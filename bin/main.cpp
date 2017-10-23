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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* Main GINA program */
    GINA window;
    window.setWindowTitle("GINA - Generations of Implanted Nuclear Activity");
    window.show();


    return a.exec();
}
