//==========================================================================
// GINA (Generations of Implanted Nuclear Activity)
// Michigan State University - National Superconducting Cylotron Laboratory
// File: GINAfit.h
// Created By: Antonius Torode
// File Created: June 22, 2017
// Purpose: This is the header file corresponding to the GINAfit.cpp file.
//==========================================================================

#ifndef GINAFIT_H
#define GINAFIT_H
#include <vector>
#include <string>

class GINAfit
{
private:

public:
    GINAfit();

    int numOfDecays;
    std::vector<double> xData(std::vector<std::string> data);
    std::vector<double> yData(std::vector<std::string> data);
    std::vector<std::string> data(std::string filename);

    void fitDataExpDecay(std::vector<double> xData, std::vector<double> yData);
};

#endif // GINAFIT_H
