#pragma once
#include "Measurement.h"

class CelestialBody
{
    private:
        Measurement _diameter = Measurement(" m");
        Measurement _distanceFromSun = Measurement(" m");
        Measurement _distanceFromInnerNeighbour = Measurement(" km"); // is set after body measurements are converted to km
        Measurement _mass = Measurement(" kg");
        Measurement _orbitTimeInEarthYears = Measurement(" earth years");
        Measurement _orbitTimeInHz = Measurement(" Hz");
        Measurement _volume = Measurement(" km^3");
        Measurement _density = Measurement(" kg/m^3");

        std::string _name;
        const double PI = 3.1415926535897932;
        const double YEAR_TO_SECONDS = 365 * 24 * 3600;

    public:
        CelestialBody(std::string name, double diameter, double distanceToSun, double orbitTime, double mass);
        void setDiameter(double scaleFactor);
        void setDistanceFromSun(double distanceFromSun);
        void setDistanceFromInnerNeighbour(double distanceFromInnerNeighbour);
        void setName(std::string name);
        void setOrbitTimeInEarthYears(double earthYears);    
        void setMass(double mass);
        void setOrbitTimeInHz(double frequency);
        void setVolume();
        void setDensity();

        Measurement getOrbitTimeInEarthYears();
        Measurement getOrbitTimeInHz();
        Measurement getDistanceFromSun();
        Measurement getDistanceFromInnerNeighbour();   
        Measurement getDiameter();
        Measurement getMass();
        Measurement getVolume();
        Measurement getDensity();

        Measurement getMeasurementObject();
        std::string getName();
};