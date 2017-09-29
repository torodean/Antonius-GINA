//==========================================================================
// GINA (Generations of Implanted Nuclear Atrophy)
// Michigan State University - National Superconducting Cylotron Laboratory
// File: gina.cpp
// Created By: Antonius Torode
// File Created: June 22, 2017
// Purpose: This file contains the brains (calculations) of the GINA program.
//==========================================================================

#include <QtWidgets/QMainWindow>
#include <QWindow>
#include "gina.h"
#include "ui_gina.h"
#include "math.h"
#include "ginagraph.h"
#include "ginaelements.h"
#include <vector>
#include <QDir>
#include <QTextStream>
#include <QDateTime>

GINA::GINA(QWidget *parent) : QMainWindow(parent), ui(new Ui::GINA),
    defaultGen0Input("5.7"), defaultGen1Input("32.6"),
    defaultGen2Input("stable"), defaultGen3Input("stable"),
    defaultGen0NucleiInput("76Zn"), defaultGen1NucleiInput("76Ga"),
    defaultGen2NucleiInput("76Ge"), defaultGen3NucleiInput(""),
    defaultRateInput("100"), defaultRunTimeInput("100"),
    defaultIncrementInput("0.1"), printData(true), hideGraphs(false),
    xTicks(5), yTicks(5), processText(""), analysisPath("Analysis"), analysisText(""),

    //Update this version number when making changes.
    VERSION("1.017")
{
    ui->setupUi(this);

    //Creates an Analysis folder if it does not already exist.
    if(!QDir(QDir::currentPath() + "/" + analysisPath).exists()){
        QDir().mkdir(QDir::currentPath() + "/" + analysisPath);
    }
}

GINA::~GINA(){
    delete ui;
}

//When the Analyze button is clicked, begin analysis.
void GINA::on_Analyze_clicked(){
    GINAelements element;

    ui->progressBar->setValue(0);
    ui->output->append("\n~~~~~Analysis started~~~~~");

    //Gathers values input to the Qt Main window.
    ui->output->append("Gathering Input values...");
    QString Qrate = ui->RateInput->text();
    QString Qtime = ui->RunTimeInput->text();
    QString Qincrement = ui->IncrementInput->text();
    QString Qhl_0 = ui->Gen0Input->text();
    QString Qhl_1 = ui->Gen1Input->text();
    QString Qhl_2 = ui->Gen2Input->text();
    QString Qhl_3 = ui->Gen3Input->text();
    ui->output->append("Finished...");

    bool continueRun = true; //Set to false if one of the fields is stable.
    int numOfDecays = 4; //Defaults to all 4 fields not set to stable. Changes if one of them is stable.

    //Converts input values into types for performing calculations.
    ui->output->append("Converting Input values...");
    long rate = Qrate.toLong();
    long time = Qtime.toLong();
    double increment = Qincrement.toDouble();
    std::vector<double> hl(4);

    //Determines how many half-life fields are filled and converts the values to doubles.
    if(Qhl_0 != "stable"){ //The first half-life field is not stable.
        hl[0] = element.convertToSeconds(Qhl_0);
        ui->output->append("hl[0] set to " + QString::number(hl[0]) + " seconds"
                );
    } else {
        numOfDecays = 0;
        continueRun = false;
        ui->output->append("hl[0] set to stable");
        ui->output->append("hl[1] set to stable");
        ui->output->append("hl[2] set to stable");
        ui->output->append("hl[3] set to stable");
    }
    if(Qhl_1 != "stable" && continueRun){ //The second half-life field is not stable.
        hl[1] = element.convertToSeconds(Qhl_1);
        ui->output->append("hl[1] set to " + QString::number(hl[1]) + " seconds");
    } else  if (continueRun){
        numOfDecays = 1;
        continueRun = false;
        ui->output->append("hl[1] set to stable");
        ui->output->append("hl[2] set to stable");
        ui->output->append("hl[3] set to stable");
    }
    if(Qhl_2 != "stable" && continueRun){ //The third half-life field is not stable.
        hl[2] = element.convertToSeconds(Qhl_2);
        ui->output->append("hl[2] set to " + QString::number(hl[2]) + " seconds");
    } else if (continueRun){
        numOfDecays = 2;
        continueRun = false;
        ui->output->append("hl[2] set to stable");
        ui->output->append("hl[3] set to stable");
    }
    if(Qhl_3 != "stable" && continueRun){ //The fourth half-life field is not stable.
        hl[3] = element.convertToSeconds(Qhl_3);
        ui->output->append("hl[3] set to " + QString::number(hl[3]) + " seconds");
    } else if (continueRun){
        numOfDecays = 3;
        continueRun = false;
        ui->output->append("hl[3] set to stable");
    }

    Decay(numOfDecays, hl, rate, time, increment);
}

//Performs the calculations for the important things.
void GINA::Decay(int decays, std::vector<double> hl, long rate, long time, double increment){
    //Determines how many elements will be in arrays baed on total time and time increment.
    long arraySlots = time/increment + 1;

    //Declares initial variables and vectors for storing data/calculations.

    ui->output->append("Creating data arrays...");

    //ui->output->append("Creating particle number arrays...");
    std::vector< std::vector<double>> N(decays+1, std::vector<double>(arraySlots)); //N for particle number.
    //ui->output->append("Finished...");

    //ui->output->append("Creating decay number arrays...");
    std::vector< std::vector<double>> D(decays+1, std::vector<double>(arraySlots)); //D for decays per second
    //ui->output->append("Finished...");

    //ui->output->append("Creating CLH (Contamination[0], Loss[1], Health[2]) array...");
    std::vector<std::vector<double>> CLH(3,std::vector<double>(arraySlots)); //CLH - Contamination[0], Loss[1], Health[2]
    //ui->output->append("Finished...");

    //ui->output->append("Creating waste array...");
    //std::vector<double> W(arraySlots); //W for waste (for storing the nuclear particles that would be lost upon beam cutoff).
    //ui->output->append("Finished...");

    //ui->output->append("Creating time array...");
    std::vector<double> t(arraySlots);
    ui->output->append("Finished...");

    ui->output->append("Filling time array...");
    //Fill in the time array.
    for(long i=0;i<arraySlots;i++){
        t[i] = i*increment;
    }
    ui->output->append("Finished...");

    //Calculates particle numbers over time.
    ui->output->append("Calculating particle numbers over time...");
    if(decays == 0){
        N[0][0] = 0;
        N[0][1] = rate*increment;
        ui->output->append("Determined Zero Decays...");

        //Appropriate equations to match how many of the particles decay.
        for(long n=2;n<arraySlots;n++){
            N[0][n]=n*rate*increment;
        }
    } else if (decays == 1){
        N[0][0] = 0;
        N[0][1] = rate*increment;
        N[1][0] = 0;
        N[1][1] = 0;
        ui->output->append("Determined One Decay...");

        //Appropriate equations to match how many of the particles decay.
        for(long n=2;n<arraySlots;n++){
            N[0][n]=N[0][1]+N[0][n-1]*exp(-increment*log(2)/hl[0]);
            N[1][n]=N[1][n-1]+N[0][n-1]*(1-exp(-increment*log(2)/hl[0]));
        }
    } else if (decays == 2){
        N[0][0] = 0;
        N[0][1] = rate*increment;
        N[1][0] = 0;
        N[1][1] = 0;
        N[2][0] = 0;
        N[2][1] = 0;
        ui->output->append("Determined Two Decays...");

        //Appropriate equations to match how many of the particles decay.
        for(long n=2;n<arraySlots;n++){
            N[0][n]=N[0][1]+N[0][n-1]*exp(-increment*log(2)/hl[0]);
            N[1][n]=N[0][n-1]*(1-exp(-increment*log(2)/hl[0]))+N[1][n-1]*exp(-increment*log(2)/hl[1]);
            N[2][n]=N[2][n-1]+N[1][n-1]*(1-exp(-increment*log(2)/hl[1]));
        }
    } else if (decays == 3){
        N[0][0] = 0;
        N[0][1] = rate*increment;
        N[1][0] = 0;
        N[1][1] = 0;
        N[2][0] = 0;
        N[2][1] = 0;
        N[3][0] = 0;
        N[3][1] = 0;
        ui->output->append("Determined Three Decays...");

        //Appropriate equations to match how many of the particles decay.
        for(long n=2;n<arraySlots;n++){
            N[0][n]=N[0][1]+N[0][n-1]*exp(-increment*log(2)/hl[0]);
            N[1][n]=N[0][n-1]*(1-exp(-increment*log(2)/hl[0]))+N[1][n-1]*exp(-increment*log(2)/hl[1]);
            N[2][n]=N[1][n-1]*(1-exp(-increment*log(2)/hl[1]))+N[2][n-1]*exp(-increment*log(2)/hl[2]);
            N[3][n]=N[3][n-1]+N[2][n-1]*(1-exp(-increment*log(2)/hl[2]));
        }
    } else if (decays == 4){
        N[0][0] = 0;
        N[0][1] = rate*increment;
        N[1][0] = 0;
        N[1][1] = 0;
        N[2][0] = 0;
        N[2][1] = 0;
        N[3][0] = 0;
        N[3][1] = 0;
        N[4][0] = 0;
        N[4][1] = 0;
        ui->output->append("Determined Four Decays...");

        //Appropriate equations to match how many of the particles decay.
        for(long n=2;n<arraySlots;n++){
            N[0][n]=N[0][1]+N[0][n-1]*exp(-increment*log(2)/hl[0]);
            N[1][n]=N[0][n-1]*(1-exp(-increment*log(2)/hl[0]))+N[1][n-1]*exp(-increment*log(2)/hl[1]);
            N[2][n]=N[1][n-1]*(1-exp(-increment*log(2)/hl[1]))+N[2][n-1]*exp(-increment*log(2)/hl[2]);
            N[3][n]=N[2][n-1]*(1-exp(-increment*log(2)/hl[2]))+N[3][n-1]*exp(-increment*log(2)/hl[3]);
            N[4][n]=N[4][n-1]+N[3][n-1]*(1-exp(-increment*log(2)/hl[3]));
        }
    }
    ui->output->append("Finished...");

    if(printData){
        ui->progressBar->setValue(25);
    } else {
        ui->progressBar->setValue(33);
    }

    //Calculates particle number decay rate and CLH over time.
    ui->output->append("Calculating particle decay rates over time...");
    if(decays == 0){ //Calculations for when none of the implant decays.
        ui->output->append("Using Zero Decays...");

        //Appropriate equations to match how many of the particles decay.
        for(long n=0;n<arraySlots;n++){
            D[0][n]=0;

            //CLH calculation
            CLH[0][n] = 0;
            CLH[1][n] = 0;
            CLH[2][n] = 100;
        }
    } else if (decays == 1){ //Calculations for when only the mother ion decays.
        ui->output->append("Using One Decay...");

        //Appropriate equations to match how many of the particles decay.
        for(long n=0;n<arraySlots;n++){
            D[0][n]=N[0][n]*log(2)/hl[0];
            D[1][n]=0;

            //CLH calculation
            CLH[0][n] = 0;
            if(n>0){
                CLH[1][n] = 100*N[1][n]/(n*rate*increment);
            } else {
                CLH[1][n] = 0;
            }
            CLH[2][n] = 100-CLH[1][n];
        }
    } else if (decays == 2){ //Calculations for when the mother and daughter decay only.
        ui->output->append("Using Two Decays...");

        //Appropriate equations to match how many of the particles decay.
        for(long n=0;n<arraySlots;n++){
            D[0][n]=N[0][n]*log(2)/hl[0];
            D[1][n]=N[1][n]*log(2)/hl[1];
            D[2][n]=0;

            //CLH calculation
            if(D[0][n]>0){
                CLH[0][n] = D[1][n]/D[0][n]*100;
            }
            if(n>0){
                CLH[1][n] = 100*(N[1][n]+N[2][n])/(n*rate*increment);
            } else {
                CLH[1][n] = 0;
            }
            CLH[2][n] = 100-CLH[1][n];
        }
    } else if (decays == 3){ //Calculations for when 3 generations decay only.
        ui->output->append("Using Three Decays...");

        //Appropriate equations to match how many of the particles decay.
        for(long n=0;n<arraySlots;n++){
            D[0][n]=N[0][n]*log(2)/hl[0];
            D[1][n]=N[1][n]*log(2)/hl[1];
            D[2][n]=N[2][n]*log(2)/hl[2];
            D[3][n]=0;

            //CLH calculation
            if(D[0][n]>0){
                CLH[0][n] = (D[1][n]+D[2][n])/D[0][n]*100;
            }
            if(n>0){
                CLH[1][n] = 100*(N[1][n]+N[2][n]+N[3][n])/(n*rate*increment);
            } else {
                CLH[1][n] = 0;
            }
            CLH[2][n] = 100-CLH[1][n];
        }
    } else if (decays == 4){ //Calculations for when 4 generations decay only.
        ui->output->append("Using Four Decays...");

        //Appropriate equations to match how many of the particles decay.
        for(long n=2;n<arraySlots;n++){
            D[0][n]=N[0][n]*log(2)/hl[0];
            D[1][n]=N[1][n]*log(2)/hl[1];
            D[2][n]=N[2][n]*log(2)/hl[2];
            D[3][n]=N[3][n]*log(2)/hl[3];
            D[4][n]=0;

            //CLH calculation
            if(D[0][n]>0){
                CLH[0][n] = (D[1][n]+D[2][n]+D[3][n])/D[0][n]*100;
            }
            if(n>0){
                CLH[1][n] = 100*(N[1][n]+N[2][n]+N[3][n]+N[4][n])/(n*rate*increment);
            } else {
                CLH[1][n] = 0;
            }
            CLH[2][n] = 100-CLH[1][n];
        }
    }
    ui->output->append("Finished...");

    if(printData){
        ui->progressBar->setValue(50); //done with calculations

    } else {
        ui->progressBar->setValue(66); //done with calculations
    }

    if(printData){
        printDataToWindow(N,D,CLH,t,decays, arraySlots);
        ui->progressBar->setValue(75); //done with printing
    }

    processText = ui->Gen0Input_Nuclei->text() + " (" + ui->Gen0Input->text() + ") -> "
                  + ui->Gen1Input_Nuclei->text() + " (" + ui->Gen1Input->text() + ") -> "
                  + ui->Gen2Input_Nuclei->text() + " (" + ui->Gen2Input->text() + ") -> "
                  + ui->Gen3Input_Nuclei->text() + " (" + ui->Gen3Input->text() + ")";

    if(!hideGraphs){
        displayData(N,D,CLH,t); //plots the data
    }
    ui->progressBar->setValue(100); //Done with graphs
}

void GINA::printDataToWindow(std::vector< std::vector<double>> N,std::vector< std::vector<double>> D,std::vector< std::vector<double>> CLH,std::vector<double> t, int decays, long arraySlots){
    analysisText = "";

    if(decays == 0){
        QString dataHeader = "ID   Time    N0          C       L";
        QString dataOutput = "";
        ui->bottom_label->setText(dataHeader);
        analysisText = dataHeader + "\n";

        addToWindow(dataHeader);
        for(int i=0;i<arraySlots;i++){
            dataOutput = "";
            dataOutput += QString::number(i);
            dataOutput = dataOutput.leftJustified(4, ' ');
            dataOutput += "|";
            dataOutput += QString::number(t[i]);
            dataOutput = dataOutput.leftJustified(9, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[0][i]);
            dataOutput = dataOutput.leftJustified(17, ' ');
            dataOutput += "|";
            dataOutput += QString::number(CLH[0][i]);
            dataOutput = dataOutput.leftJustified(27, ' ');
            dataOutput += "|";
            dataOutput += QString::number(CLH[1][i]);

            addToWindow(dataOutput);
            analysisText += dataOutput + "\n";
        }
    } else if (decays == 1){
        QString dataHeader = "ID   Time    N0      N1      D0       C       L";
        QString dataOutput = "";
        ui->bottom_label->setText(dataHeader);
        analysisText = dataHeader + "\n";

        addToWindow(dataHeader);
        for(int i=0;i<arraySlots;i++){
            dataOutput = "";
            dataOutput += QString::number(i);
            dataOutput = dataOutput.leftJustified(4, ' ');
            dataOutput += "|";
            dataOutput += QString::number(t[i]);
            dataOutput = dataOutput.leftJustified(9, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[0][i]);
            dataOutput = dataOutput.leftJustified(17, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[1][i]);
            dataOutput = dataOutput.leftJustified(25, ' ');
            dataOutput += "|";
            dataOutput += QString::number(D[0][i]);
            dataOutput = dataOutput.leftJustified(33, ' ');
            dataOutput += "|";
            dataOutput += QString::number(CLH[0][i]);
            dataOutput = dataOutput.leftJustified(43, ' ');
            dataOutput += "|";
            dataOutput += QString::number(CLH[1][i]);

            addToWindow(dataOutput);
            analysisText += dataOutput + "\n";
        }
    } else if (decays == 2){
        QString dataHeader = "ID   Time    N0      N1        N2         D0       D1          C       L";
        QString dataOutput = "";
        ui->bottom_label->setText(dataHeader);
        analysisText = dataHeader + "\n";

        addToWindow(dataHeader);
        for(int i=0;i<arraySlots;i++){
            dataOutput = "";
            dataOutput += QString::number(i);
            dataOutput = dataOutput.leftJustified(4, ' ');
            dataOutput += "|";
            dataOutput += QString::number(t[i]);
            dataOutput = dataOutput.leftJustified(9, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[0][i]);
            dataOutput = dataOutput.leftJustified(17, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[1][i]);
            dataOutput = dataOutput.leftJustified(26, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[2][i]);
            dataOutput = dataOutput.leftJustified(38, ' ');
            dataOutput += "|";
            dataOutput += QString::number(D[0][i]);
            dataOutput = dataOutput.leftJustified(46, ' ');
            dataOutput += "|";
            dataOutput += QString::number(D[1][i]);
            dataOutput = dataOutput.leftJustified(57, ' ');
            dataOutput += "|";
            dataOutput += QString::number(CLH[0][i]);
            dataOutput = dataOutput.leftJustified(67, ' ');
            dataOutput += "|";
            dataOutput += QString::number(CLH[1][i]);

            addToWindow(dataOutput);
            analysisText += dataOutput + "\n";
        }
    } else if (decays == 3){
        QString dataHeader = "ID   Time    N0      N1      N2       N3        D0      D1        D2          C       L";
        QString dataOutput = "";
        ui->bottom_label->setText(dataHeader);
        analysisText = dataHeader + "\n";

        addToWindow(dataHeader);
        for(int i=0;i<arraySlots;i++){
            dataOutput = "";
            dataOutput += QString::number(i);
            dataOutput = dataOutput.leftJustified(4, ' ');
            dataOutput += "|";
            dataOutput += QString::number(t[i]);
            dataOutput = dataOutput.leftJustified(9, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[0][i]);
            dataOutput = dataOutput.leftJustified(17, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[1][i]);
            dataOutput = dataOutput.leftJustified(25, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[2][i]);
            dataOutput = dataOutput.leftJustified(35, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[3][i]);
            dataOutput = dataOutput.leftJustified(45, ' ');
            dataOutput += "|";
            dataOutput += QString::number(D[0][i]);
            dataOutput = dataOutput.leftJustified(53, ' ');
            dataOutput += "|";
            dataOutput += QString::number(D[1][i]);
            dataOutput = dataOutput.leftJustified(63, ' ');
            dataOutput += "|";
            dataOutput += QString::number(D[2][i]);
            dataOutput = dataOutput.leftJustified(74, ' ');
            dataOutput += "|";
            dataOutput += QString::number(CLH[0][i]);
            dataOutput = dataOutput.leftJustified(84, ' ');
            dataOutput += "|";
            dataOutput += QString::number(CLH[1][i]);

            addToWindow(dataOutput);
            analysisText += dataOutput + "\n";
        }
    } else if (decays == 4){
        QString dataHeader = "ID   Time    N0      N1      N2       N3        N4         D0      D1        D2        D3          C       L";
        QString dataOutput = "";
        ui->bottom_label->setText(dataHeader);
        analysisText = dataHeader + "\n";

        addToWindow(dataHeader);
        for(int i=0;i<arraySlots;i++){
            dataOutput = "";
            dataOutput += QString::number(i);
            dataOutput = dataOutput.leftJustified(4, ' ');
            dataOutput += "|";
            dataOutput += QString::number(t[i]);
            dataOutput = dataOutput.leftJustified(9, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[0][i]);
            dataOutput = dataOutput.leftJustified(17, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[1][i]);
            dataOutput = dataOutput.leftJustified(25, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[2][i]);
            dataOutput = dataOutput.leftJustified(35, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[3][i]);
            dataOutput = dataOutput.leftJustified(45, ' ');
            dataOutput += "|";
            dataOutput += QString::number(N[4][i]);
            dataOutput = dataOutput.leftJustified(55, ' ');
            dataOutput += "|";
            dataOutput += QString::number(D[0][i]);
            dataOutput = dataOutput.leftJustified(63, ' ');
            dataOutput += "|";
            dataOutput += QString::number(D[1][i]);
            dataOutput = dataOutput.leftJustified(73, ' ');
            dataOutput += "|";
            dataOutput += QString::number(D[2][i]);
            dataOutput = dataOutput.leftJustified(84, ' ');
            dataOutput += "|";
            dataOutput += QString::number(D[3][i]);
            dataOutput = dataOutput.leftJustified(95, ' ');
            dataOutput += "|";
            dataOutput += QString::number(CLH[0][i]);
            dataOutput = dataOutput.leftJustified(105, ' ');
            dataOutput += "|";
            dataOutput += QString::number(CLH[1][i]);

            addToWindow(dataOutput);
            analysisText += dataOutput + "\n";
        }
    }
}

//Creates a GinaGraph window and plots the data.
void GINA::displayData(std::vector< std::vector<double>> N,std::vector< std::vector<double>> D,std::vector< std::vector<double>> CLH,std::vector<double> t){
    //Draw Plots
    ui->output->append("Drawing plots...");

    GinaGraph *graph = new GinaGraph(N,D,CLH,t,xTicks,yTicks,processText);
    graph->resize(1000,400);

    //Gives the window an appropriate title
    QString title = "GINA Analysis: "
            + ui->Gen0Input_Nuclei->text() + " (" + ui->Gen0Input->text() + ") -> "
            + ui->Gen1Input_Nuclei->text() + " (" + ui->Gen1Input->text() + ") -> "
            + ui->Gen2Input_Nuclei->text() + " (" + ui->Gen2Input->text() + ") -> "
            + ui->Gen3Input_Nuclei->text() + " (" + ui->Gen3Input->text() + ")";
    graph->setWindowTitle(title);

    graph->show();
    ui->output->append("Finished...");
}

//Resets the fields to their default values.
void GINA::on_Reset_clicked(){
    ui->Gen0Input->setText(defaultGen0Input);
    ui->Gen1Input->setText(defaultGen1Input);
    ui->Gen2Input->setText(defaultGen2Input);
    ui->Gen3Input->setText(defaultGen3Input);
    ui->RateInput->setText(defaultRateInput);
    ui->Gen0Input_Nuclei->setText(defaultGen0NucleiInput);
    ui->Gen1Input_Nuclei->setText(defaultGen1NucleiInput);
    ui->Gen2Input_Nuclei->setText(defaultGen2NucleiInput);
    ui->Gen3Input_Nuclei->setText(defaultGen3NucleiInput);
    ui->RunTimeInput->setText(defaultRunTimeInput);
    ui->IncrementInput->setText(defaultIncrementInput);
    ui->progressBar->setValue(0);
    ui->output->append("Reset all fields to their default values.");
}

//Exits the program if exit is clicked.
void GINA::on_actionExit_triggered(){
    qApp->quit();
}

//If the first input is set to stable then the others are also.
void GINA::on_Gen0Input_textChanged(const QString &arg1){
    if(arg1 == "stable"){
        ui->Gen1Input->setText("stable");
        ui->Gen2Input->setText("stable");
        ui->Gen3Input->setText("stable");
        ui->Gen1Input_Nuclei->clear();
        ui->Gen2Input_Nuclei->clear();
        ui->Gen3Input_Nuclei->clear();
    }
}

//If the second input is set to stable then the last two are also.
void GINA::on_Gen1Input_textChanged(const QString &arg1){
    if(arg1 == "stable"){
        ui->Gen2Input->setText("stable");
        ui->Gen3Input->setText("stable");
        ui->Gen2Input_Nuclei->clear();
        ui->Gen3Input_Nuclei->clear();
    }
}

//If the third input is set to stable then the last is also.
void GINA::on_Gen2Input_textChanged(const QString &arg1){
    if(arg1 == "stable"){
        ui->Gen3Input->setText("stable");
        ui->Gen3Input_Nuclei->clear();
    }
}

//When the About button is clicked, display GINA information.
void GINA::on_actionAbout_triggered(){
    ui->output->append("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    ui->output->append("GINA (Generations of Implanted Nuclear Atrophy)");
    ui->output->append("Release version " + VERSION);
    ui->output->append("Author: Antonius Torode");
    ui->output->append("  Michigan State University");
    ui->output->append("  National Superconducting Cyclotron Laboratory");
    ui->output->append("  SuN Data Group");
    ui->output->append("Created: June 2017");
    ui->output->append("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

//When the Info button is clicked, display useful GINA information.
void GINA::on_actionInfo_triggered(){
    ui->output->append("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    ui->output->append("GINA (Generations of Implanted Nuclear Atrophy)");
    ui->output->append("-----------------------------------------------");
    ui->output->append("The nuclear ion generations is incremented from 0 to n with 0 representing the primary ion, 1 representing the daughter ion, and so forth...");
    ui->output->append("-----------------------------------------------");
    ui->output->append(" -- Nuclei Count: These are the total number of each ion present on the target after a certain amount of time.");
    ui->output->append("-----------------------------------------------");
    ui->output->append(" -- Decay rates: These are the total decays per second that each ion is undergoing.");
    ui->output->append("-----------------------------------------------");
    ui->output->append(" -- Contamination: This represents the total contamination of primary ion decays with respect to the other ions decaying.");
    ui->output->append("-----------------------------------------------");
    ui->output->append(" -- Loss: This shows the percentage of the implanted ions that are not of the primary ion.");
    ui->output->append("-----------------------------------------------");
    ui->output->append(" -- Health: This shows the percentage of the implanted ions that are of the primary ion.");
    ui->output->append("-----------------------------------------------");
    ui->output->append("To change graph settings and display, go to program > Graph Settings.");
    ui->output->append("-----------------------------------------------");
    ui->output->append("Hover over any label to get extended tool-tip information about the field.");
    ui->output->append("-----------------------------------------------");
    ui->output->append("For extended explanations and derivations of the equations used, see the program documentation.");
    ui->output->append("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

//When the Advanced Info button is clicked, display useful Advanced GINA information.
void GINA::on_actionInfo_Advanced_triggered(){
    ui->output->append("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    ui->output->append("GINA (Generations of Implanted Nuclear Atrophy)");
    ui->output->append("-----------------------------------------------");
    ui->output->append(" -- The advanced > Show Data feature determines whether data is printed to the debugger window.");
    ui->output->append(" -- Disabling this option will speed up the creation of the graphs but provide less information.");
    ui->output->append("-----------------------------------------------");
    ui->output->append(" -- The advanced > Hide Graphs feature determines whether graphs are produced by GINA upon analysis.");
    ui->output->append("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}


//When Analyze is clicked through the menu bar.
void GINA::on_actionAnalyze_triggered(){
    on_Analyze_clicked();
}

//When Reset is clicked through the menu bar.
void GINA::on_actionReset_triggered(){
    on_Reset_clicked();
}

//When Clear Debug Window is clicked through the menu bar.
void GINA::on_actionClear_Debug_Window_triggered(){
    ui->output->clear();
    ui->bottom_label->clear();
}

void GINA::on_action3_3_triggered(){
    xTicks = 3;
    uncheckX();
    ui->action3_3->setChecked(true);
}

void GINA::on_action7_2_triggered(){
    xTicks = 7;
    uncheckX();
    ui->action7_2->setChecked(true);
}

void GINA::on_action9_2_triggered(){
    xTicks = 9;
    uncheckX();
    ui->action9_2->setChecked(true);
}

void GINA::on_action11_2_triggered(){
    xTicks = 11;
    uncheckX();
    ui->action11_2->setChecked(true);
}

void GINA::on_action5_default_2_triggered(){
    xTicks = 5;
    uncheckX();
    ui->action5_default_2->setChecked(true);
}

std::int8_t GINA::getxTicks(){
    return xTicks;
}

std::int8_t GINA::getyTicks(){
    return yTicks;
}

void GINA::uncheckX(){
    ui->action5_default_2->setChecked(false);
    ui->action3_3->setChecked(false);
    ui->action7_2->setChecked(false);
    ui->action9_2->setChecked(false);
    ui->action11_2->setChecked(false);

}

void GINA::uncheckY(){
    ui->action5_default->setChecked(false);
    ui->action3_2->setChecked(false);
    ui->action7->setChecked(false);
    ui->action9->setChecked(false);
    ui->action11->setChecked(false);

}

void GINA::on_action3_2_triggered(){
    yTicks = 3;
    uncheckY();
    ui->action3_2->setChecked(true);
}

void GINA::on_action7_triggered(){
    yTicks = 7;
    uncheckY();
    ui->action7->setChecked(true);
}

void GINA::on_action9_triggered(){
    yTicks = 9;
    uncheckY();
    ui->action9->setChecked(true);
}

void GINA::on_action11_triggered(){
    yTicks = 11;
    uncheckY();
    ui->action11->setChecked(true);
}

void GINA::on_action5_default_triggered(){
    yTicks = 5;
    uncheckY();
    ui->action5_default->setChecked(true);
}

void GINA::on_actionSet_To_Default_triggered(){
    uncheckX();
    uncheckY();
    xTicks = 5;
    yTicks = 5;
    ui->action5_default->setChecked(true);
    ui->action5_default_2->setChecked(true);
}

//Adds a string of text to the ui window.
void GINA::addToWindow(QString text){
    ui->output->append(text);
}

//Changes the setting to printData when the menu option is clicked.
void GINA::on_actionPrint_Data_triggered(){
    if(!printData){
        ui->actionPrint_Data->setChecked(true);
        printData = true;
    } else {
        ui->actionPrint_Data->setChecked(false);
        printData = false;
    }
}

//Determines whether to display the graphs or not.
void GINA::on_actionHide_Graphs_triggered(){
    if(hideGraphs){
        ui->actionHide_Graphs->setChecked(false);
        hideGraphs = false;
    } else {
        ui->actionHide_Graphs->setChecked(true);
        hideGraphs = true;
    }
}

void GINA::on_Save_Window_Text_clicked()
{
    QString windowText = ui->output->toPlainText();
    QString date = QDate::currentDate().toString();
    QString time = QTime::currentTime().toString();
    ui->output->append("Date: " + date + " Time: " + time);
    time.remove(':');
    date.remove(' ');

    QString filename = analysisPath + "/" + "window" + date + time + ".txt";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << windowText;
    }


    ui->output->append("Contents of Window saved to: " + filename);
}

void GINA::on_Save_Analysis_clicked()
{
    QString time = QTime::currentTime().toString();
    time.remove(':');

    if (processText != ""){
        processText.remove(' ');
        QString filename = analysisPath + "/" + processText + ".txt";
        QFile file( filename );
        if ( file.open(QIODevice::ReadWrite) )
        {
            QTextStream stream( &file );
            stream << analysisText;
        }

        ui->output->append("Analysis saved to: " + filename);
    } else {
      ui->output->append("No analysis to save.");
    }
}
