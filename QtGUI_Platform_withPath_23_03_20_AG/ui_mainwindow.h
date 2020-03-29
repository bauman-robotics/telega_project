/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabStandOps;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QWidget *sin_button_widget;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *button_sin_025;
    QPushButton *button_sin_05;
    QPushButton *button_sin_1;
    QPushButton *button_sin_2;
    QPushButton *button_sin_3;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *spinBox_des_val;
    QPushButton *pushButton_Set_angle;
    QPushButton *pushButton_2;
    QPushButton *pushButton_Set_angle_2;
    QDoubleSpinBox *spinBox_des_val_2;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QRadioButton *radioButton_disabled_mode;
    QRadioButton *radioButton_static_mode;
    QRadioButton *radioButton_speed_mode;
    QRadioButton *radioButton_sine_mode;
    QLabel *label_7;
    QRadioButton *radioButton_SmoothMode;
    QRadioButton *radioButton_TrajectoryMode;
    QLabel *label_15;
    QRadioButton *radioButton_SmoothMode_Autonomous;
    QRadioButton *radioButton_TrajectoryMode_Autonomous;
    QRadioButton *radioButton_path_mode_Autonomous;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QComboBox *ListInfoPortsBox;
    QPushButton *ConnectBtn;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *udpConnectButton;
    QLineEdit *udpIpEdit;
    QWidget *tabEmbedOps;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QTextEdit *Kp_text;
    QPushButton *write_Kp;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QTextEdit *Ki_text;
    QPushButton *write_Ki;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QTextEdit *Kd_text;
    QPushButton *write_Kd;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_10;
    QTextEdit *WriteTime;
    QPushButton *SmoothModeEnabled;
    QPushButton *SmoothModeDisabled;
    QPushButton *SetTime;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_10;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_11;
    QTextEdit *WriteFunc_7;
    QTextEdit *WriteFunc_4;
    QTextEdit *WriteFunc_6;
    QPushButton *FuncModeDisabled;
    QTextEdit *WriteFunc_8;
    QHBoxLayout *horizontalLayout_12;
    QTextEdit *WriteTime_10;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *FuncModeEnabled;
    QLabel *label_13;
    QTextEdit *WriteFunc;
    QTextEdit *WriteFunc_3;
    QTextEdit *WriteFunc_9;
    QTextEdit *WriteFunc_5;
    QTextEdit *WriteFunc_2;
    QTextEdit *WriteTime_4;
    QTextEdit *WriteTime_5;
    QTextEdit *WriteTime_13;
    QTextEdit *WriteTime_6;
    QTextEdit *WriteTime_7;
    QTextEdit *WriteTime_8;
    QTextEdit *WriteTime_9;
    QTextEdit *WriteTime_11;
    QTextEdit *WriteTime_12;
    QTextEdit *WriteTime_14;
    QTextEdit *WriteTime_15;
    QTextEdit *WriteTime_16;
    QTextEdit *WriteTime_17;
    QTextEdit *WriteTime_18;
    QTextEdit *WriteTime_19;
    QTextEdit *WriteTime_20;
    QTextEdit *WriteTime_3;
    QLabel *label_11;
    QWidget *tabGraph;
    QChartView *graphicsView;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout;
    QPushButton *pushButtonResetPlot;
    QPushButton *savePlotToFile;
    QPushButton *pushButtonStartSaveToFile;
    QCheckBox *plot_graphic;
    QWidget *tab_Autonomous;
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_12;
    QPushButton *SmoothAutonomousEnabled;
    QLabel *label_14;
    QLabel *label_12;
    QPushButton *Set_Desired_Time;
    QTextEdit *Write_Desired_Time;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QPushButton *SmoothAutonomousDisabled;
    QTextEdit *Write_Desired_Velocity;
    QPushButton *Set_Desired_Velocity;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_13;
    QPushButton *PathModeEnabled;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *Set_Linear_vel;
    QTextEdit *Write_Linear_vel;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_18;
    QPushButton *PathModeDisabled;
    QTextEdit *Write_Angular_vel;
    QPushButton *Set_Angular_vel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(629, 608);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAcceptDrops(false);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 611, 591));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(100);
        sizePolicy2.setVerticalStretch(100);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setSizeIncrement(QSize(1, 1));
        tabWidget->setBaseSize(QSize(1, 1));
        tabStandOps = new QWidget();
        tabStandOps->setObjectName(QString::fromUtf8("tabStandOps"));
        sizePolicy1.setHeightForWidth(tabStandOps->sizePolicy().hasHeightForWidth());
        tabStandOps->setSizePolicy(sizePolicy1);
        gridLayout_6 = new QGridLayout(tabStandOps);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 20, 0, 20);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSlider = new QSlider(tabStandOps);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setEnabled(true);
        horizontalSlider->setMinimum(-360);
        horizontalSlider->setMaximum(360);
        horizontalSlider->setPageStep(20);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);

        gridLayout_2->addWidget(horizontalSlider, 2, 0, 1, 1);

        label_2 = new QLabel(tabStandOps);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        sin_button_widget = new QWidget(tabStandOps);
        sin_button_widget->setObjectName(QString::fromUtf8("sin_button_widget"));
        sin_button_widget->setEnabled(true);
        gridLayout_7 = new QGridLayout(sin_button_widget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        button_sin_025 = new QPushButton(sin_button_widget);
        button_sin_025->setObjectName(QString::fromUtf8("button_sin_025"));
        button_sin_025->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(button_sin_025);

        button_sin_05 = new QPushButton(sin_button_widget);
        button_sin_05->setObjectName(QString::fromUtf8("button_sin_05"));

        horizontalLayout_5->addWidget(button_sin_05);

        button_sin_1 = new QPushButton(sin_button_widget);
        button_sin_1->setObjectName(QString::fromUtf8("button_sin_1"));

        horizontalLayout_5->addWidget(button_sin_1);

        button_sin_2 = new QPushButton(sin_button_widget);
        button_sin_2->setObjectName(QString::fromUtf8("button_sin_2"));

        horizontalLayout_5->addWidget(button_sin_2);

        button_sin_3 = new QPushButton(sin_button_widget);
        button_sin_3->setObjectName(QString::fromUtf8("button_sin_3"));

        horizontalLayout_5->addWidget(button_sin_3);


        gridLayout_7->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        gridLayout_2->addWidget(sin_button_widget, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        spinBox_des_val = new QDoubleSpinBox(tabStandOps);
        spinBox_des_val->setObjectName(QString::fromUtf8("spinBox_des_val"));
        spinBox_des_val->setMinimumSize(QSize(100, 0));
        spinBox_des_val->setDecimals(4);
        spinBox_des_val->setSingleStep(0.100000000000000);

        horizontalLayout_4->addWidget(spinBox_des_val);

        pushButton_Set_angle = new QPushButton(tabStandOps);
        pushButton_Set_angle->setObjectName(QString::fromUtf8("pushButton_Set_angle"));

        horizontalLayout_4->addWidget(pushButton_Set_angle);

        pushButton_2 = new QPushButton(tabStandOps);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton_Set_angle_2 = new QPushButton(tabStandOps);
        pushButton_Set_angle_2->setObjectName(QString::fromUtf8("pushButton_Set_angle_2"));
        pushButton_Set_angle_2->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_4->addWidget(pushButton_Set_angle_2);

        spinBox_des_val_2 = new QDoubleSpinBox(tabStandOps);
        spinBox_des_val_2->setObjectName(QString::fromUtf8("spinBox_des_val_2"));
        spinBox_des_val_2->setMinimumSize(QSize(100, 0));
        spinBox_des_val_2->setDecimals(4);
        spinBox_des_val_2->setSingleStep(0.100000000000000);

        horizontalLayout_4->addWidget(spinBox_des_val_2);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 2, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(12);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(tabStandOps);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Comic Sans MS"));
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        radioButton_disabled_mode = new QRadioButton(tabStandOps);
        radioButton_disabled_mode->setObjectName(QString::fromUtf8("radioButton_disabled_mode"));

        verticalLayout_2->addWidget(radioButton_disabled_mode);

        radioButton_static_mode = new QRadioButton(tabStandOps);
        radioButton_static_mode->setObjectName(QString::fromUtf8("radioButton_static_mode"));

        verticalLayout_2->addWidget(radioButton_static_mode);

        radioButton_speed_mode = new QRadioButton(tabStandOps);
        radioButton_speed_mode->setObjectName(QString::fromUtf8("radioButton_speed_mode"));

        verticalLayout_2->addWidget(radioButton_speed_mode);

        radioButton_sine_mode = new QRadioButton(tabStandOps);
        radioButton_sine_mode->setObjectName(QString::fromUtf8("radioButton_sine_mode"));

        verticalLayout_2->addWidget(radioButton_sine_mode);

        label_7 = new QLabel(tabStandOps);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy5);
        label_7->setMaximumSize(QSize(360, 30));
        label_7->setFont(font1);
        label_7->setScaledContents(true);
        label_7->setWordWrap(true);

        verticalLayout_2->addWidget(label_7);

        radioButton_SmoothMode = new QRadioButton(tabStandOps);
        radioButton_SmoothMode->setObjectName(QString::fromUtf8("radioButton_SmoothMode"));
        sizePolicy4.setHeightForWidth(radioButton_SmoothMode->sizePolicy().hasHeightForWidth());
        radioButton_SmoothMode->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(radioButton_SmoothMode);

        radioButton_TrajectoryMode = new QRadioButton(tabStandOps);
        radioButton_TrajectoryMode->setObjectName(QString::fromUtf8("radioButton_TrajectoryMode"));
        radioButton_TrajectoryMode->setEnabled(true);
        sizePolicy4.setHeightForWidth(radioButton_TrajectoryMode->sizePolicy().hasHeightForWidth());
        radioButton_TrajectoryMode->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(radioButton_TrajectoryMode);

        label_15 = new QLabel(tabStandOps);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy5.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy5);
        label_15->setMaximumSize(QSize(360, 30));
        label_15->setFont(font1);
        label_15->setScaledContents(true);
        label_15->setWordWrap(true);

        verticalLayout_2->addWidget(label_15);

        radioButton_SmoothMode_Autonomous = new QRadioButton(tabStandOps);
        radioButton_SmoothMode_Autonomous->setObjectName(QString::fromUtf8("radioButton_SmoothMode_Autonomous"));
        sizePolicy4.setHeightForWidth(radioButton_SmoothMode_Autonomous->sizePolicy().hasHeightForWidth());
        radioButton_SmoothMode_Autonomous->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(radioButton_SmoothMode_Autonomous);

        radioButton_TrajectoryMode_Autonomous = new QRadioButton(tabStandOps);
        radioButton_TrajectoryMode_Autonomous->setObjectName(QString::fromUtf8("radioButton_TrajectoryMode_Autonomous"));
        radioButton_TrajectoryMode_Autonomous->setEnabled(false);
        sizePolicy4.setHeightForWidth(radioButton_TrajectoryMode_Autonomous->sizePolicy().hasHeightForWidth());
        radioButton_TrajectoryMode_Autonomous->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(radioButton_TrajectoryMode_Autonomous);

        radioButton_path_mode_Autonomous = new QRadioButton(tabStandOps);
        radioButton_path_mode_Autonomous->setObjectName(QString::fromUtf8("radioButton_path_mode_Autonomous"));
        radioButton_path_mode_Autonomous->setEnabled(true);

        verticalLayout_2->addWidget(radioButton_path_mode_Autonomous);


        horizontalLayout_9->addLayout(verticalLayout_2);

        toolBox = new QToolBox(tabStandOps);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy6);
        toolBox->setMinimumSize(QSize(150, 0));
        toolBox->setAutoFillBackground(false);
        toolBox->setLineWidth(1);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 150, 69));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        ListInfoPortsBox = new QComboBox(page);
        ListInfoPortsBox->setObjectName(QString::fromUtf8("ListInfoPortsBox"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(ListInfoPortsBox->sizePolicy().hasHeightForWidth());
        ListInfoPortsBox->setSizePolicy(sizePolicy7);

        verticalLayout_3->addWidget(ListInfoPortsBox);

        ConnectBtn = new QPushButton(page);
        ConnectBtn->setObjectName(QString::fromUtf8("ConnectBtn"));
        sizePolicy7.setHeightForWidth(ConnectBtn->sizePolicy().hasHeightForWidth());
        ConnectBtn->setSizePolicy(sizePolicy7);

        verticalLayout_3->addWidget(ConnectBtn);

        toolBox->addItem(page, QString::fromUtf8("Serial Connection"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 134, 69));
        sizePolicy1.setHeightForWidth(page_2->sizePolicy().hasHeightForWidth());
        page_2->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        udpConnectButton = new QPushButton(page_2);
        udpConnectButton->setObjectName(QString::fromUtf8("udpConnectButton"));
        udpConnectButton->setEnabled(false);
        sizePolicy3.setHeightForWidth(udpConnectButton->sizePolicy().hasHeightForWidth());
        udpConnectButton->setSizePolicy(sizePolicy3);

        verticalLayout_4->addWidget(udpConnectButton);

        udpIpEdit = new QLineEdit(page_2);
        udpIpEdit->setObjectName(QString::fromUtf8("udpIpEdit"));
        udpIpEdit->setEnabled(false);
        sizePolicy3.setHeightForWidth(udpIpEdit->sizePolicy().hasHeightForWidth());
        udpIpEdit->setSizePolicy(sizePolicy3);

        verticalLayout_4->addWidget(udpIpEdit);

        toolBox->addItem(page_2, QString::fromUtf8("UDP Connection"));
        udpConnectButton->raise();
        udpIpEdit->raise();

        horizontalLayout_9->addWidget(toolBox);


        gridLayout_5->addLayout(horizontalLayout_9, 0, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        tabWidget->addTab(tabStandOps, QString());
        tabEmbedOps = new QWidget();
        tabEmbedOps->setObjectName(QString::fromUtf8("tabEmbedOps"));
        layoutWidget_2 = new QWidget(tabEmbedOps);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 0, 192, 141));
        gridLayout_4 = new QGridLayout(layoutWidget_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy6.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy6);
        label_6->setFont(font1);

        verticalLayout->addWidget(label_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy6.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy6);
        label_3->setMinimumSize(QSize(20, 10));

        horizontalLayout->addWidget(label_3);

        Kp_text = new QTextEdit(layoutWidget_2);
        Kp_text->setObjectName(QString::fromUtf8("Kp_text"));
        QSizePolicy sizePolicy8(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(Kp_text->sizePolicy().hasHeightForWidth());
        Kp_text->setSizePolicy(sizePolicy8);
        Kp_text->setMaximumSize(QSize(71, 29));

        horizontalLayout->addWidget(Kp_text);

        write_Kp = new QPushButton(layoutWidget_2);
        write_Kp->setObjectName(QString::fromUtf8("write_Kp"));
        sizePolicy3.setHeightForWidth(write_Kp->sizePolicy().hasHeightForWidth());
        write_Kp->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(write_Kp);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy6.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy6);
        label_4->setMinimumSize(QSize(20, 10));

        horizontalLayout_3->addWidget(label_4);

        Ki_text = new QTextEdit(layoutWidget_2);
        Ki_text->setObjectName(QString::fromUtf8("Ki_text"));
        sizePolicy8.setHeightForWidth(Ki_text->sizePolicy().hasHeightForWidth());
        Ki_text->setSizePolicy(sizePolicy8);
        Ki_text->setMaximumSize(QSize(71, 29));

        horizontalLayout_3->addWidget(Ki_text);

        write_Ki = new QPushButton(layoutWidget_2);
        write_Ki->setObjectName(QString::fromUtf8("write_Ki"));
        sizePolicy3.setHeightForWidth(write_Ki->sizePolicy().hasHeightForWidth());
        write_Ki->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(write_Ki);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy6.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy6);
        label_5->setMinimumSize(QSize(20, 10));

        horizontalLayout_2->addWidget(label_5);

        Kd_text = new QTextEdit(layoutWidget_2);
        Kd_text->setObjectName(QString::fromUtf8("Kd_text"));
        sizePolicy8.setHeightForWidth(Kd_text->sizePolicy().hasHeightForWidth());
        Kd_text->setSizePolicy(sizePolicy8);
        Kd_text->setMaximumSize(QSize(71, 29));

        horizontalLayout_2->addWidget(Kd_text);

        write_Kd = new QPushButton(layoutWidget_2);
        write_Kd->setObjectName(QString::fromUtf8("write_Kd"));
        sizePolicy3.setHeightForWidth(write_Kd->sizePolicy().hasHeightForWidth());
        write_Kd->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(write_Kd);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_4->addLayout(verticalLayout, 1, 0, 1, 1);

        layoutWidget = new QWidget(tabEmbedOps);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(204, 0, 235, 141));
        gridLayout_10 = new QGridLayout(layoutWidget);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        WriteTime = new QTextEdit(layoutWidget);
        WriteTime->setObjectName(QString::fromUtf8("WriteTime"));
        sizePolicy3.setHeightForWidth(WriteTime->sizePolicy().hasHeightForWidth());
        WriteTime->setSizePolicy(sizePolicy3);
        WriteTime->setMaximumSize(QSize(71, 29));

        gridLayout_10->addWidget(WriteTime, 2, 1, 1, 1);

        SmoothModeEnabled = new QPushButton(layoutWidget);
        SmoothModeEnabled->setObjectName(QString::fromUtf8("SmoothModeEnabled"));
        sizePolicy3.setHeightForWidth(SmoothModeEnabled->sizePolicy().hasHeightForWidth());
        SmoothModeEnabled->setSizePolicy(sizePolicy3);
        SmoothModeEnabled->setMinimumSize(QSize(5, 0));
        SmoothModeEnabled->setLayoutDirection(Qt::LeftToRight);

        gridLayout_10->addWidget(SmoothModeEnabled, 6, 0, 1, 1);

        SmoothModeDisabled = new QPushButton(layoutWidget);
        SmoothModeDisabled->setObjectName(QString::fromUtf8("SmoothModeDisabled"));
        SmoothModeDisabled->setEnabled(false);
        sizePolicy3.setHeightForWidth(SmoothModeDisabled->sizePolicy().hasHeightForWidth());
        SmoothModeDisabled->setSizePolicy(sizePolicy3);

        gridLayout_10->addWidget(SmoothModeDisabled, 7, 0, 1, 1);

        SetTime = new QPushButton(layoutWidget);
        SetTime->setObjectName(QString::fromUtf8("SetTime"));
        sizePolicy3.setHeightForWidth(SetTime->sizePolicy().hasHeightForWidth());
        SetTime->setSizePolicy(sizePolicy3);

        gridLayout_10->addWidget(SetTime, 2, 2, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(label_8);


        gridLayout_10->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_10->addItem(verticalSpacer_3, 6, 1, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy6.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy6);
        label_10->setMinimumSize(QSize(30, 0));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_10, 1, 0, 1, 3);

        layoutWidget1 = new QWidget(tabEmbedOps);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 150, 371, 381));
        gridLayout_11 = new QGridLayout(layoutWidget1);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        WriteFunc_7 = new QTextEdit(layoutWidget1);
        WriteFunc_7->setObjectName(QString::fromUtf8("WriteFunc_7"));
        sizePolicy.setHeightForWidth(WriteFunc_7->sizePolicy().hasHeightForWidth());
        WriteFunc_7->setSizePolicy(sizePolicy);
        WriteFunc_7->setMaximumSize(QSize(200, 29));

        gridLayout_11->addWidget(WriteFunc_7, 9, 1, 1, 1);

        WriteFunc_4 = new QTextEdit(layoutWidget1);
        WriteFunc_4->setObjectName(QString::fromUtf8("WriteFunc_4"));
        sizePolicy.setHeightForWidth(WriteFunc_4->sizePolicy().hasHeightForWidth());
        WriteFunc_4->setSizePolicy(sizePolicy);
        WriteFunc_4->setMaximumSize(QSize(200, 29));

        gridLayout_11->addWidget(WriteFunc_4, 12, 1, 1, 1);

        WriteFunc_6 = new QTextEdit(layoutWidget1);
        WriteFunc_6->setObjectName(QString::fromUtf8("WriteFunc_6"));
        sizePolicy.setHeightForWidth(WriteFunc_6->sizePolicy().hasHeightForWidth());
        WriteFunc_6->setSizePolicy(sizePolicy);
        WriteFunc_6->setMaximumSize(QSize(200, 29));

        gridLayout_11->addWidget(WriteFunc_6, 8, 1, 1, 1);

        FuncModeDisabled = new QPushButton(layoutWidget1);
        FuncModeDisabled->setObjectName(QString::fromUtf8("FuncModeDisabled"));
        FuncModeDisabled->setEnabled(false);
        sizePolicy3.setHeightForWidth(FuncModeDisabled->sizePolicy().hasHeightForWidth());
        FuncModeDisabled->setSizePolicy(sizePolicy3);

        gridLayout_11->addWidget(FuncModeDisabled, 4, 0, 1, 1);

        WriteFunc_8 = new QTextEdit(layoutWidget1);
        WriteFunc_8->setObjectName(QString::fromUtf8("WriteFunc_8"));
        sizePolicy.setHeightForWidth(WriteFunc_8->sizePolicy().hasHeightForWidth());
        WriteFunc_8->setSizePolicy(sizePolicy);
        WriteFunc_8->setMaximumSize(QSize(200, 29));

        gridLayout_11->addWidget(WriteFunc_8, 10, 1, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        WriteTime_10 = new QTextEdit(layoutWidget1);
        WriteTime_10->setObjectName(QString::fromUtf8("WriteTime_10"));
        QSizePolicy sizePolicy9(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(WriteTime_10->sizePolicy().hasHeightForWidth());
        WriteTime_10->setSizePolicy(sizePolicy9);
        WriteTime_10->setMaximumSize(QSize(71, 29));
        WriteTime_10->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_10->setTabChangesFocus(false);

        horizontalLayout_12->addWidget(WriteTime_10);


        gridLayout_11->addLayout(horizontalLayout_12, 11, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        FuncModeEnabled = new QPushButton(layoutWidget1);
        FuncModeEnabled->setObjectName(QString::fromUtf8("FuncModeEnabled"));
        sizePolicy3.setHeightForWidth(FuncModeEnabled->sizePolicy().hasHeightForWidth());
        FuncModeEnabled->setSizePolicy(sizePolicy3);
        FuncModeEnabled->setMinimumSize(QSize(5, 0));
        FuncModeEnabled->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_7->addWidget(FuncModeEnabled);


        gridLayout_11->addLayout(horizontalLayout_7, 3, 0, 1, 1);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy6.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy6);
        label_13->setMinimumSize(QSize(30, 0));
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_13, 0, 0, 1, 3);

        WriteFunc = new QTextEdit(layoutWidget1);
        WriteFunc->setObjectName(QString::fromUtf8("WriteFunc"));
        sizePolicy.setHeightForWidth(WriteFunc->sizePolicy().hasHeightForWidth());
        WriteFunc->setSizePolicy(sizePolicy);
        WriteFunc->setMaximumSize(QSize(200, 29));

        gridLayout_11->addWidget(WriteFunc, 3, 1, 1, 1);

        WriteFunc_3 = new QTextEdit(layoutWidget1);
        WriteFunc_3->setObjectName(QString::fromUtf8("WriteFunc_3"));
        sizePolicy.setHeightForWidth(WriteFunc_3->sizePolicy().hasHeightForWidth());
        WriteFunc_3->setSizePolicy(sizePolicy);
        WriteFunc_3->setMaximumSize(QSize(200, 29));

        gridLayout_11->addWidget(WriteFunc_3, 6, 1, 1, 1);

        WriteFunc_9 = new QTextEdit(layoutWidget1);
        WriteFunc_9->setObjectName(QString::fromUtf8("WriteFunc_9"));
        sizePolicy.setHeightForWidth(WriteFunc_9->sizePolicy().hasHeightForWidth());
        WriteFunc_9->setSizePolicy(sizePolicy);
        WriteFunc_9->setMaximumSize(QSize(200, 29));

        gridLayout_11->addWidget(WriteFunc_9, 11, 1, 1, 1);

        WriteFunc_5 = new QTextEdit(layoutWidget1);
        WriteFunc_5->setObjectName(QString::fromUtf8("WriteFunc_5"));
        sizePolicy.setHeightForWidth(WriteFunc_5->sizePolicy().hasHeightForWidth());
        WriteFunc_5->setSizePolicy(sizePolicy);
        WriteFunc_5->setMaximumSize(QSize(200, 29));

        gridLayout_11->addWidget(WriteFunc_5, 7, 1, 1, 1);

        WriteFunc_2 = new QTextEdit(layoutWidget1);
        WriteFunc_2->setObjectName(QString::fromUtf8("WriteFunc_2"));
        sizePolicy.setHeightForWidth(WriteFunc_2->sizePolicy().hasHeightForWidth());
        WriteFunc_2->setSizePolicy(sizePolicy);
        WriteFunc_2->setMaximumSize(QSize(200, 29));

        gridLayout_11->addWidget(WriteFunc_2, 5, 1, 1, 1);

        WriteTime_4 = new QTextEdit(layoutWidget1);
        WriteTime_4->setObjectName(QString::fromUtf8("WriteTime_4"));
        sizePolicy9.setHeightForWidth(WriteTime_4->sizePolicy().hasHeightForWidth());
        WriteTime_4->setSizePolicy(sizePolicy9);
        WriteTime_4->setMaximumSize(QSize(71, 29));
        WriteTime_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_4->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_4, 4, 2, 1, 1);

        WriteTime_5 = new QTextEdit(layoutWidget1);
        WriteTime_5->setObjectName(QString::fromUtf8("WriteTime_5"));
        sizePolicy9.setHeightForWidth(WriteTime_5->sizePolicy().hasHeightForWidth());
        WriteTime_5->setSizePolicy(sizePolicy9);
        WriteTime_5->setMaximumSize(QSize(71, 29));
        WriteTime_5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_5->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_5, 5, 0, 1, 1);

        WriteTime_13 = new QTextEdit(layoutWidget1);
        WriteTime_13->setObjectName(QString::fromUtf8("WriteTime_13"));
        sizePolicy9.setHeightForWidth(WriteTime_13->sizePolicy().hasHeightForWidth());
        WriteTime_13->setSizePolicy(sizePolicy9);
        WriteTime_13->setMaximumSize(QSize(71, 29));
        WriteTime_13->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_13->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_13, 6, 0, 1, 1);

        WriteTime_6 = new QTextEdit(layoutWidget1);
        WriteTime_6->setObjectName(QString::fromUtf8("WriteTime_6"));
        sizePolicy9.setHeightForWidth(WriteTime_6->sizePolicy().hasHeightForWidth());
        WriteTime_6->setSizePolicy(sizePolicy9);
        WriteTime_6->setMaximumSize(QSize(71, 29));
        WriteTime_6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_6->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_6, 7, 0, 1, 1);

        WriteTime_7 = new QTextEdit(layoutWidget1);
        WriteTime_7->setObjectName(QString::fromUtf8("WriteTime_7"));
        sizePolicy9.setHeightForWidth(WriteTime_7->sizePolicy().hasHeightForWidth());
        WriteTime_7->setSizePolicy(sizePolicy9);
        WriteTime_7->setMaximumSize(QSize(71, 29));
        WriteTime_7->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_7->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_7, 8, 0, 1, 1);

        WriteTime_8 = new QTextEdit(layoutWidget1);
        WriteTime_8->setObjectName(QString::fromUtf8("WriteTime_8"));
        sizePolicy9.setHeightForWidth(WriteTime_8->sizePolicy().hasHeightForWidth());
        WriteTime_8->setSizePolicy(sizePolicy9);
        WriteTime_8->setMaximumSize(QSize(71, 29));
        WriteTime_8->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_8->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_8, 9, 0, 1, 1);

        WriteTime_9 = new QTextEdit(layoutWidget1);
        WriteTime_9->setObjectName(QString::fromUtf8("WriteTime_9"));
        sizePolicy9.setHeightForWidth(WriteTime_9->sizePolicy().hasHeightForWidth());
        WriteTime_9->setSizePolicy(sizePolicy9);
        WriteTime_9->setMaximumSize(QSize(71, 29));
        WriteTime_9->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_9->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_9, 10, 0, 1, 1);

        WriteTime_11 = new QTextEdit(layoutWidget1);
        WriteTime_11->setObjectName(QString::fromUtf8("WriteTime_11"));
        sizePolicy9.setHeightForWidth(WriteTime_11->sizePolicy().hasHeightForWidth());
        WriteTime_11->setSizePolicy(sizePolicy9);
        WriteTime_11->setMaximumSize(QSize(71, 29));
        WriteTime_11->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_11->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_11, 12, 0, 1, 1);

        WriteTime_12 = new QTextEdit(layoutWidget1);
        WriteTime_12->setObjectName(QString::fromUtf8("WriteTime_12"));
        sizePolicy9.setHeightForWidth(WriteTime_12->sizePolicy().hasHeightForWidth());
        WriteTime_12->setSizePolicy(sizePolicy9);
        WriteTime_12->setMaximumSize(QSize(71, 29));
        WriteTime_12->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_12->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_12, 5, 2, 1, 1);

        WriteTime_14 = new QTextEdit(layoutWidget1);
        WriteTime_14->setObjectName(QString::fromUtf8("WriteTime_14"));
        sizePolicy9.setHeightForWidth(WriteTime_14->sizePolicy().hasHeightForWidth());
        WriteTime_14->setSizePolicy(sizePolicy9);
        WriteTime_14->setMaximumSize(QSize(71, 29));
        WriteTime_14->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_14->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_14, 6, 2, 1, 1);

        WriteTime_15 = new QTextEdit(layoutWidget1);
        WriteTime_15->setObjectName(QString::fromUtf8("WriteTime_15"));
        sizePolicy9.setHeightForWidth(WriteTime_15->sizePolicy().hasHeightForWidth());
        WriteTime_15->setSizePolicy(sizePolicy9);
        WriteTime_15->setMaximumSize(QSize(71, 29));
        WriteTime_15->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_15->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_15, 7, 2, 1, 1);

        WriteTime_16 = new QTextEdit(layoutWidget1);
        WriteTime_16->setObjectName(QString::fromUtf8("WriteTime_16"));
        sizePolicy9.setHeightForWidth(WriteTime_16->sizePolicy().hasHeightForWidth());
        WriteTime_16->setSizePolicy(sizePolicy9);
        WriteTime_16->setMaximumSize(QSize(71, 29));
        WriteTime_16->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_16->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_16, 8, 2, 1, 1);

        WriteTime_17 = new QTextEdit(layoutWidget1);
        WriteTime_17->setObjectName(QString::fromUtf8("WriteTime_17"));
        sizePolicy9.setHeightForWidth(WriteTime_17->sizePolicy().hasHeightForWidth());
        WriteTime_17->setSizePolicy(sizePolicy9);
        WriteTime_17->setMaximumSize(QSize(71, 29));
        WriteTime_17->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_17->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_17, 9, 2, 1, 1);

        WriteTime_18 = new QTextEdit(layoutWidget1);
        WriteTime_18->setObjectName(QString::fromUtf8("WriteTime_18"));
        sizePolicy9.setHeightForWidth(WriteTime_18->sizePolicy().hasHeightForWidth());
        WriteTime_18->setSizePolicy(sizePolicy9);
        WriteTime_18->setMaximumSize(QSize(71, 29));
        WriteTime_18->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_18->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_18, 10, 2, 1, 1);

        WriteTime_19 = new QTextEdit(layoutWidget1);
        WriteTime_19->setObjectName(QString::fromUtf8("WriteTime_19"));
        sizePolicy9.setHeightForWidth(WriteTime_19->sizePolicy().hasHeightForWidth());
        WriteTime_19->setSizePolicy(sizePolicy9);
        WriteTime_19->setMaximumSize(QSize(71, 29));
        WriteTime_19->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_19->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_19, 11, 2, 1, 1);

        WriteTime_20 = new QTextEdit(layoutWidget1);
        WriteTime_20->setObjectName(QString::fromUtf8("WriteTime_20"));
        sizePolicy9.setHeightForWidth(WriteTime_20->sizePolicy().hasHeightForWidth());
        WriteTime_20->setSizePolicy(sizePolicy9);
        WriteTime_20->setMaximumSize(QSize(71, 29));
        WriteTime_20->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_20->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_20, 12, 2, 1, 1);

        WriteTime_3 = new QTextEdit(layoutWidget1);
        WriteTime_3->setObjectName(QString::fromUtf8("WriteTime_3"));
        sizePolicy9.setHeightForWidth(WriteTime_3->sizePolicy().hasHeightForWidth());
        WriteTime_3->setSizePolicy(sizePolicy9);
        WriteTime_3->setMaximumSize(QSize(71, 29));
        WriteTime_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        WriteTime_3->setTabChangesFocus(false);

        gridLayout_11->addWidget(WriteTime_3, 3, 2, 1, 1);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy6.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy6);
        label_11->setMinimumSize(QSize(30, 0));
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_11, 4, 1, 1, 1);

        tabWidget->addTab(tabEmbedOps, QString());
        tabGraph = new QWidget();
        tabGraph->setObjectName(QString::fromUtf8("tabGraph"));
        QSizePolicy sizePolicy10(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(tabGraph->sizePolicy().hasHeightForWidth());
        tabGraph->setSizePolicy(sizePolicy10);
        graphicsView = new QChartView(tabGraph);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 601, 481));
        sizePolicy2.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy2);
        layoutWidget_3 = new QWidget(tabGraph);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(0, 500, 402, 31));
        gridLayout = new QGridLayout(layoutWidget_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonResetPlot = new QPushButton(layoutWidget_3);
        pushButtonResetPlot->setObjectName(QString::fromUtf8("pushButtonResetPlot"));
        pushButtonResetPlot->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(pushButtonResetPlot, 0, 1, 1, 1);

        savePlotToFile = new QPushButton(layoutWidget_3);
        savePlotToFile->setObjectName(QString::fromUtf8("savePlotToFile"));
        savePlotToFile->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(savePlotToFile, 0, 3, 1, 1);

        pushButtonStartSaveToFile = new QPushButton(layoutWidget_3);
        pushButtonStartSaveToFile->setObjectName(QString::fromUtf8("pushButtonStartSaveToFile"));

        gridLayout->addWidget(pushButtonStartSaveToFile, 0, 2, 1, 1);

        plot_graphic = new QCheckBox(layoutWidget_3);
        plot_graphic->setObjectName(QString::fromUtf8("plot_graphic"));

        gridLayout->addWidget(plot_graphic, 0, 0, 1, 1);

        tabWidget->addTab(tabGraph, QString());
        tab_Autonomous = new QWidget();
        tab_Autonomous->setObjectName(QString::fromUtf8("tab_Autonomous"));
        layoutWidget_4 = new QWidget(tab_Autonomous);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 20, 260, 154));
        gridLayout_12 = new QGridLayout(layoutWidget_4);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        SmoothAutonomousEnabled = new QPushButton(layoutWidget_4);
        SmoothAutonomousEnabled->setObjectName(QString::fromUtf8("SmoothAutonomousEnabled"));
        sizePolicy3.setHeightForWidth(SmoothAutonomousEnabled->sizePolicy().hasHeightForWidth());
        SmoothAutonomousEnabled->setSizePolicy(sizePolicy3);
        SmoothAutonomousEnabled->setMinimumSize(QSize(5, 0));
        SmoothAutonomousEnabled->setLayoutDirection(Qt::LeftToRight);

        gridLayout_12->addWidget(SmoothAutonomousEnabled, 8, 0, 1, 1);

        label_14 = new QLabel(layoutWidget_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);

        gridLayout_12->addWidget(label_14, 6, 0, 1, 1);

        label_12 = new QLabel(layoutWidget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy6.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy6);
        label_12->setMinimumSize(QSize(30, 0));
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_12, 1, 0, 1, 3);

        Set_Desired_Time = new QPushButton(layoutWidget_4);
        Set_Desired_Time->setObjectName(QString::fromUtf8("Set_Desired_Time"));
        sizePolicy3.setHeightForWidth(Set_Desired_Time->sizePolicy().hasHeightForWidth());
        Set_Desired_Time->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(Set_Desired_Time, 2, 2, 1, 1);

        Write_Desired_Time = new QTextEdit(layoutWidget_4);
        Write_Desired_Time->setObjectName(QString::fromUtf8("Write_Desired_Time"));
        sizePolicy3.setHeightForWidth(Write_Desired_Time->sizePolicy().hasHeightForWidth());
        Write_Desired_Time->setSizePolicy(sizePolicy3);
        Write_Desired_Time->setMaximumSize(QSize(71, 29));

        gridLayout_12->addWidget(Write_Desired_Time, 2, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(layoutWidget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(label_9);


        gridLayout_12->addLayout(horizontalLayout_8, 2, 0, 1, 1);

        SmoothAutonomousDisabled = new QPushButton(layoutWidget_4);
        SmoothAutonomousDisabled->setObjectName(QString::fromUtf8("SmoothAutonomousDisabled"));
        SmoothAutonomousDisabled->setEnabled(false);
        sizePolicy3.setHeightForWidth(SmoothAutonomousDisabled->sizePolicy().hasHeightForWidth());
        SmoothAutonomousDisabled->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(SmoothAutonomousDisabled, 8, 2, 1, 1);

        Write_Desired_Velocity = new QTextEdit(layoutWidget_4);
        Write_Desired_Velocity->setObjectName(QString::fromUtf8("Write_Desired_Velocity"));
        sizePolicy3.setHeightForWidth(Write_Desired_Velocity->sizePolicy().hasHeightForWidth());
        Write_Desired_Velocity->setSizePolicy(sizePolicy3);
        Write_Desired_Velocity->setMaximumSize(QSize(71, 29));

        gridLayout_12->addWidget(Write_Desired_Velocity, 6, 1, 1, 1);

        Set_Desired_Velocity = new QPushButton(layoutWidget_4);
        Set_Desired_Velocity->setObjectName(QString::fromUtf8("Set_Desired_Velocity"));
        sizePolicy3.setHeightForWidth(Set_Desired_Velocity->sizePolicy().hasHeightForWidth());
        Set_Desired_Velocity->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(Set_Desired_Velocity, 6, 2, 1, 1);

        layoutWidget_5 = new QWidget(tab_Autonomous);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(290, 20, 260, 154));
        gridLayout_13 = new QGridLayout(layoutWidget_5);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        PathModeEnabled = new QPushButton(layoutWidget_5);
        PathModeEnabled->setObjectName(QString::fromUtf8("PathModeEnabled"));
        sizePolicy3.setHeightForWidth(PathModeEnabled->sizePolicy().hasHeightForWidth());
        PathModeEnabled->setSizePolicy(sizePolicy3);
        PathModeEnabled->setMinimumSize(QSize(5, 0));
        PathModeEnabled->setLayoutDirection(Qt::LeftToRight);

        gridLayout_13->addWidget(PathModeEnabled, 8, 0, 1, 1);

        label_16 = new QLabel(layoutWidget_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);

        gridLayout_13->addWidget(label_16, 6, 0, 1, 1);

        label_17 = new QLabel(layoutWidget_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy6.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy6);
        label_17->setMinimumSize(QSize(30, 0));
        label_17->setFont(font1);
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(label_17, 1, 0, 1, 3);

        Set_Linear_vel = new QPushButton(layoutWidget_5);
        Set_Linear_vel->setObjectName(QString::fromUtf8("Set_Linear_vel"));
        sizePolicy3.setHeightForWidth(Set_Linear_vel->sizePolicy().hasHeightForWidth());
        Set_Linear_vel->setSizePolicy(sizePolicy3);

        gridLayout_13->addWidget(Set_Linear_vel, 2, 2, 1, 1);

        Write_Linear_vel = new QTextEdit(layoutWidget_5);
        Write_Linear_vel->setObjectName(QString::fromUtf8("Write_Linear_vel"));
        sizePolicy3.setHeightForWidth(Write_Linear_vel->sizePolicy().hasHeightForWidth());
        Write_Linear_vel->setSizePolicy(sizePolicy3);
        Write_Linear_vel->setMaximumSize(QSize(71, 29));

        gridLayout_13->addWidget(Write_Linear_vel, 2, 1, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_18 = new QLabel(layoutWidget_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy1.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(label_18);


        gridLayout_13->addLayout(horizontalLayout_10, 2, 0, 1, 1);

        PathModeDisabled = new QPushButton(layoutWidget_5);
        PathModeDisabled->setObjectName(QString::fromUtf8("PathModeDisabled"));
        PathModeDisabled->setEnabled(false);
        sizePolicy3.setHeightForWidth(PathModeDisabled->sizePolicy().hasHeightForWidth());
        PathModeDisabled->setSizePolicy(sizePolicy3);

        gridLayout_13->addWidget(PathModeDisabled, 8, 2, 1, 1);

        Write_Angular_vel = new QTextEdit(layoutWidget_5);
        Write_Angular_vel->setObjectName(QString::fromUtf8("Write_Angular_vel"));
        sizePolicy3.setHeightForWidth(Write_Angular_vel->sizePolicy().hasHeightForWidth());
        Write_Angular_vel->setSizePolicy(sizePolicy3);
        Write_Angular_vel->setMaximumSize(QSize(71, 29));

        gridLayout_13->addWidget(Write_Angular_vel, 6, 1, 1, 1);

        Set_Angular_vel = new QPushButton(layoutWidget_5);
        Set_Angular_vel->setObjectName(QString::fromUtf8("Set_Angular_vel"));
        sizePolicy3.setHeightForWidth(Set_Angular_vel->sizePolicy().hasHeightForWidth());
        Set_Angular_vel->setSizePolicy(sizePolicy3);

        gridLayout_13->addWidget(Set_Angular_vel, 6, 2, 1, 1);

        tabWidget->addTab(tab_Autonomous, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 629, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217/\321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270 V0", nullptr));
        button_sin_025->setText(QCoreApplication::translate("MainWindow", "0.25 \320\223\321\206", nullptr));
        button_sin_05->setText(QCoreApplication::translate("MainWindow", "0.5 \320\223\321\206", nullptr));
        button_sin_1->setText(QCoreApplication::translate("MainWindow", "1 \320\223\321\206", nullptr));
        button_sin_2->setText(QCoreApplication::translate("MainWindow", "2\320\223\321\206", nullptr));
        button_sin_3->setText(QCoreApplication::translate("MainWindow", "3\320\223\321\206", nullptr));
        pushButton_Set_angle->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260", nullptr));
        pushButton_Set_angle_2->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274", nullptr));
        radioButton_disabled_mode->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\272\320\273\321\216\321\207\320\265\320\275", nullptr));
        radioButton_static_mode->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217", nullptr));
        radioButton_speed_mode->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270", nullptr));
        radioButton_sine_mode->setText(QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\241\320\273\320\276\320\266\320\275\321\213\320\265 \321\200\320\265\320\266\320\270\320\274\321\213, \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 (\320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\262 \320\240\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\275\321\213\320\265)</p></body></html>", nullptr));
        radioButton_SmoothMode->setText(QCoreApplication::translate("MainWindow", "\320\234\321\217\320\263\320\272\320\270\320\271 \320\277\321\203\321\201\320\272/\321\201\321\202\320\276\320\277", nullptr));
        radioButton_TrajectoryMode->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 \321\202\321\200\320\260\320\265\320\272\321\202\320\276\321\200\320\270\320\270", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\241\320\273\320\276\320\266\320\275\321\213\320\265 \321\200\320\265\320\266\320\270\320\274\321\213, \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201 \320\272\320\276\320\275\321\202\321\200\320\276\320\273\320\273\320\265\321\200\320\260 (\320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\262 \320\220\320\262\321\202\320\276\320\275\320\276\320\274\320\275\321\213\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270)</p></body></html>", nullptr));
        radioButton_SmoothMode_Autonomous->setText(QCoreApplication::translate("MainWindow", "\320\234\321\217\320\263\320\272\320\270\320\271 \320\277\321\203\321\201\320\272/\321\201\321\202\320\276\320\277", nullptr));
        radioButton_TrajectoryMode_Autonomous->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 \321\202\321\200\320\260\320\265\320\272\321\202\320\276\321\200\320\270\320\270", nullptr));
        radioButton_path_mode_Autonomous->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 \320\277\321\203\321\202\320\270", nullptr));
        ConnectBtn->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Serial Connection", nullptr));
        udpConnectButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "UDP Connection", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStandOps), QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\213\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\320\230\320\224-\321\200\320\265\320\263\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Kp", nullptr));
        Kp_text->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt;\">0.3</span></p></body></html>", nullptr));
        write_Kp->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Ki", nullptr));
        Ki_text->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt;\">0.0002</span></p></body></html>", nullptr));
        write_Ki->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Kd", nullptr));
        Kd_text->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt;\">50</span></p></body></html>", nullptr));
        write_Kd->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264", nullptr));
        WriteTime->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">3.00</span></p></body></html>", nullptr));
        SmoothModeEnabled->setText(QCoreApplication::translate("MainWindow", "\320\222\320\272\320\273", nullptr));
        SmoothModeDisabled->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273", nullptr));
        SetTime->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217\n"
"\321\200\320\260\320\261\320\276\321\202\321\213, \321\201", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\237\320\273\320\260\320\262\320\275\321\213\320\271 \320\277\321\203\321\201\320\272/\321\202\320\276\321\200\320\274\320\276\320\267", nullptr));
        WriteFunc_7->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\224\320\276\320\277. \321\204\321\203\320\275\320\272\321\206\320\270\321\217, \321\203\320\272\320\260\320\266\320\270\321\202\320\265 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0  </span><span style=\" font-family:'MS Shell Dlg 2';\">\320\270 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1</span></p></body></html>", nullptr));
        WriteFunc_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\224\320\276\320\277. \321\204\321\203\320\275\320\272\321\206\320\270\321\217, \321\203\320\272\320\260\320\266\320\270\321\202\320\265 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0  </span><span style=\" font-family:'MS Shell Dlg 2';\">\320\270 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1</span></p></body></html>", nullptr));
        WriteFunc_6->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\224\320\276\320\277. \321\204\321\203\320\275\320\272\321\206\320\270\321\217, \321\203\320\272\320\260\320\266\320\270\321\202\320\265 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0  </span><span style=\" font-family:'MS Shell Dlg 2';\">\320\270 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1</span></p></body></html>", nullptr));
        FuncModeDisabled->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273", nullptr));
        WriteFunc_8->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\224\320\276\320\277. \321\204\321\203\320\275\320\272\321\206\320\270\321\217, \321\203\320\272\320\260\320\266\320\270\321\202\320\265 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0  </span><span style=\" font-family:'MS Shell Dlg 2';\">\320\270 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1</span></p></body></html>", nullptr));
        WriteTime_10->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t7</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        FuncModeEnabled->setText(QCoreApplication::translate("MainWindow", "\320\222\320\272\320\273", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\320\276\320\275 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270 \320\276\321\202 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        WriteFunc->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\236\321\201\320\275\320\276\320\262\320\275\320\260\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\321\217</span></p></body></html>", nullptr));
        WriteFunc_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\224\320\276\320\277. \321\204\321\203\320\275\320\272\321\206\320\270\321\217, \321\203\320\272\320\260\320\266\320\270\321\202\320\265 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0  </span><span style=\" font-family:'MS Shell Dlg 2';\">\320\270 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1</span></p></body></html>", nullptr));
        WriteFunc_9->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\224\320\276\320\277. \321\204\321\203\320\275\320\272\321\206\320\270\321\217, \321\203\320\272\320\260\320\266\320\270\321\202\320\265 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0  </span><span style=\" font-family:'MS Shell Dlg 2';\">\320\270 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1</span></p></body></html>", nullptr));
        WriteFunc_5->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\224\320\276\320\277. \321\204\321\203\320\275\320\272\321\206\320\270\321\217, \321\203\320\272\320\260\320\266\320\270\321\202\320\265 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0  </span><span style=\" font-family:'MS Shell Dlg 2';\">\320\270 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1</span></p></body></html>", nullptr));
        WriteFunc_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\224\320\276\320\277. \321\204\321\203\320\275\320\272\321\206\320\270\321\217, \321\203\320\272\320\260\320\266\320\270\321\202\320\265 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0  </span><span style=\" font-family:'MS Shell Dlg 2';\">\320\270 t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1</span></p></body></html>", nullptr));
        WriteTime_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1 </span><span style=\" font-family:'MS Shell Dlg 2';\">= </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">\342\210\236</span></p></body></html>", nullptr));
        WriteTime_5->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t1</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_13->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t2</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_6->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t3</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_7->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t4</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_8->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t5</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_9->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t6</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_11->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t8</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_12->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t1</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_14->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t2</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_15->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t3</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_16->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t4</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_17->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t5</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_18->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t6</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_19->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t7</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_20->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t8</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">1 </span><span style=\" font-family:'MS Shell Dlg 2';\">- NO</span></p></body></html>", nullptr));
        WriteTime_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">t</span><span style=\" font-family:'MS Shell Dlg 2'; vertical-align:sub;\">0 </span><span style=\" font-family:'MS Shell Dlg 2';\">= 0</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:400;\">\320\235\320\260\321\207\320\260\320\273\320\276 \320\270 \320\272\320\276\320\275\320\265\321\206 \320\276\321\201\320\275\320\276\320\262\320\275\320\276\320\263\320\276 \320\277\320\265\321\200\320\270\320\276\320\264\320\260:</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabEmbedOps), QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\275\321\213\320\265", nullptr));
        pushButtonResetPlot->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        savePlotToFile->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButtonStartSaveToFile->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214 \320\262 \321\204\320\260\320\271\320\273", nullptr));
        plot_graphic->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\320\265 \320\263\321\200\320\260\321\204\320\270\320\272\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGraph), QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272", nullptr));
        SmoothAutonomousEnabled->setText(QCoreApplication::translate("MainWindow", "\320\222\320\272\320\273", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\226\320\265\320\273\320\260\320\265\320\274\320\260\321\217 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\237\320\273\320\260\320\262\320\275\320\276\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270 ", nullptr));
        Set_Desired_Time->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264", nullptr));
        Write_Desired_Time->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">3.00</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217\n"
"\320\277\320\265\321\200\320\265\321\205\320\276\320\264\320\260, \321\201", nullptr));
        SmoothAutonomousDisabled->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273", nullptr));
        Write_Desired_Velocity->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">0.50</span></p></body></html>", nullptr));
        Set_Desired_Velocity->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264", nullptr));
        PathModeEnabled->setText(QCoreApplication::translate("MainWindow", "\320\222\320\272\320\273", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\273\320\276\320\262\320\260\321\217 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 \320\277\321\203\321\202\320\270 (\320\270\320\274\320\270\321\202\320\260\321\206\320\270\321\217 Rpi \320\264\320\273\321\217 STMF103)", nullptr));
        Set_Linear_vel->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264", nullptr));
        Write_Linear_vel->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">0.50</span></p></body></html>", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\233\320\270\320\275\320\265\320\271\320\275\320\260\321\217 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214</p></body></html>", nullptr));
        PathModeDisabled->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273", nullptr));
        Write_Angular_vel->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">0.50</span></p></body></html>", nullptr));
        Set_Angular_vel->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Autonomous), QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\275\320\276\320\274\320\275\321\213\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
