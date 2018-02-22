/********************************************************************************
** Form generated from reading UI file 'gina.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GINA_H
#define UI_GINA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GINA
{
public:
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionReset;
    QAction *actionAnalyze;
    QAction *actionClear_Debug_Window;
    QAction *action3;
    QAction *action3_2;
    QAction *action5_default;
    QAction *action7;
    QAction *action9;
    QAction *action11;
    QAction *action3_3;
    QAction *action5_default_2;
    QAction *action7_2;
    QAction *action9_2;
    QAction *action11_2;
    QAction *actionSet_To_Default;
    QAction *actionInfo;
    QAction *actionPrint_Data;
    QAction *actionInfo_Advanced;
    QAction *actionHide_Graphs;
    QAction *actionFit_Decay_Curve;
    QWidget *centralWidget;
    QPushButton *Analyze;
    QPushButton *Reset;
    QLineEdit *RunTimeInput;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *RateInput;
    QLineEdit *Gen0Input;
    QLineEdit *Gen1Input;
    QLineEdit *Gen3Input;
    QLineEdit *Gen2Input;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *IncrementInput;
    QProgressBar *progressBar;
    QTextEdit *output;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *Gen0Input_Nuclei;
    QLineEdit *Gen1Input_Nuclei;
    QLineEdit *Gen2Input_Nuclei;
    QLineEdit *Gen3Input_Nuclei;
    QLabel *bottom_label;
    QPushButton *Save_Window_Text;
    QPushButton *Save_Analysis;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QMenu *menuGraph_Settings;
    QMenu *menuSet_X_Ticks;
    QMenu *menuSet_Y_Ticks;
    QMenu *menuOptions;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GINA)
    {
        if (GINA->objectName().isEmpty())
            GINA->setObjectName(QStringLiteral("GINA"));
        GINA->resize(1202, 452);
        actionExit = new QAction(GINA);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionHelp = new QAction(GINA);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout = new QAction(GINA);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionReset = new QAction(GINA);
        actionReset->setObjectName(QStringLiteral("actionReset"));
        actionAnalyze = new QAction(GINA);
        actionAnalyze->setObjectName(QStringLiteral("actionAnalyze"));
        actionClear_Debug_Window = new QAction(GINA);
        actionClear_Debug_Window->setObjectName(QStringLiteral("actionClear_Debug_Window"));
        action3 = new QAction(GINA);
        action3->setObjectName(QStringLiteral("action3"));
        action3_2 = new QAction(GINA);
        action3_2->setObjectName(QStringLiteral("action3_2"));
        action3_2->setCheckable(true);
        action5_default = new QAction(GINA);
        action5_default->setObjectName(QStringLiteral("action5_default"));
        action5_default->setCheckable(true);
        action5_default->setChecked(true);
        action7 = new QAction(GINA);
        action7->setObjectName(QStringLiteral("action7"));
        action7->setCheckable(true);
        action9 = new QAction(GINA);
        action9->setObjectName(QStringLiteral("action9"));
        action9->setCheckable(true);
        action11 = new QAction(GINA);
        action11->setObjectName(QStringLiteral("action11"));
        action11->setCheckable(true);
        action3_3 = new QAction(GINA);
        action3_3->setObjectName(QStringLiteral("action3_3"));
        action3_3->setCheckable(true);
        action5_default_2 = new QAction(GINA);
        action5_default_2->setObjectName(QStringLiteral("action5_default_2"));
        action5_default_2->setCheckable(true);
        action5_default_2->setChecked(true);
        action7_2 = new QAction(GINA);
        action7_2->setObjectName(QStringLiteral("action7_2"));
        action7_2->setCheckable(true);
        action9_2 = new QAction(GINA);
        action9_2->setObjectName(QStringLiteral("action9_2"));
        action9_2->setCheckable(true);
        action11_2 = new QAction(GINA);
        action11_2->setObjectName(QStringLiteral("action11_2"));
        action11_2->setCheckable(true);
        action11_2->setChecked(false);
        actionSet_To_Default = new QAction(GINA);
        actionSet_To_Default->setObjectName(QStringLiteral("actionSet_To_Default"));
        actionInfo = new QAction(GINA);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        actionPrint_Data = new QAction(GINA);
        actionPrint_Data->setObjectName(QStringLiteral("actionPrint_Data"));
        actionPrint_Data->setCheckable(true);
        actionPrint_Data->setChecked(true);
        actionInfo_Advanced = new QAction(GINA);
        actionInfo_Advanced->setObjectName(QStringLiteral("actionInfo_Advanced"));
        actionHide_Graphs = new QAction(GINA);
        actionHide_Graphs->setObjectName(QStringLiteral("actionHide_Graphs"));
        actionHide_Graphs->setCheckable(true);
        actionFit_Decay_Curve = new QAction(GINA);
        actionFit_Decay_Curve->setObjectName(QStringLiteral("actionFit_Decay_Curve"));
        centralWidget = new QWidget(GINA);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Analyze = new QPushButton(centralWidget);
        Analyze->setObjectName(QStringLiteral("Analyze"));
        Analyze->setGeometry(QRect(20, 330, 101, 25));
        Reset = new QPushButton(centralWidget);
        Reset->setObjectName(QStringLiteral("Reset"));
        Reset->setGeometry(QRect(130, 330, 131, 25));
        RunTimeInput = new QLineEdit(centralWidget);
        RunTimeInput->setObjectName(QStringLiteral("RunTimeInput"));
        RunTimeInput->setGeometry(QRect(90, 54, 111, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 71, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 60, 16, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 130, 81, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 130, 61, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 26, 81, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(210, 26, 31, 17));
        RateInput = new QLineEdit(centralWidget);
        RateInput->setObjectName(QStringLiteral("RateInput"));
        RateInput->setGeometry(QRect(90, 20, 111, 31));
        Gen0Input = new QLineEdit(centralWidget);
        Gen0Input->setObjectName(QStringLiteral("Gen0Input"));
        Gen0Input->setGeometry(QRect(110, 150, 101, 31));
        Gen1Input = new QLineEdit(centralWidget);
        Gen1Input->setObjectName(QStringLiteral("Gen1Input"));
        Gen1Input->setGeometry(QRect(110, 180, 101, 31));
        Gen3Input = new QLineEdit(centralWidget);
        Gen3Input->setObjectName(QStringLiteral("Gen3Input"));
        Gen3Input->setGeometry(QRect(110, 240, 101, 31));
        Gen2Input = new QLineEdit(centralWidget);
        Gen2Input->setObjectName(QStringLiteral("Gen2Input"));
        Gen2Input->setGeometry(QRect(110, 210, 101, 31));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 160, 81, 17));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 190, 91, 17));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 220, 91, 17));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 250, 91, 17));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 280, 221, 41));
        label_11->setTextFormat(Qt::AutoText);
        label_11->setScaledContents(true);
        label_11->setWordWrap(true);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 96, 81, 17));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(210, 96, 16, 17));
        IncrementInput = new QLineEdit(centralWidget);
        IncrementInput->setObjectName(QStringLiteral("IncrementInput"));
        IncrementInput->setGeometry(QRect(90, 90, 111, 31));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 360, 241, 23));
        progressBar->setValue(0);
        output = new QTextEdit(centralWidget);
        output->setObjectName(QStringLiteral("output"));
        output->setGeometry(QRect(300, 50, 891, 331));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        output->setFont(font);
        output->setReadOnly(true);
        output->setAcceptRichText(true);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(300, 20, 891, 20));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(230, 130, 51, 17));
        Gen0Input_Nuclei = new QLineEdit(centralWidget);
        Gen0Input_Nuclei->setObjectName(QStringLiteral("Gen0Input_Nuclei"));
        Gen0Input_Nuclei->setGeometry(QRect(220, 150, 71, 31));
        Gen1Input_Nuclei = new QLineEdit(centralWidget);
        Gen1Input_Nuclei->setObjectName(QStringLiteral("Gen1Input_Nuclei"));
        Gen1Input_Nuclei->setGeometry(QRect(220, 180, 71, 31));
        Gen2Input_Nuclei = new QLineEdit(centralWidget);
        Gen2Input_Nuclei->setObjectName(QStringLiteral("Gen2Input_Nuclei"));
        Gen2Input_Nuclei->setGeometry(QRect(220, 210, 71, 31));
        Gen3Input_Nuclei = new QLineEdit(centralWidget);
        Gen3Input_Nuclei->setObjectName(QStringLiteral("Gen3Input_Nuclei"));
        Gen3Input_Nuclei->setGeometry(QRect(220, 240, 71, 31));
        bottom_label = new QLabel(centralWidget);
        bottom_label->setObjectName(QStringLiteral("bottom_label"));
        bottom_label->setGeometry(QRect(300, 380, 891, 20));
        bottom_label->setFont(font);
        Save_Window_Text = new QPushButton(centralWidget);
        Save_Window_Text->setObjectName(QStringLiteral("Save_Window_Text"));
        Save_Window_Text->setGeometry(QRect(940, 10, 141, 25));
        Save_Analysis = new QPushButton(centralWidget);
        Save_Analysis->setObjectName(QStringLiteral("Save_Analysis"));
        Save_Analysis->setGeometry(QRect(1090, 10, 101, 25));
        GINA->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GINA);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1202, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuGraph_Settings = new QMenu(menuEdit);
        menuGraph_Settings->setObjectName(QStringLiteral("menuGraph_Settings"));
        menuSet_X_Ticks = new QMenu(menuGraph_Settings);
        menuSet_X_Ticks->setObjectName(QStringLiteral("menuSet_X_Ticks"));
        menuSet_Y_Ticks = new QMenu(menuGraph_Settings);
        menuSet_Y_Ticks->setObjectName(QStringLiteral("menuSet_Y_Ticks"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        GINA->setMenuBar(menuBar);
        statusBar = new QStatusBar(GINA);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GINA->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionInfo);
        menuHelp->addAction(actionInfo_Advanced);
        menuEdit->addAction(actionReset);
        menuEdit->addAction(actionAnalyze);
        menuEdit->addAction(actionClear_Debug_Window);
        menuEdit->addAction(menuGraph_Settings->menuAction());
        menuGraph_Settings->addAction(menuSet_X_Ticks->menuAction());
        menuGraph_Settings->addAction(menuSet_Y_Ticks->menuAction());
        menuGraph_Settings->addAction(actionSet_To_Default);
        menuSet_X_Ticks->addAction(action3_3);
        menuSet_X_Ticks->addAction(action5_default_2);
        menuSet_X_Ticks->addAction(action7_2);
        menuSet_X_Ticks->addAction(action9_2);
        menuSet_X_Ticks->addAction(action11_2);
        menuSet_Y_Ticks->addAction(action3_2);
        menuSet_Y_Ticks->addAction(action5_default);
        menuSet_Y_Ticks->addAction(action7);
        menuSet_Y_Ticks->addAction(action9);
        menuSet_Y_Ticks->addAction(action11);
        menuOptions->addAction(actionPrint_Data);
        menuOptions->addAction(actionHide_Graphs);
        menuOptions->addAction(actionFit_Decay_Curve);

        retranslateUi(GINA);

        QMetaObject::connectSlotsByName(GINA);
    } // setupUi

    void retranslateUi(QMainWindow *GINA)
    {
        GINA->setWindowTitle(QApplication::translate("GINA", "GINA", Q_NULLPTR));
        actionExit->setText(QApplication::translate("GINA", "Exit", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("GINA", "Help", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("GINA", "About", Q_NULLPTR));
        actionReset->setText(QApplication::translate("GINA", "Reset", Q_NULLPTR));
        actionAnalyze->setText(QApplication::translate("GINA", "Analyze", Q_NULLPTR));
        actionClear_Debug_Window->setText(QApplication::translate("GINA", "Clear Debug Window", Q_NULLPTR));
        action3->setText(QApplication::translate("GINA", "3", Q_NULLPTR));
        action3_2->setText(QApplication::translate("GINA", "3", Q_NULLPTR));
        action5_default->setText(QApplication::translate("GINA", "5 (default)", Q_NULLPTR));
        action7->setText(QApplication::translate("GINA", "7", Q_NULLPTR));
        action9->setText(QApplication::translate("GINA", "9", Q_NULLPTR));
        action11->setText(QApplication::translate("GINA", "11", Q_NULLPTR));
        action3_3->setText(QApplication::translate("GINA", "3", Q_NULLPTR));
        action5_default_2->setText(QApplication::translate("GINA", "5 (default)", Q_NULLPTR));
        action7_2->setText(QApplication::translate("GINA", "7", Q_NULLPTR));
        action9_2->setText(QApplication::translate("GINA", "9", Q_NULLPTR));
        action11_2->setText(QApplication::translate("GINA", "11", Q_NULLPTR));
        actionSet_To_Default->setText(QApplication::translate("GINA", "Set To Default", Q_NULLPTR));
        actionInfo->setText(QApplication::translate("GINA", "Info", Q_NULLPTR));
        actionPrint_Data->setText(QApplication::translate("GINA", "Print Data", Q_NULLPTR));
        actionInfo_Advanced->setText(QApplication::translate("GINA", "Advanced Info", Q_NULLPTR));
        actionHide_Graphs->setText(QApplication::translate("GINA", "Hide Graphs", Q_NULLPTR));
        actionFit_Decay_Curve->setText(QApplication::translate("GINA", "Fit Decay Curve", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Analyze->setToolTip(QApplication::translate("GINA", "Analyzes the data over time.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        Analyze->setText(QApplication::translate("GINA", "Analyze", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Reset->setToolTip(QApplication::translate("GINA", "Resets the input fields to their default values.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        Reset->setText(QApplication::translate("GINA", "Reset to Default", Q_NULLPTR));
        RunTimeInput->setText(QApplication::translate("GINA", "100", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("GINA", "<html><head/><body><p>The run time is the total time that the GINA program will analyze the scenario for. This is also the x-axis maximum.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("GINA", "Run Time:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("GINA", "<html><head/><body><p>seconds</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("GINA", "s", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("GINA", "<html><head/><body><p><span style=\" color:#000000;\">The nuclear ion generations is incremented from 0 to n with 0 representing the primary ion, 1 representing the daughter ion, and so forth...</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("GINA", "Generation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("GINA", "<html><head/><body><p>The half life is the time it takes for a quantity of the respective nuclei to decay by a factor of one half. This field defaults to units of seconds but units may be entered as well. Valid units are seconds (sec), minutes (min), hours (hr), days (day), or years (yr). </p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("GINA", "Half-Life", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("GINA", "<html><head/><body><p>The input rate is the rate at which radioactive particles are being implanted.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("GINA", "Input Rate:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("GINA", "particles/second", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("GINA", "N/s", Q_NULLPTR));
        RateInput->setText(QApplication::translate("GINA", "100", Q_NULLPTR));
        Gen0Input->setText(QApplication::translate("GINA", "5.7", Q_NULLPTR));
        Gen1Input->setText(QApplication::translate("GINA", "32.6", Q_NULLPTR));
        Gen3Input->setText(QApplication::translate("GINA", "stable", Q_NULLPTR));
        Gen2Input->setText(QApplication::translate("GINA", "stable", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("GINA", "The mother nucleii are those being implanted on the target by the beam.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("GINA", "Mother (0):", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("GINA", "The daughter nuclei are those that the mother nuclei decay into.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("GINA", "Daughter (1):", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_9->setToolTip(QApplication::translate("GINA", "<html><head/><body><p>The grand-daughter nuclei are those that the daughter nuclei decay into.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_9->setText(QApplication::translate("GINA", "Grand-D (2):", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_10->setToolTip(QApplication::translate("GINA", "<html><head/><body><p>The great grand-daughter nuclei are those that the granddaughter nuclei decay into.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("GINA", "Great-GD (3):", Q_NULLPTR));
        label_11->setText(QApplication::translate("GINA", "*Note: 'stable' will assume the particle does not decay.", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_12->setToolTip(QApplication::translate("GINA", "<html><head/><body><p>The increment determines the step size for the GINA program to analyze a change in incoming particles. At each increment of time, each calculation is re-performed. Making this value smaller will increase the program speed but decrease data resolution.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_12->setText(QApplication::translate("GINA", "Increment:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_13->setToolTip(QApplication::translate("GINA", "seconds", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_13->setText(QApplication::translate("GINA", "s", Q_NULLPTR));
        IncrementInput->setText(QApplication::translate("GINA", "0.1", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_14->setToolTip(QApplication::translate("GINA", "Debugging Window mainly used for monitoring output during programming but kept since it contains useful information and messages.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_14->setText(QApplication::translate("GINA", "<html><head/><body><p align=\"center\">Debugging and Troubleshooting Window</p></body></html>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_15->setToolTip(QApplication::translate("GINA", "<html><head/><body><p>The Nuclear isotope corresponding to the specific generation.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_15->setText(QApplication::translate("GINA", "Isotope", Q_NULLPTR));
        Gen0Input_Nuclei->setText(QApplication::translate("GINA", "76Zn", Q_NULLPTR));
        Gen1Input_Nuclei->setText(QApplication::translate("GINA", "76Ga", Q_NULLPTR));
        Gen2Input_Nuclei->setText(QApplication::translate("GINA", "76Ge", Q_NULLPTR));
        Gen3Input_Nuclei->setText(QString());
#ifndef QT_NO_TOOLTIP
        bottom_label->setToolTip(QApplication::translate("GINA", "<html><head/><body><p>ID: The index of the element in each array where the data is stored.</p><p>Time: The total time at which the data was calculated at.</p><p>N0: The total number of implanted mother nuclei.</p><p>N1: The total number of implanted daughter nuclei.</p><p>N2: etc...</p><p>D0: The decays per second of the mother nuclei.</p><p>D1: The decays per second of the daughter nuclei.</p><p>D2: etc...</p><p>C: The contamination of the decays emmited.</p><p>L: The percent of implanted particles that are not the mother nuclei.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        bottom_label->setText(QString());
        Save_Window_Text->setText(QApplication::translate("GINA", "Save Window Text", Q_NULLPTR));
        Save_Analysis->setText(QApplication::translate("GINA", "Save Analysis", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("GINA", "File", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("GINA", "Help", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("GINA", "Program", Q_NULLPTR));
        menuGraph_Settings->setTitle(QApplication::translate("GINA", "Graph Settings", Q_NULLPTR));
        menuSet_X_Ticks->setTitle(QApplication::translate("GINA", "Set X Ticks", Q_NULLPTR));
        menuSet_Y_Ticks->setTitle(QApplication::translate("GINA", "Set Y Ticks", Q_NULLPTR));
        menuOptions->setTitle(QApplication::translate("GINA", "Advanced", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GINA: public Ui_GINA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GINA_H
