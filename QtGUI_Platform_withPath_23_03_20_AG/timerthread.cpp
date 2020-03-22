#include "timerthread.h"
#include <QDebug>
#include <windows.h>
#include "mainwindow.h"

TimerThread::TimerThread(QString s) : name(s)
{

}

void TimerThread::do()
{
  //  Ui::MainWindow *ui;
//    clock_t timer = 0;
//    timer = clock();
for(int i = 0; i <= 100; i++)
{
    globtime=i;
    emit send(globtime);
    Sleep(1000);
    emit GetTime(globtime);
}
//return timer;
//Ui::MainWindow ui->textEdit->insertPlainText(QString::number(i));
//connect(doWork, SIGNAL(started()), my, SLOT(doWork()));
}




TimerThread::TimerThread()
{

}
