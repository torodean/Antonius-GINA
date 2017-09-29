//==========================================================================
// GINA (Generations of Implanted Nuclear Atrophy)
// Michigan State University - National Superconducting Cylotron Laboratory
// File: gina.h
// Created By: Antonius Torode
// File Created: June 22, 2017
// Purpose: This file is the header file corresponding to gina.cpp
//==========================================================================

#ifndef GINA_H
#define GINA_H

#include <QMainWindow>
#include <QString>
#include <vector>

namespace Ui {
class GINA;
}

class GINA : public QMainWindow
{
    Q_OBJECT

public:
    explicit GINA(QWidget *parent = 0);
    std::int8_t getxTicks();
    std::int8_t getyTicks();
    ~GINA();

private slots:
    //Performs actions when interacting with the main window.
    void on_Analyze_clicked();
    void on_Reset_clicked();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_actionInfo_triggered();
    void on_actionInfo_Advanced_triggered();
    void on_actionHide_Graphs_triggered();
    void on_actionAnalyze_triggered();
    void on_actionReset_triggered();
    void on_action3_3_triggered();
    void on_action7_2_triggered();
    void on_action9_2_triggered();
    void on_action11_2_triggered();
    void on_action5_default_2_triggered();
    void on_action3_2_triggered();
    void on_action7_triggered();
    void on_action9_triggered();
    void on_action11_triggered();
    void on_action5_default_triggered();
    void on_actionPrint_Data_triggered();
    void on_actionSet_To_Default_triggered();
    void on_actionClear_Debug_Window_triggered();
    void on_Gen1Input_textChanged(const QString &arg1);
    void on_Gen2Input_textChanged(const QString &arg1);
    void on_Gen0Input_textChanged(const QString &arg1);

    void uncheckX();
    void uncheckY();

    //Performs calculations for analysis of data.
    void Decay(int decays, std::vector<double> hl, long rate, long time, double increment);
    void printDataToWindow(std::vector< std::vector<double>> N,std::vector< std::vector<double>> D,std::vector< std::vector<double>> CLH,std::vector<double> t, int decays, long arraySlots);
    void displayData(std::vector< std::vector<double>> N,std::vector< std::vector<double>> D,std::vector< std::vector<double>> CLH,std::vector<double> t);

    void addToWindow(QString text);

    void on_Save_Window_Text_clicked();

    void on_Save_Analysis_clicked();

private:
    Ui::GINA *ui;

    //Stores the default input values.
    QString defaultGen0Input;
    QString defaultGen1Input;
    QString defaultGen2Input;
    QString defaultGen3Input;
    QString defaultGen0NucleiInput;
    QString defaultGen1NucleiInput;
    QString defaultGen2NucleiInput;
    QString defaultGen3NucleiInput;
    QString defaultRateInput;
    QString defaultRunTimeInput;
    QString defaultIncrementInput;

    bool printData;
    bool hideGraphs;

    std::int8_t xTicks;
    std::int8_t yTicks;
    QString processText;
    QString analysisPath;
    QString analysisText;

    //Gather's entered values for external classes to use.
    QString returnGen0NucleiInput();
    QString returnGen1NucleiInput();
    QString returnGen2NucleiInput();
    QString returnGen3NucleiInput();
    QString returnGen0Input();
    QString returnGen1Input();
    QString returnGen2Input();
    QString returnGen3Input();
    QString VERSION;
};

#endif // GINA_H
