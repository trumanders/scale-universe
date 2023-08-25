#include <iostream>
#include "Measurement.h"
#include <sstream>
#include <iomanip>

Measurement::Measurement(std::string unit)
{
    _unit = unit;
}

void Measurement::setMeasurement(double measurement)
{
    _measurement = measurement;
    setUnit();
}

double Measurement::getMeasurement()
{
    return _measurement;
}

std::string Measurement::getUnit()
{
    return _unit;
}

std::string Measurement::toString()
{
    std::ostringstream oss;
    int precision = 3;
    if (((_unit == " km" || _unit == " kg" || _unit == " km^3") && _measurement >= 1000) || _unit == " g/liter") precision = 0;
    if (_unit == " cm" || _unit == " mm") precision = 1;
    if (_unit == " mm" && _measurement < 1) precision = 3;
    if (_unit == " earth years") precision = 2;
    if (_unit == " g" && _measurement < 1) precision = 3;
    if (_unit == " Hz" && _measurement >= 1) precision = 0;
    if (_unit == " Hz" && _measurement < 1) precision = 50;

    oss << std::fixed << std::setprecision(precision) << _measurement;
    std::string formattedNumber = oss.str();
    if ((_unit == " km" || _unit == " kg" || _unit == " km^3") && _measurement >= 1000)
        formattedNumber = insertCommas(formattedNumber);
    formattedNumber += _unit;
    return formattedNumber;
}

void Measurement::setUnit()
{
    if (_unit == " km" || _unit == " cm" || _unit == " mm" || _unit == " m")
    {
        _unit = " m";

        if (_measurement >= 1000) _unit = " km";
        if (_measurement < 1) _unit = " cm";
        if (_measurement < 0.01) _unit = " mm";

        if (_unit == " km") _measurement /= 1000;
        if (_unit == " cm") _measurement *= 100;
        if (_unit == " mm") _measurement *= 1000;
    }

    if (_unit == " kg" || _unit == " g" || _unit == " mg" || _unit == " mcg" || _unit == " ng")
    {
        _unit = " kg";

        if (_measurement < 1) _unit = " g";
        if (_measurement < 0.01) _unit = " mg";
        if (_measurement < 0.00001) _unit = " mcg";
        if (_measurement < 0.000000001) _unit = " ng";

        if (_unit == " g") _measurement *= 1000;
        if (_unit == " mg") _measurement *= 1000000;
        if (_unit == " mcg") _measurement *= 1000000000;
        if (_unit == " ng") _measurement *= 1000000000000;
    }

    if (_unit == " km^3" || _unit == " m^3" || _unit == " liters" || _unit == " ml") 
    {
        _unit = " km^3";

        if (_measurement < 0.1) _unit = " m^3";
        if (_measurement < 0.000000001) _unit = " liters";
        if (_measurement < 0.000000000001) _unit = " ml";

        if (_unit == " m^3") _measurement *= 1000000000;
        if (_unit == " liters") _measurement *= 1000000000000;
        if (_unit == " ml") _measurement *= 1000000000000000;
    }


}

std::string Measurement::insertCommas(std::string num)
{
    if (num.length() < 4)
        return num;

    int start = num.length() - 3;
    int end = 0;
    while (start > end)
    {
        num.insert(start, ",");
        start -= 3;
    }
    return num;
}

double Measurement::toMeters()
{
    if (_unit == " km") return _measurement * 1000;
    if (_unit == " cm") return _measurement / 100;
    if (_unit == " mm") return _measurement / 1000;
    return _measurement;
}

double Measurement::toKilos()
{
    if (_unit == " g") return _measurement / 1000;
    if (_unit == " mg") return _measurement / 1000000;
    if (_unit == " mcg") return _measurement / 1000000000;
    if (_unit == " ng") return _measurement / 1000000000000;
    return _measurement;
}