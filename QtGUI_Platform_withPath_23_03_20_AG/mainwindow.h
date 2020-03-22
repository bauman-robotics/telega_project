#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QThread>
#include <QString>
#include <QSerialPort>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include "visual_data.h"
#include <QQueue>
#include "counter.h"
#include <QObject>

QT_CHARTS_USE_NAMESPACE

size_t encode(const uint8_t *ptr, size_t length, uint8_t *dst);
size_t cobs_decode(const uint8_t * input, size_t length, uint8_t * output);

namespace Ui {
class MainWindow;/*class Counter;*/
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void build_static_plot();
    void serial_port_init(void);
    void set_default_values(void);


    Counter GetClass();
     Counter* cl1;
     Counter* cls1;
     QThread *thread;
     Ui::MainWindow *ui;
     int CountTime = 0;
     void StopNow(float, char);
     void Warner(QString);
     void SendForSmoothMove(char command_code, float time, float vel);


    public slots:
    void on_pushButton_Set_angle_clicked();
    //void SetCounter(int);
    void GetCounter( int);
    void SendBytesFloat(char command_code, float data);

private slots:
    void openConnection();
    void on_radioButton_disabled_mode_clicked();
    void on_radioButton_static_mode_clicked();
    void on_radioButton_sine_mode_clicked();
    void on_radioButton_speed_mode_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_pushButton_2_clicked();
    void on_write_Kp_clicked();
    void on_write_Ki_clicked();
    void on_write_Kd_clicked();
    void on_spinBox_des_val_valueChanged(double arg1);
    void on_button_sin_3_clicked();
    void on_button_sin_2_clicked();
    void on_button_sin_1_clicked();
    void on_button_sin_05_clicked();
    void on_button_sin_025_clicked();
    void SendByte(char command_code);
    void serialDataReceived();
    void serialDataReady();
    void on_pushButtonResetPlot_clicked();
    void on_savePlotToFile_clicked();
    void on_TestButton_clicked();
    void ReceiveSmoothCount(int);
    void ReceiveFuncCount(int);

    void on_pushButtonStartSaveToFile_clicked();

    void on_plot_graphic_stateChanged(int arg1);

    void on_pushButton_Set_angle_2_clicked();

    void on_spinBox_des_val_2_valueChanged(double arg1);

    void on_spinBox_des_val_2_editingFinished();

    void on_SmoothModeEnabled_clicked();

    void on_SmoothModeDisabled_clicked();

    void on_FuncModeEnabled_clicked();

    void on_FuncModeDisabled_clicked();

    void on_SmoothAutonomousEnabled_clicked();

    void on_SmoothAutonomousDisabled_clicked();

    void on_radioButton_SmoothMode_clicked();

    void on_radioButton_TrajectoryMode_clicked();

    void on_radioButton_SmoothMode_Autonomous_clicked();

    void on_radioButton_TrajectoryMode_Autonomous_clicked();

    void on_radioButton_path_mode_Autonomous_clicked();

    void on_Set_Linear_vel_clicked();

    void on_Set_Angular_vel_clicked();

    void on_PathModeEnabled_clicked();

    void on_PathModeDisabled_clicked();

signals:
void sendGlobalVar(int);
void EmitSmoothStartSignal(bool);
void EmitFuncStartSignal(bool);

private:

    QSerialPortInfo* portInfo;
    uint8_t MEMS_state;// выбранные источники сигнала
    QLineSeries *encoderPosPointsArr;
    QChart *encoderPosChart;
    QChartView *encoderChartView;
    bool plot_enabled = false;              // enable graphics plot
    bool save_to_file_enabled = false;      // enable graphics plot
    bool SmoothModeEnabled = false;   // enable SmoothMode
    bool SmoothStartSignal = false;   // enable Start Smooth Moving
    bool FuncStartSignal = false;   // enable FuncMode Moving
    bool FuncModeEnabled = false;   // enable FuncMode
    bool SmoothAutonomousEnabled = false;   // enable SmoothAutonomous Mode
    bool SmoothAutonomousStartSignal = false;   // enable Start Smooth Autonomous Moving
    bool PathModeStartSignal = false;   // enable FuncMode Moving
    bool PathModeEnabled = false;   // enable FuncMode
    bool DataReady = 0;
    QTextEdit WriteTime;


    QQueue<uint8_t>* serialDataQueue;

    //COM ===
    QSerialPort *port_test;
    QString serial_buffer;
    QByteArray data_buffer; // буфер для приема данных

    QMessageBox *warn = new QMessageBox();

    //============
//    QVector<int16_t> data1_v; // контейнер для первой переменной
//    QVector<int16_t> data2_v; // контейнер для второй переменной
//    QVector<int16_t> data3_v; // контейнер для третьего параметра
//    QVector<int16_t> data4_v; // акселерометр MPU6000
//    QVector<int16_t> data5_v; // акселерометр DA2
//    QVector<int16_t> data8_v; // угол по гироскопу L2GIS
//    QVector<uint16_t> current_v;
//    QVector<uint16_t> current_des_v;
//    bool oscillogramm_EN;
    QVector<float> series_vec;

    long int counter=0;
    double ChartTimeCount=0;
    char* input;
    int last_position;
    int last_speed;
    int flag_show_plot;
    float t[18];
    QString StringFunc[9];
     QString StringTime;
     float L_vel, W_vel;        // линейная скорость, угловая скорость

     int x=0;

};

#endif // MAINWINDOW_H
