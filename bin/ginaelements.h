//==========================================================================
// GINA (Generations of Implanted Nuclear Activity)
// Michigan State University - National Superconducting Cylotron Laboratory
// File: GINAelements.h
// Created By: Antonius Torode
// File Created: June 22, 2017
// Purpose: This is the header file corresponding to GINAelements.cpp
//==========================================================================

#ifndef GINAELEMENTS_H
#define GINAELEMENTS_H

#include <QString>

class GINAelements
{
public:
    GINAelements();
    QString extractUnits(QString input);
    double extractValue(QString input);
    double convertToSeconds(QString input);

private:
    //These are used for converting times given with units into seconds.
    double minuteConversion;
    double hourConversion;
    double dayConversion;
    double weekConversion;
    double yearConversion;
};

#endif // GINAELEMENTS_H
