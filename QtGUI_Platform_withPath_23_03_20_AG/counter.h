#ifndef COUNTER_H
#define COUNTER_H

//#define globtime = 0
#define StdRollTime 30.0
#define AccellTime 10

#include <QObject>
#include <QString>
#include "qdebug.h"

class MainWindow;

//namespace Ui {
//class MainWindow;class Counter;
//}

class Counter:public QObject
{
    Q_OBJECT

public:
    explicit Counter();
    //void func1(/*MainWindow *ui*/);
   Counter& GetClass(Counter& cls1);
   void SetAddressClass(Counter& cls1);
   static Counter& GetAddressClass();
   //*Ui::*/MainWindow *ui;


public slots:
   //void Timer(bool);
//   int GetA();
//   void SetA(int);
   void ReceiveSmoothStartSignal(bool);
   void ReceiveFuncStartSignal(bool);
   void CounterTimer();


signals:
void sendSmooth(int);
void sendFunc(int);
void sendVirtData(int);


private:
    bool SmoothStartSignal=false;
    bool FuncStartSignal=false;
    int a, Count;
    Counter* cls1;
};

#endif // COUNTER_H
