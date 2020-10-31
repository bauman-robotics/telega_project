#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "counter.h"
#include <QDebug>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
#include <QFile>
#include <ctime>
#include "parser.h"

#define StartBlock()	(code_ptr = dst++, code = 1)
#define FinishBlock()	(*code_ptr = code)

int last_position = 0;
int last_speed = 0;
int flag_show_plot = 1;
//float t[18]={0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

enum State {disabled, position_control, speed_control, sinus, smooth_move, func_move, smooth_move_autonomous, path_mode};
State state = disabled;

int max_speed = 10; // Гц
int max_position = 360; // Градусов

size_t cobs_decode(const uint8_t * input, size_t length, uint8_t * output);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    portInfo(new QSerialPortInfo),
    ui(new Ui::MainWindow),
    cl1(new Counter),
    thread(new QThread),
    port_test(new QSerialPort)
{
    ui->setupUi(this);
    connect(ui->ConnectBtn, SIGNAL(clicked()), this, SLOT(openConnection()));
    encoderPosPointsArr = new QLineSeries();
//    encoderPosPointsArr->append(0, 255);
//    encoderPosPointsArr->append(2, 4);
//    encoderPosPointsArr->append(3, 8);
//    encoderPosPointsArr->append(7, 4);
//    encoderPosPointsArr->append(255, 5);

    encoderPosChart = new QChart();
    encoderPosChart->legend()->hide();
    encoderPosChart->addSeries(encoderPosPointsArr);
    encoderPosChart->createDefaultAxes();
    encoderPosChart->setTitle("Simple line chart example");
    encoderPosChart->axisY()->setRange(-185, 185); //need
    encoderPosChart->axisX()->setRange(0, 10000);

    ui->graphicsView->setChart(encoderPosChart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    QMessageBox *warn = new QMessageBox();
    warn->setIcon(QMessageBox::Warning);

    QList<QSerialPortInfo>listOfPorts = portInfo->availablePorts();

    for (const QSerialPortInfo &info : listOfPorts)
    {
        QStringList list;
        list << info.portName();
        ui->ListInfoPortsBox->addItem(list.first(), list);
    }

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    //connect(port_test, SIGNAL(readyRead()), this, SLOT(serialDataReady()));

    set_default_values();

    cl1->moveToThread(thread); // переместить в новый поток
    connect(thread, SIGNAL(started()), cl1, SLOT(CounterTimer()) , Qt::DirectConnection);  // включить счетчик
    connect(cl1, SIGNAL(sendSmooth(int) ), this, SLOT(ReceiveSmoothCount(int)) ,Qt::DirectConnection);  // плавный режим, передача инфо между потоками
    connect(this, SIGNAL(EmitSmoothStartSignal(bool)), cl1, SLOT(ReceiveSmoothStartSignal(bool) ), Qt::DirectConnection  );  // плавный режим, передача стартового сигнала между потоками
    connect(cl1, SIGNAL(sendFunc(int) ), this, SLOT(ReceiveFuncCount(int)) ,Qt::DirectConnection);  // функциональный режим, передача инфо между потоками
    connect(this, SIGNAL(EmitFuncStartSignal(bool)), cl1, SLOT(ReceiveFuncStartSignal(bool) ), Qt::DirectConnection  ); // функциональный режим, передача стартового сигнала между потоками

    connect(cl1, SIGNAL(sendVirtData(int) ), this, SLOT(GetCounter(int)) ,Qt::DirectConnection);

     thread->start() ;  // новый поток запущен

    // port_test->readyRead();

}

MainWindow::~MainWindow()
{
    delete ui;
    port_test->close();
}

double plot_count;

double d_data_buf, yMin, yMax;
uint8_t angle_to_decode[6];
uint8_t angle_decoded[6];
uint8_t data_size;
uint8_t replace;


QQueue<uint8_t> quekap;
uint8_t kapla[254];
uint8_t kap = 0;
float fbuf;
uint8_t decoded[254];
uint8_t decodedhigh = 0;
uint8_t a, c;

void MainWindow::serialDataReceived()
{
    data_buffer = port_test->readAll();
    qDebug() << "data_buffer" << data_buffer;

//    if (x==180) x=-180;
//    data_buffer[0] = 'v';
//    data_buffer[1] = x;

     data_size = data_buffer.size();
   //  replace = ];
     //qDebug() << data_buffer.size();
     uint8_t tmp_mass[254];
     for (int i = 0; i < data_buffer.size(); i++){
         quekap.enqueue((uint8_t)data_buffer[i]);
         //qDebug() << (uint8_t)data_buffer[i];
         if ((uint8_t)data_buffer[i] == 0){
             kap = 0;
             kapla[kap++] = quekap.dequeue();
             while (kapla[kap-1] != 0){
                  kapla[kap++] = quekap.dequeue();
             }
             kap--;// ноль который был в конце выкинули
         }
     }data_buffer.clear();
  //   qDebug() << "kapla";
  //   qDebug() << kapla[0];
  //   qDebug() << kapla[1];
  //   qDebug() << kapla[2];
  //   qDebug() << kapla[3];
  //   qDebug() << kapla[4];
  //   qDebug() << kapla[5];
  //   qDebug() << " ";
     if (kap != 0){
         a = 1;
         decodedhigh = 0;
         c = kapla[0];
         while (a <= kap) {
             decoded[decodedhigh++]=kapla[a++];
             if (--c == 0){
                 c = decoded[decodedhigh];
                 decoded[decodedhigh] = 0;
             }
         }
         kap = 0;
     }
     decodedhigh--;
  //   qDebug() << "kapla";
  //      qDebug() << decoded[0];
  //      qDebug() << decoded[1];
  //      qDebug() << decoded[2];
  //      qDebug() << decoded[3];
  //      qDebug() << decoded[4];
  //      qDebug() << decoded[5];
  //      qDebug() << " ";
  // теперь любой пакет зашифрованный по тому самому алгоритму расшифрован
   memcpy(&(fbuf), &decoded[0], 4);

   d_data_buf = fbuf;

  if (plot_enabled) {

      encoderPosPointsArr->append(ChartTimeCount, d_data_buf); // need

      //encoderPosPointsArr->append(plot_count, d_data_buf); // need
      //encoderPosPointsArr->append(ChartTimeCount, x); // need
          encoderPosChart->axisX()->setRange(0, ChartTimeCount); //need
      if(d_data_buf< yMin || d_data_buf > yMax){
          if(d_data_buf < yMin)
              yMin = d_data_buf;
          if(d_data_buf> yMax)
              yMax = d_data_buf;

           encoderPosChart->axisY()->setRange(yMin-1, yMax+1); //need

        }
      encoderPosChart->axisX()->setRange(0, ChartTimeCount);  //was

        //plot_count++;
   }
  else
  {
      ChartTimeCount = 0;
      qDebug() << "000";
}

  if (save_to_file_enabled)
  {
     series_vec.push_back(d_data_buf);
  }
  //x=x+10;

  //DataReady = false;

}

void MainWindow::openConnection(){

    if(not port_test->isOpen()){
        QMessageBox *warn = new QMessageBox();
        warn->setIcon(QMessageBox::Warning);

        if (ui->ListInfoPortsBox->currentText() != ""){
            port_test->setPortName(ui->ListInfoPortsBox->currentText());
        } else {
            warn->setText("Нет доступных портов");
            warn->show();
        }

        port_test->setBaudRate(QSerialPort::Baud115200);
        port_test->setDataBits(QSerialPort::Data8);
        port_test->setParity(QSerialPort::NoParity);
        port_test->setStopBits(QSerialPort::OneStop);
        port_test->setFlowControl(QSerialPort::NoFlowControl);
        port_test->open(QIODevice::ReadWrite);

        if (port_test->isOpen()){
            ui->ConnectBtn->setText("Connected");
            ui->ConnectBtn->update();
            //warn->setText("Cоединение установлено");
            //warn->show();
        }else {
            warn->setText("Не удалось установить соединение, возможно порт занят другим процессом");
            warn->show();
        }
    }
    else{
        port_test->close();
        qDebug() << port_test->isOpen();
        ui->ConnectBtn->setText("Disconnected");
        ui->ConnectBtn->update();
    }
}

void MainWindow::serial_port_init()
{

    port_test = new QSerialPort();
    port_test->setPortName("com4");

    port_test->open(QIODevice::ReadWrite);
    port_test->setBaudRate(QSerialPort::Baud115200);
    port_test->setDataBits(QSerialPort::Data8);
    port_test->setParity(QSerialPort::NoParity);
    port_test->setStopBits(QSerialPort::OneStop);
    port_test->setFlowControl(QSerialPort::NoFlowControl);
    // connect(port_test, SIGNAL(readyRead()), this, SLOT(serial_recieved()));
}

void MainWindow::set_default_values()
{
    ui->radioButton_disabled_mode->click();
}

void MainWindow::on_radioButton_disabled_mode_clicked()
{

    state = disabled;
    QByteArray data_to_send;
    data_to_send[0] = 'a';
    data_to_send[1] = 0x00;
    data_to_send[2] = 0x00;
    data_to_send[3] = 0x00;
    data_to_send[4] = 0x00;
    StopNow('v', 0);
    port_test->write(data_to_send);
    ui->horizontalSlider->setDisabled(true);
    ui->spinBox_des_val->setDisabled(true);
    ui->spinBox_des_val_2->setDisabled(true);
    ui->sin_button_widget->setDisabled(true);
}

void MainWindow::on_radioButton_static_mode_clicked()
{
    state = position_control;
    last_speed = ui->horizontalSlider->value();
    // ui->horizontalSlider->setEnabled(true);
    ui->spinBox_des_val->setEnabled(true);
    ui->spinBox_des_val_2->setEnabled(true);
    ui->sin_button_widget->setDisabled(true);
    ui->horizontalSlider->setRange(-max_position*10000,max_position*10000);
    ui->horizontalSlider->setPageStep(ceil(ceil((double)(max_position*10000)/20)));
    ui->horizontalSlider->setValue(last_position);
    ui->horizontalSlider->update();
    ui->spinBox_des_val->setRange((double)(-max_position),(double)(max_position));
    ui->spinBox_des_val_2->setRange((double)(-max_position),(double)(max_position));

}

void MainWindow::on_radioButton_sine_mode_clicked()
{
    state = sinus;

    ui->horizontalSlider->setDisabled(true);
    ui->spinBox_des_val->setDisabled(true);
    ui->spinBox_des_val_2->setDisabled(true);
    ui->sin_button_widget->setEnabled(true);
}

void MainWindow::on_radioButton_speed_mode_clicked()
{
    state = speed_control;
    last_position = ui->horizontalSlider->value();
    // ui->horizontalSlider->setEnabled(true);
    ui->spinBox_des_val->setEnabled(true);
    ui->spinBox_des_val_2->setEnabled(true);
    ui->sin_button_widget->setDisabled(true);
    ui->horizontalSlider->setRange(-max_speed*10000, max_speed*10000);
    ui->horizontalSlider->setPageStep(ceil(ceil((double)(max_speed*10000)/20)));
    ui->horizontalSlider->setValue(last_speed);
    ui->horizontalSlider->update();
    ui->spinBox_des_val->setRange((double)(-max_speed), (double)(max_speed));
    ui->spinBox_des_val_2->setRange((double)(-max_speed), (double)(max_speed));
}

void MainWindow::on_pushButton_Set_angle_clicked()
{
    char command_code = 0;
    float data = ui->spinBox_des_val->value();
    QString StringVar;
    float DataTmp;
    float DataDesiredVelocity;

    ui->horizontalSlider->setValue((int)(data*10000));      //да да, это делается через signal

    switch (state) {
    case position_control:
        command_code = 'p';
        break;
    case speed_control:
        command_code = 'v';
        break;
    case disabled:
        command_code = 'a';
        break;
    case smooth_move:           // плавный режим, старт-сигнал

        command_code = 'v';
        SmoothStartSignal = true;
        FuncStartSignal = false;
        SmoothAutonomousEnabled = false;
        PathModeEnabled = false;
        emit EmitSmoothStartSignal(SmoothStartSignal);
        emit EmitFuncStartSignal(FuncStartSignal);
        qDebug() << "EmitSmoothStartSignalTRUE";
         break;

    case smooth_move_autonomous:

        SmoothStartSignal = false;
        FuncStartSignal = false;
        SmoothAutonomousEnabled = true;
        PathModeEnabled = false;
        emit EmitSmoothStartSignal(SmoothStartSignal);
        emit EmitFuncStartSignal(FuncStartSignal);
        qDebug() << "Autonomous Smooth Start true";

         StringVar = ui->Write_Desired_Time->toPlainText();
         DataTmp  = StringVar.toFloat();
         StringVar = ui->Write_Desired_Velocity->toPlainText();

         DataDesiredVelocity  = StringVar.toFloat();
         if (DataDesiredVelocity > 1 || DataDesiredVelocity < -1)
         Warner ("Слишком высокая скорость");
         else
         SendForSmoothMove('g', DataTmp, DataDesiredVelocity);
        command_code = 'g';
        break;

    case func_move:    // функциональный режим, старт-сигнал

        FuncStartSignal = true;
        SmoothStartSignal = false;
        SmoothAutonomousEnabled = false;
        PathModeEnabled = false;
        emit EmitFuncStartSignal(FuncStartSignal);
        emit EmitSmoothStartSignal(SmoothStartSignal);
        qDebug() << "EmitFuncStartSignalTRUE";
        command_code = 'p';
        break;

    case path_mode:

        command_code = 'v';
        SmoothStartSignal = false;
        FuncStartSignal = false;
        SmoothAutonomousEnabled = false;
        PathModeEnabled = true;
        emit EmitSmoothStartSignal(SmoothStartSignal);
        emit EmitFuncStartSignal(FuncStartSignal);

        StringVar = ui->Write_Linear_vel->toPlainText();
        L_vel  = StringVar.toFloat();

        if (L_vel > 1.2 || L_vel < -1.2)
            Warner ("Слишком высокая скорость");
        else SendBytesFloat('L', L_vel);               // отсылаем линейную скорость платформы

        StringVar = ui->Write_Angular_vel->toPlainText();
        W_vel  = StringVar.toFloat();
        if (W_vel > 1.2 || W_vel < -1.2)
            Warner ("Слишком высокая скорость");
        else  SendBytesFloat('W', W_vel);              // отсылаем угловую скорость платформы
        break;
    default:
        command_code = 'e';
        qDebug() << "error";
        break;
    }



    if (MainWindow::SmoothAutonomousEnabled == false && MainWindow::FuncModeEnabled == false && MainWindow::SmoothModeEnabled == false && MainWindow::PathModeEnabled == false)
    {
        SmoothStartSignal = false;
        FuncStartSignal = false;
        SmoothAutonomousEnabled = false;
        PathModeEnabled = false;
        emit EmitSmoothStartSignal(SmoothStartSignal);
        emit EmitFuncStartSignal(FuncStartSignal);
        qDebug() << "EmitStartSignalFALSE";
        qDebug() << "EmitFuncSignalFALSE";

    SendBytesFloat(command_code, data);
    qDebug() << "data_norm" << data;
    }
}

void MainWindow::on_pushButton_Set_angle_2_clicked()
{
    char command_code = 0;
    float data = ui->spinBox_des_val_2->value();
    QString StringVar;
    float DataTmp;
    float DataDesiredVelocity;

    ui->horizontalSlider->setValue((int)(data*10000));      //да да, это делается через signal

    switch (state) {
    case position_control:
        command_code = 'p';
        break;
    case speed_control:
        command_code = 'v';
        break;
    case disabled:
        command_code = 'a';
        break;
    case smooth_move:           // плавный режим, старт-сигнал

        command_code = 'v';
        SmoothStartSignal = true;
        FuncStartSignal = false;
        SmoothAutonomousEnabled = false;
        PathModeEnabled = false;
        emit EmitSmoothStartSignal(SmoothStartSignal);
        emit EmitFuncStartSignal(FuncStartSignal);
        qDebug() << "EmitSmoothStartSignalTRUE";
         break;

    case smooth_move_autonomous:

        SmoothStartSignal = false;
        FuncStartSignal = false;
        SmoothAutonomousEnabled = true;
        PathModeEnabled = false;
        emit EmitSmoothStartSignal(SmoothStartSignal);
        emit EmitFuncStartSignal(FuncStartSignal);
        qDebug() << "Autonomous Smooth Start true";

         StringVar = ui->Write_Desired_Time->toPlainText();
         DataTmp  = StringVar.toFloat();
         StringVar = ui->Write_Desired_Velocity->toPlainText();

         DataDesiredVelocity  = StringVar.toFloat();
         if (DataDesiredVelocity > 1 || DataDesiredVelocity < -1)
         Warner ("Слишком высокая скорость");
         else
         SendForSmoothMove('g', DataTmp, DataDesiredVelocity);
        command_code = 'g';
        break;

    case func_move:    // функциональный режим, старт-сигнал

        FuncStartSignal = true;
        SmoothStartSignal = false;
        SmoothAutonomousEnabled = false;
        PathModeEnabled = false;
        emit EmitFuncStartSignal(FuncStartSignal);
        emit EmitSmoothStartSignal(SmoothStartSignal);
        qDebug() << "EmitFuncStartSignalTRUE";
        command_code = 'p';
        break;

    case path_mode:

        command_code = 'v';
        SmoothStartSignal = false;
        FuncStartSignal = false;
        SmoothAutonomousEnabled = false;
        PathModeEnabled = true;
        emit EmitSmoothStartSignal(SmoothStartSignal);
        emit EmitFuncStartSignal(FuncStartSignal);

        StringVar = ui->Write_Linear_vel->toPlainText();
        L_vel  = StringVar.toFloat();

        if (L_vel > 1.2 || L_vel < -1.2)
            Warner ("Слишком высокая скорость");
        else SendBytesFloat('L', L_vel);               // отсылаем линейную скорость платформы

        StringVar = ui->Write_Angular_vel->toPlainText();
        W_vel  = StringVar.toFloat();
        if (W_vel > 1.2 || W_vel < -1.2)
            Warner ("Слишком высокая скорость");
        else  SendBytesFloat('W', W_vel);              // отсылаем угловую скорость платформы
        break;
    default:
        command_code = 'e';
        qDebug() << "error";
        break;
    }



    if (MainWindow::SmoothAutonomousEnabled == false && MainWindow::FuncModeEnabled == false && MainWindow::SmoothModeEnabled == false && MainWindow::PathModeEnabled == false)
    {
        SmoothStartSignal = false;
        FuncStartSignal = false;
        SmoothAutonomousEnabled = false;
        PathModeEnabled = false;
        emit EmitSmoothStartSignal(SmoothStartSignal);
        emit EmitFuncStartSignal(FuncStartSignal);
        qDebug() << "EmitStartSignalFALSE";
        qDebug() << "EmitFuncSignalFALSE";

    SendBytesFloat(command_code, data);
    qDebug() << "data_norm" << data;
    }
}


void MainWindow::on_radioButton_SmoothMode_clicked()
{
    state = smooth_move;
    SmoothStartSignal = true;
    FuncStartSignal = false;
    SmoothAutonomousEnabled = false;
    PathModeEnabled = false;
    emit EmitSmoothStartSignal(SmoothStartSignal);
    qDebug() << "EmitSmoothStartSignalTRUE";
}

void MainWindow::on_radioButton_TrajectoryMode_clicked()
{
    state = func_move;
    FuncStartSignal = true;
    SmoothStartSignal = false;
    SmoothAutonomousEnabled = false;
    PathModeEnabled = false;
    emit EmitFuncStartSignal(FuncStartSignal);
    qDebug() << "EmitFuncStartSignalTRUE";
}


void MainWindow::on_SmoothModeEnabled_clicked()
{
    state = smooth_move;
     MainWindow::SmoothModeEnabled = true;
     MainWindow::FuncModeEnabled = false;
     ui->SmoothModeDisabled->setEnabled(true);
     ui->SmoothModeEnabled->setDisabled(true);
}

void MainWindow::on_SmoothModeDisabled_clicked()
{
    state = disabled;
    MainWindow::SmoothModeEnabled = false;
    ui->SmoothModeEnabled->setEnabled(true);
    ui->SmoothModeDisabled->setDisabled(true);

}

void MainWindow::on_FuncModeEnabled_clicked()
{
    state = func_move;
    MainWindow::FuncModeEnabled = true;
    MainWindow::SmoothModeEnabled = false;
    ui->FuncModeDisabled->setEnabled(true);
    ui->FuncModeEnabled->setDisabled(true);

}

void MainWindow::on_FuncModeDisabled_clicked()
{
    state = disabled;
     MainWindow::FuncModeEnabled = false;
     ui->FuncModeEnabled->setEnabled(true);
     ui->FuncModeDisabled->setDisabled(true);

}

void MainWindow::on_SmoothAutonomousEnabled_clicked()
{
    state = smooth_move_autonomous;
    SmoothAutonomousEnabled = true;
    ui->SmoothAutonomousDisabled->setEnabled(true);
    ui->SmoothAutonomousEnabled->setDisabled(true);
}


void MainWindow::on_SmoothAutonomousDisabled_clicked()
{
    state = disabled;
    SmoothAutonomousEnabled = false;
    ui->SmoothAutonomousEnabled->setEnabled(true);
    ui->SmoothAutonomousDisabled->setDisabled(true);
}


void MainWindow::on_Set_Linear_vel_clicked()
{
    QString StringVar = ui->Write_Linear_vel->toPlainText();
    L_vel  = StringVar.toFloat();
    if (L_vel > 1.2 || L_vel < -1.2)
        Warner ("Слишком высокая скорость");
}

void MainWindow::on_Set_Angular_vel_clicked()
{
    QString StringVar = ui->Write_Angular_vel->toPlainText();
    W_vel  = StringVar.toFloat();
    if (W_vel > 1.2 || W_vel < -1.2)
        Warner ("Слишком высокая скорость");
}

void MainWindow::on_PathModeEnabled_clicked()
{
    state = path_mode;
    PathModeEnabled = true;
    ui->PathModeEnabled->setDisabled(true);
    ui->PathModeDisabled->setEnabled(true);
}

void MainWindow::on_PathModeDisabled_clicked()
{
    state = disabled;
    PathModeEnabled = false;
    ui->PathModeEnabled->setEnabled(true);
    ui->PathModeDisabled->setDisabled(true);
}

void MainWindow::on_radioButton_SmoothMode_Autonomous_clicked()
{
    state = smooth_move_autonomous;
    char command_code = 0;
    float data = ui->spinBox_des_val->value();
    QString StringVar;
    float DataTime;
    float DataDesiredVelocity;

    SmoothStartSignal = false;
    FuncStartSignal = false;
    SmoothAutonomousEnabled = true;
    PathModeEnabled = false;
    qDebug() << "Autonomous Smooth Start true";

     StringVar = ui->Write_Desired_Time->toPlainText();
     DataTime  = StringVar.toFloat();
     //StringVar = ui->Write_Desired_Velocity->toPlainText();

     DataDesiredVelocity  = StringVar.toFloat();
     if (DataDesiredVelocity > 1.2 || DataDesiredVelocity < -1.2)
     Warner ("Слишком высокая скорость");
//     else
//     SendForSmoothMove('g', DataTime, DataDesiredVelocity);
}

void MainWindow::on_radioButton_path_mode_Autonomous_clicked()
{
    state = path_mode;
    SmoothStartSignal = false;
    FuncStartSignal = false;
    SmoothAutonomousEnabled = false;
    PathModeEnabled = true;
}

void MainWindow::on_radioButton_TrajectoryMode_Autonomous_clicked()
{
    //// загрузка промежутков времени функций в массив
    //    QString StringTime[18] = {ui->WriteTime_3->toPlainText(), ui->WriteTime_4->toPlainText(), ui->WriteTime_5->toPlainText(), ui->WriteTime_12->toPlainText(),
    //                             ui->WriteTime_13->toPlainText(), ui->WriteTime_14->toPlainText(), ui->WriteTime_6->toPlainText(), ui->WriteTime_15->toPlainText(),
    //                             ui->WriteTime_7->toPlainText(), ui->WriteTime_16->toPlainText(), ui->WriteTime_8->toPlainText(), ui->WriteTime_17->toPlainText(),
    //                             ui->WriteTime_9->toPlainText(), ui->WriteTime_18->toPlainText(), ui->WriteTime_10->toPlainText(), ui->WriteTime_19->toPlainText(),
    //                             ui->WriteTime_11->toPlainText(), ui->WriteTime_20->toPlainText()};
    //    // загрузка функций в массив
    //    QString StringFunc[9] = {ui->WriteFunc->toPlainText(), ui->WriteFunc_2->toPlainText(), ui->WriteFunc_3->toPlainText(), ui->WriteFunc_5->toPlainText(),
    //                             ui->WriteFunc_6->toPlainText(), ui->WriteFunc_7->toPlainText(), ui->WriteFunc_8->toPlainText(), ui->WriteFunc_9->toPlainText(),
    //                             ui->WriteFunc_4->toPlainText()};
    //// проверки корректности при включении режима
    //    for (int j=0; j<9; j++)
    //{
    //        t[2*j]=StringTime[2*j].toFloat();
    //        t[2*j+1]=StringTime[2*j+1].toFloat();

    //        if (j!=0 && (t[2*j]==0 || t[2*j+1]==0) )
    //        {
    //        Warner ("Некорректное время");
    //        }
    //        /*else*/ if(j!=0 && t[2*j]>=t[2*j+1])
    //        {
    //            t[2*j]=0;
    //            t[2*j+1]=0;
    //             Warner ("Конечное время меньше начального");
    //        }

    //        else if(j==0 && t[1]<=t[0] && t[1]!=0 )
    //        {
    //            t[2*j]=0;
    //            t[2*j+1]=0;
    //            Warner ("Конечное время t1 меньше начального t0");
    //        }

    //    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
//    char command_code = '\0';
//    float data = (float)(value);
//    ui->spinBox_des_val->setValue(((double)data)/10000);
//    switch (state) {
//    case position_control:
//        command_code = 'p';
//        break;
//    case speed_control:
//        command_code = 'v';
//        break;
//    default:
//        qDebug() << "error";
//        break;
//    }
//    SendBytesFloat(command_code, data/10000);
}

void MainWindow::on_pushButton_2_clicked()
{                                                   // калибровка энкодера
    char command_code = 'b';
    SendByte(command_code);
}
//запись ПИД-коэффициентов
void MainWindow::on_write_Kp_clicked()
{
    QString raw_string_val = ui->Ki_text->toPlainText();
    float data  = raw_string_val.toFloat();
    char command_code = '1';
    SendBytesFloat(command_code, data);
}

void MainWindow::on_write_Ki_clicked()
{
    QString raw_string_val = ui->Ki_text->toPlainText();
    float data  = raw_string_val.toFloat();
    char command_code = '2';
    SendBytesFloat(command_code, data);
}

void MainWindow::on_write_Kd_clicked()
{
    QString raw_string_val = ui->Ki_text->toPlainText();
    float data  = raw_string_val.toFloat();
    char command_code = '3';
    SendBytesFloat(command_code, data);
}

void MainWindow::on_spinBox_des_val_valueChanged(double arg1)
{
    ui->horizontalSlider->setValue((int)(arg1*10000));
}

void MainWindow::on_button_sin_3_clicked()
{
    char command_code = 's';
    float data = 3.0;
    SendBytesFloat(command_code, data);
}

void MainWindow::on_button_sin_2_clicked()
{
    char command_code = 's';
    float data = 2.0;
    SendBytesFloat(command_code, data);
}

void MainWindow::on_button_sin_1_clicked()
{
    char command_code = 's';
    float data = 1.0;
    SendBytesFloat(command_code, data);
}

void MainWindow::on_button_sin_05_clicked()
{
    char command_code = 's';
    float data = 0.5;
    SendBytesFloat(command_code, data);
}

void MainWindow::on_button_sin_025_clicked()
{
    char command_code = 's';
    float data = 0.25;
    SendBytesFloat(command_code, data);
}



void MainWindow::SendBytesFloat(char command_code, float data)
{   // как-то можно было делать функцию с одним названием, но разной реализацией для разных типов
                                                                    //отправка команды "код команды + число"
    qDebug() << state;
    uint8_t data_to_send[5] = {};
    data_to_send[0] = command_code;           // стартовый бит
    memcpy(data_to_send+1, &data, 4);
    qDebug() << "data_to_send: ";
    for(int i =0; i<5; i++)
        qDebug() << i << ":  '" << data_to_send[i] << "'";
    uint8_t data_to_send_encoded[7] = {};
    uint8_t size = encode(data_to_send, 5, data_to_send_encoded);
    qDebug() << "data_to_send_encoded: ";
    for(int i =0; i<7; i++)
        qDebug() << i << ":  '" << data_to_send_encoded[i] << "'";
    qDebug() << "end of data_to_send_encoded";
    qDebug() << "size_encoded: " << size;
    qDebug() << " ";
    char data_to_send_encoded_char[7] = {};
    memcpy(data_to_send_encoded_char, data_to_send_encoded, 7);
    port_test->write(data_to_send_encoded_char, (qint64)size+1);
    if(port_test->waitForBytesWritten(10) == false)
        qDebug() << "error sending";
}

void MainWindow::SendByte(char command_code)
{   // как-то можно было делать функцию с одним названием, но разной реализацией для разных типов
                                                                    //отправка команды "код команды"
    char data_to_send[2] = {};
    data_to_send[0] = command_code;
    data_to_send[1] = 0;
    qDebug() << data_to_send;
    port_test->write(data_to_send, 2);
    if(port_test->waitForBytesWritten(10) == false)
        qDebug() << "error sending";
}

void MainWindow::SendForSmoothMove(char command_code, float time, float vel)    // чтобы запихнуть float время и скорость в 5 байтов, они переводятся в int умножением на 100. В МК для получения снова float нужно разделить!
{   // как-то можно было делать функцию с одним названием, но разной реализацией для разных типов
    uint16_t data_time, data_vel;                                                                //отправка команды "код команды + число"
    qDebug() << state;
    uint8_t data_to_send[5] = {};
    data_to_send[0] = command_code;           // стартовый бит
    data_time = 100*time;
    data_vel = 100*vel;
    memcpy(data_to_send+1, &data_time, 2);
    memcpy(data_to_send+3, &data_vel, 2);

    qDebug() << "data_to_send: ";
    for(int i =0; i<5; i++)
        qDebug() << i << ":  '" << data_to_send[i] << "'";
    uint8_t data_to_send_encoded[7] = {};
    uint8_t size = encode(data_to_send, 5, data_to_send_encoded);
    qDebug() << "data_to_send_encoded: ";
    for(int i =0; i<7; i++)
        qDebug() << i << ":  '" << data_to_send_encoded[i] << "'";
    qDebug() << "end of data_to_send_encoded";
    qDebug() << "size_encoded: " << size;
    qDebug() << " ";
    char data_to_send_encoded_char[7] = {};
    memcpy(data_to_send_encoded_char, data_to_send_encoded, 7);
    port_test->write(data_to_send_encoded_char, (qint64)size+1);
    if(port_test->waitForBytesWritten(10) == false)
        qDebug() << "error sending";
}


size_t encode(const uint8_t *ptr, size_t length, uint8_t *dst)
{    /*
     * StuffData byte stuffs "length" bytes of data
     * at the location pointed to by "ptr", writing
     * the output to the location pointed to by "dst".
     *
     * Returns the length of the encoded data.
     */
    const uint8_t *start = dst, *end = ptr + length;
    uint8_t code = 0, *code_ptr = nullptr; /* Where to insert the leading count */

    StartBlock();
    while (ptr < end)
    {
        if (code != 0xFF)
        {
            uint8_t c = *ptr++;
            if (c != 0)
            {
                *dst++ = c;
                code++;
                continue;
            }
        }
        FinishBlock();
        StartBlock();
    }
    FinishBlock();
    return (size_t)(dst - start);
}

/* Unstuffs "length" bytes of data at the location pointed to by
 * "input", writing the output * to the location pointed to by
 * "output". Returns the number of bytes written to "output" if
 * "input" was successfully unstuffed, and 0 if there was an
 * error unstuffing "input".
 */

size_t cobs_decode(const uint8_t * input, size_t length, uint8_t * output)
{
    size_t read_index = 0;
    size_t write_index = 0;
    uint8_t code;
    uint8_t i;

    while(read_index < length)
    {
        code = input[read_index];

        if(read_index + code > length && code != 1)
        {
            return 0;
        }

        read_index++;

        for(i = 1; i < code; i++)
        {
            output[write_index++] = input[read_index++];
        }
        if(code != 0xFF && read_index != length)
        {
            output[write_index++] = '\0';
        }
    }

    return write_index;
}

void MainWindow::on_pushButtonResetPlot_clicked()
{
    encoderPosPointsArr->clear();
    yMin = yMax = d_data_buf;

    ChartTimeCount = 0;

    //plot_count = 0;
    //encoderPosChart->axisY()->setRange(yMin-1, yMax+1); //need
    //encoderPosChart->axisX()->setRange(0, plot_count);   //need
}

bool UploadToCsv(const QChart * chart,const QString filename);

void MainWindow::on_savePlotToFile_clicked()
{
    plot_enabled = false;
    save_to_file_enabled = false;
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Address Book"), "",
        tr("Address Book (*.csv);;All Files (*)"));

    // comment begin
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly
                  |QIODevice::Truncate
                  |QIODevice::Text))
    {
        // QDataStream out(&file);
        file.write("x;y;\n");
        for(int i=0; i < series_vec.count(); ++i) {
            // out << QString::number( series_vec[i] ).toLocal8Bit() << ";";
            QByteArray ba;
            ba = QString::number( i ).toLatin1();
            ba += ";";
            ba += QString::number( series_vec[i] ).toLatin1();
            ba += ";\n";
            file.write(ba);
        }
        // out << series_vec;
        file.close();
    } // comment end

    // UploadToCsv(encoderPosChart,fileName); // need. original
    ui->pushButtonResetPlot->setDisabled(false);
}


bool UploadToCsv(
        const QChart * chart,
        const QString filename)
{
    QFile csvfile(filename);
    if(chart->series().count()==0)
        return false;
    if (!csvfile.open(QIODevice::WriteOnly
                 |QIODevice::Truncate
                 |QIODevice::Text))
        return false;
    for (int i = 0; i < chart->series().count(); ++i)
    {
        QLineSeries * ls;
        ls = static_cast<QLineSeries *>(chart->series().at(i));
        csvfile.write(QByteArray("series")
                      + QString::number(i).toLatin1()
                      + QByteArray("\n"));
        csvfile.write("x;y;\n");
        for (int j=0; j < ls->count();++j)
        {
            QByteArray ba;
            ba = QString::number(ls->at(j).x(),'i',0).toLatin1();
            ba += ";";
            ba += QString::number(ls->at(j).y(),'f',2).toLatin1();
            ba += ";\n";
            csvfile.write(ba);
        }
    }
    csvfile.close();
    qDebug() << "Write successfull";
    return true;
}

void MainWindow::on_pushButtonStartSaveToFile_clicked()
{
    // encoderPosPointsArr->clear();
    //flag_show_plot = 0;
    //yMin = yMax = 0;
    //ui->pushButtonResetPlot->setDisabled(true);
    save_to_file_enabled = true;
    series_vec.clear();
    //plot_enabled = false;
}

void MainWindow::on_plot_graphic_stateChanged(int enabled)
{
    if (enabled == false){
        plot_enabled = false;
        encoderPosPointsArr->clear();
        //ui->pushButtonStartSaveToFile->setDisabled(true);
        ui->pushButtonResetPlot->setDisabled(true);
    }
    else{
        ui->pushButtonStartSaveToFile->setEnabled(true);
        ui->pushButtonResetPlot->setEnabled(true);
        plot_enabled = true;
    }
}

void MainWindow::on_spinBox_des_val_2_valueChanged(double arg1)
{
    ui->horizontalSlider->setValue((int)(arg1*10000));
}

void MainWindow::on_spinBox_des_val_2_editingFinished()
{

}

void MainWindow::ReceiveSmoothCount(int GetCount)
{
    //qDebug() << "on sending";

    char command_code = 0;
    double data = ui->spinBox_des_val->value();
                     switch (state) {
                     case position_control:
                         command_code = 'p';
                         break;
                     case speed_control:
                         command_code = 'v';
                         break;
                     case smooth_move:       // go with gentle changing velocity
                         command_code = 'g';
                         break;
                     default:
                         command_code = 'e';
                         qDebug() << "error";
                         break;
                     }
                     /*Получает текущее значение у счетчика
                      * Смотрит время ускорения/замедления
                      * Считывает время работы на полной скорости
                      * Подает нарастающий сигнал ускорения
                      * Подает заданный сигнал
                      * Подает падающий сигнал замедления
                      * Останавливается
                      */
    CountTime = GetCount;
    double RollTime = StdRollTime;
     StringTime = ui->WriteTime->toPlainText();
     RollTime  = StringTime.toDouble();

     if (counter < 2*AccellTime+RollTime)
     {
          if ( counter < AccellTime)
          {
               data = 0.1*data*counter;
               qDebug() << "data_accel" << data;
              SendBytesFloat(command_code, data);
              ui->horizontalSlider->setValue((int)(data*10000));
              qDebug() << "counter" << counter;
           }

           else if ( (counter >= AccellTime)&&(counter<= 2*AccellTime+RollTime - AccellTime) )
                 {
                 qDebug() << endl << "counter" << counter;

                 data = ui->spinBox_des_val->value();
                 SendBytesFloat(command_code, data);
                  qDebug() << "data_run" << data << endl;
                    }
                  else if ( (counter <= 2*AccellTime+RollTime)&&(counter >= 2*AccellTime+RollTime - AccellTime) )
                  {
                      data = ui->spinBox_des_val->value();
                      data = 0.1*data*(2*AccellTime+RollTime-counter);
                     SendBytesFloat(command_code, data);
                     ui->horizontalSlider->setValue((int)(data*10000));
                     qDebug() << "data_stop" << data;
                     qDebug() << "counter" << counter;
                  }
          else {StopNow(data, command_code);}
            }
     else {StopNow(data, command_code);}
     counter++;
}

void MainWindow::ReceiveFuncCount(int GetCount)
{
    qDebug() << "on sending";

    char command_code = 0;
    const char *p;

    switch (state) {
    case position_control:
        command_code = 'p';
        break;
    case speed_control:
        command_code = 'v';
        break;
    case smooth_move:       // go with gentle changing velocity
        command_code = 'g';
        break;
    default:
        command_code = 'e';
        qDebug() << "error";
        break;
    }

    CountTime = GetCount;

    // загрузка промежутков времени функций в массив

    QString StringTime[18] = {ui->WriteTime_3->toPlainText(), ui->WriteTime_4->toPlainText(), ui->WriteTime_5->toPlainText(), ui->WriteTime_12->toPlainText(),
                             ui->WriteTime_13->toPlainText(), ui->WriteTime_14->toPlainText(), ui->WriteTime_6->toPlainText(), ui->WriteTime_15->toPlainText(),
                             ui->WriteTime_7->toPlainText(), ui->WriteTime_16->toPlainText(), ui->WriteTime_8->toPlainText(), ui->WriteTime_17->toPlainText(),
                             ui->WriteTime_9->toPlainText(), ui->WriteTime_18->toPlainText(), ui->WriteTime_10->toPlainText(), ui->WriteTime_19->toPlainText(),
                             ui->WriteTime_11->toPlainText(), ui->WriteTime_20->toPlainText()};
    // загрузка функций в массив
    QString StringFunc[9] = {ui->WriteFunc->toPlainText(), ui->WriteFunc_2->toPlainText(), ui->WriteFunc_3->toPlainText(), ui->WriteFunc_5->toPlainText(),
                             ui->WriteFunc_6->toPlainText(), ui->WriteFunc_7->toPlainText(), ui->WriteFunc_8->toPlainText(), ui->WriteFunc_9->toPlainText(),
                             ui->WriteFunc_4->toPlainText()};
    // проверки корректности при выполнении, окна не выводятся, для t1=0 -> основная функция выполняется бесконечно, для t2...t8=0 / t(i)>t(i+1) -> некорректны, не выполняются
    // основная функция выполняется в промежутке (t0;t1) в периоде, с перерывами на дополнительные функции
     for (int j=0; j<9; j++)
{
         t[2*j]=StringTime[2*j].toFloat();
         t[2*j+1]=StringTime[2*j+1].toFloat();
         qDebug() << "j= " << j << ",t[2j]= " << t[2*j];


         if (j!=0 && (t[2*j]==0 || t[2*j+1]==0) )
         {
         t[2*j]=0;
         t[2*j+1]=0;
         //qDebug() << "Некорректное время " << 2*j;
         //Warner ("Некорректное время t1");
         }
         else if(j!=0 && t[2*j]>=t[2*j+1])
         {
             t[2*j]=0;
             t[2*j+1]=0;
//             Warner ("Конечное время t1 меньше начального t0");
             //qDebug() << "Конечное время " << 2*j << " меньше начального " << 2*j-1 ;
         }
         else if(j==0 && t[1]==0 )
         {
             //t[2*j]=-1;
            // t[2*j+1]=-1;
            // qDebug() << "t1 бесконечно";
         }
         else if(j==0 && t[1]<=t[0] && t[1]!=0 )
         {
             t[2*j]=0;
             t[2*j+1]=0;
             //qDebug() << "Конечное время t1 меньше начального t0";
         }

             if (j!=0 && t[2*j]!=0 && t[2*j+1]!=0 && counter>=t[2*j] && counter<=t[2*j+1]) {
                 std::string d = StringFunc[j].toStdString();

                p=d.data();
                //qDebug() << "string" << p;
                Parser parser(p);    //Подключает разборщик ввода
               // auto result = eval(parser.parse());
                double data = Calculator(p, counter);  // Разбирает и высчитывает результат ввода
                SendBytesFloat(command_code, data);
                ui->horizontalSlider->setValue((int)(data*10000));
                qDebug() << "data" << data;
                if (FuncModeEnabled==false) {StopNow(data, command_code);}
                break;
             }
             else if (j==8 && t[1]==0 ) {
                 std::string d = StringFunc[0].toStdString();
                p=d.data();
               // qDebug() << "string" << p;
                Parser parser(p);    //Подключает разборщик ввода
               // auto result = eval(parser.parse());
                double data = Calculator(p, counter);  // Разбирает и высчитывает результат ввода
                SendBytesFloat(command_code, data);
                ui->horizontalSlider->setValue((int)(data*10000));
                qDebug() << "data" << data;
                if (FuncModeEnabled==false) {StopNow(data, command_code);}
                break;
             }

             else if (j==8 && t[1]!=0 && counter>=t[0] && counter<=t[1]) {
                 std::string d = StringFunc[0].toStdString();
                p=d.data();
              //  qDebug() << "string" << p;
                Parser parser(p);    //Подключает разборщик ввода
               // auto result = eval(parser.parse());
                double data = Calculator(p, counter);  // Разбирает и высчитывает результат ввода
                SendBytesFloat(command_code, data);
                ui->horizontalSlider->setValue((int)(data*10000));
                qDebug() << "data" << data;
                if (FuncModeEnabled==false) {StopNow(data, command_code);}
                break;
             }

              else if (j==8 && t[1]!=0 && counter>=t[0] && counter>=t[1])
                 counter=-1;
         }

counter++;

}


void MainWindow::Warner(QString s)
{
    warn->setText(s);
    warn->show();
}

//Стоп
void MainWindow::StopNow(float f_data, char f_command_code)
{
    f_data = 0;
    counter=-1;
    SendBytesFloat('a', 0);
    SmoothStartSignal=false;
    emit EmitSmoothStartSignal(SmoothStartSignal);
    FuncStartSignal=false;
    emit EmitFuncStartSignal(FuncStartSignal);
    SmoothAutonomousEnabled = false;
    SmoothAutonomousStartSignal = false;
}

void MainWindow::GetCounter(int counter)
{
    //
    ChartTimeCount+=0.1;
    //port_test->readyRead();
   // qDebug() << "GetCounter";
    //if ( DataReady == true ){
      //  qDebug() << "ready";
    serialDataReceived();
//}
    //return *ui;
}

void MainWindow::serialDataReady()
{

    //qDebug() << "GetReady";
    //DataReady = true;

    //return *ui;
}

void MainWindow::on_TestButton_clicked()
{
//            test("0", 0);
//            test("1", 1);
//            test("9", 9);
//            test("10", 10);
//            test("+1", 1);
//            test("-1", -1);
//            test("(1)", 1);
//            test("(-1)", -1);
//            test("abs(-1)", 1);
//            test("1+20", 21);
//            test("1 + 20", 21);
//            test("1+20+300", 321);
//            test("1+20+300+4000", 4321);
//        test("-1+20", 19);
//        test("--1+20", 21);
//        test("---1+20", 19);
//            test("(1+20)", 21);
//            test("-2*3", -6);
//            test("2*-3", -6);
//            test("1++2", 3);
//            test("1+10*2", 21);
//            test("10*2+1", 21);
//            test("(1+20)*2", 42);
//            test("2*(1+20)", 42);
//            test("(1+2)*(3+4)", 21);
//            test("2*3+4*5", 26);
//            test("100+2*10+3", 123);
//            test("2**3", 8);
//            test("2**3*5+2", 42);
//            test("5*2**3+2", 42);
//            test("2+5*2**3", 42);
//            test("1+2**3*10", 81);
//            test("2^3", 8);
//            test("2*abs(3)+sin(3.14)", 26);
//            test("cos(0+3.14/2)+sin(3.14/2+0*28)", 1);
//            test("2**3+2*10", 28);
//            test("5 * 4 + 3 * 2 + 1", 27);
//            std::cout << "Done with " << errors << " errors.\n";
}

