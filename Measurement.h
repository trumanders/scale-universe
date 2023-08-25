#pragma once
#include <iostream>

class Measurement
{
    private:
        std::string _unit;
        double _measurement;
        void setUnit();
        std::string format();
        std::string insertCommas(std::string num);        
        std::string convertToString();
        std::string _type;

    public:    
        Measurement(std::string unit);
        void setMeasurement(double measurement);
        double getMeasurement();        
        std::string getUnit();
        std::string toString();
        double toMeters();
        double toKilos();
        std::string getType();

        friend class CelestialBody;
};
