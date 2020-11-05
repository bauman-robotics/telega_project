#include "counter.h"
#include <QDebug>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "mainwindow.h"
//#include <QThread>
//#include "windows.h"
#include <thread>
//#include <chrono>

//using namespace Ui;

Counter::Counter()
{

}

void Counter::ReceiveSmoothStartSignal(bool ss)
{
    SmoothStartSignal = ss;
    FuncStartSignal = false;
}

void Counter::ReceiveFuncStartSignal(bool ss)
{
    FuncStartSignal = ss;
    SmoothStartSignal = false;
}

void Counter::CounterTimer()
{
    while (1) {

        for (a = 0; a < 10000; a++) {
            sleep(100);
            emit sendVirtData(Count);
            // qDebug() << "emit virt data signal";
            Count = a;

            if (Count % 10 != 0) {
                ;
            } else {
                qDebug() << Count / 10;
                //std::this_thread::sleep_for(std::chrono::microseconds(8000));
                if (SmoothStartSignal==true) {
                    emit sendSmooth(Count / 10);
                    qDebug() << "GotSmoothStartSignal, emit send";
                }
                else if (FuncStartSignal == true) {
                    emit sendFunc(Count / 10);
                    qDebug() << "GotFuncStartSignal, emit send";
                }
            }
       }
   }
}

