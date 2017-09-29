//==========================================================================
// GINA (Generations of Implanted Nuclear Atrophy)
// Michigan State University - National Superconducting Cylotron Laboratory
// File: GINAelements.h
// Created By: Antonius Torode
// File Created: June 22, 2017
// Purpose: This file contains useful functions and small features of the GINA program.
//==========================================================================

#include "ginaelements.h"
#include <QString>

GINAelements::GINAelements():
    minuteConversion(60.0), hourConversion(3600.0), dayConversion(3600.0*24.0), weekConversion(3600.0*24.0*7.0), yearConversion(3600.0*24.0*365.25)
{

}

//extracts the text in a string and removes all spaces.
QString GINAelements::extractUnits(QString input){
    input.remove(' ');
    input.remove('.');

    input = input.toLower();

    //Removes all numbers
    input.remove('0');
    input.remove('1');
    input.remove('2');
    input.remove('3');
    input.remove('4');
    input.remove('5');
    input.remove('6');
    input.remove('7');
    input.remove('8');
    input.remove('9');

    return input;
}

//extracts all numbers in a string.
double GINAelements::extractValue(QString input){

    input = input.toLower();

    //Removes all letters
    input.remove(' ');
    input.remove('a');
    input.remove('b');
    input.remove('c');
    input.remove('d');
    input.remove('e');
    input.remove('f');
    input.remove('g');
    input.remove('h');
    input.remove('i');
    input.remove('j');
    input.remove('k');
    input.remove('l');
    input.remove('m');
    input.remove('n');
    input.remove('o');
    input.remove('p');
    input.remove('q');
    input.remove('r');
    input.remove('s');
    input.remove('t');
    input.remove('u');
    input.remove('v');
    input.remove('w');
    input.remove('x');
    input.remove('y');
    input.remove('z');

    double value = input.toDouble();

    return value;
}

double GINAelements::convertToSeconds(QString input){
    double value = extractValue(input);
    QString units = extractUnits(input);

    if (units == "e"){
        value = input.toDouble();
    } else if(units == "s" || units == "sec" || units == "second" || units == "seconds"){

    } else if (units == "m" || units == "min"  || units == "mins" || units == "minute" || units == "minutes"){
        value = value * minuteConversion;
    } else if (units == "h" || units == "hr" || units == "hrs" || units == "hour" || units == "hours"){
        value = value * hourConversion;
    } else if (units == "d" || units == "day" || units == "days"){
        value = value * dayConversion;
    } else if (units == "w" || units == "wk"  || units == "wks"  || units == "week" || units == "weeks"){
        value = value * weekConversion;
    } else if (units == "y" || units == "yr" || units == "yrs" || units == "year" || units == "years"){
        value = value * yearConversion;
    } else {
        value = value;
    }

    return value;
}
