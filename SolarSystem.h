#pragma once
#include "CelestialBody.h"
#include <vector>
#include <iostream>

class SolarSystem
{
    private:
        void createSolarSystem();
        std::vector<CelestialBody> celestialBodies;
        std::string insertCommas(std::string num);
        std::string formatNumber(double number);
        std::string getAppropriateUnit(double& num);
        double _frequencyScaleFactor;
        void listBodyNames();
        double _scaleFactor = 1;
        double _massScaleFactor = 1;
        double _newSize;
        double _newFrequency;
        std::string _unit;
        void setScaleFactor();
        CelestialBody chooseBody();
        void convertYearToHz();
        void setUnit(double  &value);
        double getMassScaleFactor();

    public:
        SolarSystem();
        void printPlanetInfo(int index);
        // void createCelestialBody();
        int getNumberOfCelestialBodies();
        double getDistanceFromInnerNeighbour(int index);
        // CelestialBody getCelestialBody(int index);
        void setScaleParameters();
        void scaleSolarSystem();
        void setFrequencyScaleParameters();
        void scaleFrequency();
        static const double YEAR_TO_HZ;
};