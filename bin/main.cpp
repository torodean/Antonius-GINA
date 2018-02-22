//==========================================================================
// GINA (Generations of Implanted Nuclear Activity)
// Michigan State University - National Superconducting Cylotron Laboratory
// File: main.cpp
// Created By: Antonius Torode
// File Created: June 22, 2017
// Purpose: This file is the main launcher for the GINA program.
//==========================================================================

#include "gina.h"
#include <QApplication>

//For testing
#include "ginafit.h"
#include "string"
#include <iostream>

//For testing new functions.
void test(){
    std::string filename = "/user/antonius/Desktop/Antonius-Research/e17503/sundata/decayDat.txt";
    GINAfit fit;
    std::cout << "Entered testing" << std::endl;
    fit.data(filename);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* Main GINA program */
    GINA window;
    test();
    window.setWindowTitle("GINA - Generations of Implanted Nuclear Activity");
    window.show();


    return a.exec();
}
