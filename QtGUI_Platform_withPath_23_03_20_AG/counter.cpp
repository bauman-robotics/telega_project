#include "counter.h"
#include <QDebug>
#include <windows.h>
#include "mainwindow.h"
//#include <QThread>
//#include "windows.h"
#include <thread>
//#include <chrono>

//using namespace Ui;

Counter::Counter(){}

void Counter::ReceiveSmoothStartSignal(bool ss)
{
    SmoothStartSignal = ss;
    FuncStartSignal = FALSE;
}

void Counter::ReceiveFuncStartSignal(bool ss)
{
    FuncStartSignal = ss;
    SmoothStartSignal = FALSE;
}

void Counter::CounterTimer()
{
   while (1)
   {

            for (a=0; a<10000; a++)
   {
        Sleep(100);
        emit sendVirtData(Count);
       // qDebug() << "emit virt data signal";
        Count=a;

        if (Count%10!=0) ;
        else {
           qDebug() << Count/10;
        //std::this_thread::sleep_for(std::chrono::microseconds(8000));
         if (SmoothStartSignal==TRUE)
        {emit sendSmooth(Count/10); qDebug() << "GotSmoothStartSignal, emit send";}
         else if (FuncStartSignal==TRUE)
        {emit sendFunc(Count/10); qDebug() << "GotFuncStartSignal, emit send";}
        }
   }
   }
}

