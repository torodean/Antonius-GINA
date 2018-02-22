//==========================================================================
// GINA (Generations of Implanted Nuclear Activity)
// Michigan State University - National Superconducting Cylotron Laboratory
// File: GINAfit.cpp
// Created By: Antonius Torode
// File Created: June 22, 2017
// Purpose: This file contains functions for fitting various decay curves to a function.
//==========================================================================


#include "ginafit.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//GINAfit constructor
GINAfit::GINAfit(){

}

//Collects the xData from a sey of data points.
std::vector<double> GINAfit::xData(std::vector<std::string> data){

}

//Collects the yData from a sey of data points.
std::vector<double> GINAfit::yData(std::vector<std::string> data){

}

//Collects each data coordinate from a file.
std::vector<std::string> GINAfit::data(std::string filename){
    std::vector<std::string> data;
    int count = 0;
    std::cout << "Entered data" << std::endl;

    std::string fileLine;
    std::ifstream file;
    file.open (filename);
        while(!file.eof()){
            std::getline(file,fileLine);
            data.push_back(fileLine);
            count++;
            std::cout << data[count-1] << std::endl;
        }
    file.close();

    return data;
}
