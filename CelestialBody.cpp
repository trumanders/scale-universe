#include "CelestialBody.h"
#include "SolarSystem.h"
#include <iostream>
#include <math.h>

CelestialBody::CelestialBody(std::string name, double diameter, double distanceFromSun, double orbitTime, double mass)
{
    setName(name);
    setDiameter(diameter);
    setVolume();
    setMass(mass);
    setDensity();
    setDistanceFromSun(distanceFromSun);
    setOrbitTimeInEarthYears(orbitTime);    
    setOrbitTimeInHz((1 / orbitTime) / YEAR_TO_SECONDS);
}

void CelestialBody::setMass(double mass)
{
    _mass.setMeasurement(mass);
}

void CelestialBody::setDensity()    // kg/m^3
{
    // convert volume to m^3
    std::string volumeUnit = _volume.getUnit();
    double volume = _volume.getMeasurement();
    if (volumeUnit == " km^3") volume *= 1000000000;
    if (volumeUnit == " liters") volume /= 1000;
    if (volumeUnit == " ml") volume /= 1000000;

    // convert mass to grams
    double mass = _mass.getMeasurement();
    std::string massUnit = _mass.getUnit();
    if (massUnit == " g") mass /= 1000;
    if (massUnit == " mg") mass /= 1000000;
    if (massUnit == " mcg") mass /= 1000000000;
    if (massUnit == " ng") mass /= 1000000000000;

    _density.setMeasurement(mass / volume);
}

Measurement CelestialBody::getDensity()
{
    return _density;
}

Measurement CelestialBody::getMass()
{
    return _mass;
}

void CelestialBody::setOrbitTimeInHz(double frequency)
{
    _orbitTimeInHz.setMeasurement(frequency);
}

Measurement CelestialBody::getOrbitTimeInHz()
{
    return _orbitTimeInHz;
}

void CelestialBody::setDiameter(double diameter)
{
    _diameter.setMeasurement(diameter);
}

void CelestialBody::setDistanceFromSun(double distanceFromSun)
{
    _distanceFromSun.setMeasurement(distanceFromSun);
}

Measurement CelestialBody::getDiameter()
{
    return _diameter;
}    

void CelestialBody::setName(std::string name)
{
    _name = name;
}

std::string CelestialBody::getName()
{
    return _name;
}

Measurement CelestialBody::getDistanceFromSun()
{
    return _distanceFromSun;
}

void CelestialBody::setOrbitTimeInEarthYears(double orbitTime)
{
    _orbitTimeInEarthYears.setMeasurement(orbitTime);
}

Measurement CelestialBody::getOrbitTimeInEarthYears()
{
    return _orbitTimeInEarthYears;
}

Measurement CelestialBody::getDistanceFromInnerNeighbour()
{
    return _distanceFromInnerNeighbour;
}

void CelestialBody::setDistanceFromInnerNeighbour(double distanceFromInnerNeighbour)
{
    _distanceFromInnerNeighbour.setMeasurement(distanceFromInnerNeighbour);
}

Measurement CelestialBody::getVolume()
{
    return _volume;
} 

void CelestialBody::setVolume()
{
    std::string unit = _diameter.getUnit();
    double diameter = _diameter.getMeasurement();
    std::cout << _name << ": diameter = " << diameter << std::endl;
    std::cout << _name << ": unit = " << unit << std::endl;


    // always set volume in km^3
    // convert diameter to km
    if (unit == " m") diameter /= 1000;
    if (unit == " cm") diameter /= 100000;
    if (unit == " mm") diameter /= 1000000;

    _volume.setMeasurement((4 * PI * pow((diameter / 2), 3)) / 3);
}