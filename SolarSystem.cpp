#include <iostream>
#include <string>
#include "CelestialBody.h"
#include "SolarSystem.h"
#include <iomanip>
#include <math.h>

const double SolarSystem::YEAR_TO_HZ = .0000000317097919837;

SolarSystem::SolarSystem()
{
    createSolarSystem();
}

void SolarSystem::createSolarSystem() 
{
    celestialBodies.clear();
    celestialBodies.emplace_back(CelestialBody("Sun", 1391000000, 0, 0, 1.989 * pow(10, 30)));
    celestialBodies.emplace_back(CelestialBody("Mercury", 4879000, 57909227000, 0.24, 3.3011 * pow(10, 23)));
    celestialBodies.emplace_back(CelestialBody("Venus", 12104000, 108208930000, 0.62, 4.8675 * pow(10, 24)));
    celestialBodies.emplace_back(CelestialBody("Earth", 12742000, 149597890000, 1, 5.97237 * pow(10, 24)));
    celestialBodies.emplace_back(CelestialBody("Mars", 6779000, 227936640000, 1.88, 6.4171 * pow(10, 23)));
    celestialBodies.emplace_back(CelestialBody("Jupiter", 139820000, 778412020000, 11.86, 1.8982 * pow(10, 27)));
    celestialBodies.emplace_back(CelestialBody("Saturn", 116460000, 1426725400000, 29.46, 5.6834 * pow(10, 26)));
    celestialBodies.emplace_back(CelestialBody("Uranus", 50724000, 2870972200000, 84.01, 8.6810 * pow(10, 25)));
    celestialBodies.emplace_back(CelestialBody("Neptune", 49244000, 4498252900000, 164.79, 1.02413 * pow(10, 26)));

    celestialBodies[0].setDistanceFromSun(0);
    celestialBodies[0].setDistanceFromInnerNeighbour(0);

    for (int i = 1; i < celestialBodies.size(); i++)
    {
        celestialBodies[i].setDistanceFromInnerNeighbour(celestialBodies[i].getDistanceFromSun().toMeters() - celestialBodies[i - 1].getDistanceFromSun().toMeters());
    }
}

void SolarSystem::setScaleParameters()
{   
    CelestialBody body = chooseBody();
    // set size and scale
    std::cout << "\nEnter new diameter of " << body.getName() << " in meters: ";
    std::cin >> _newSize;
    _scaleFactor = _newSize / body.getDiameter().toMeters();
}

void SolarSystem::setFrequencyScaleParameters()
{
    CelestialBody body = chooseBody();
    std::cout << "\nEnter new frequency of " << body.getName() << " in Hz: ";
    std::cin >> _newFrequency;
    _frequencyScaleFactor = _newFrequency / body.getOrbitTimeInHz().getMeasurement();
}

CelestialBody SolarSystem::chooseBody()
{
    // choose planet
    std::cout << "Select celesial body to scale by:\n";
    SolarSystem::listBodyNames();
    std::cout << "\n\tChoose: ";
    int choise; std::cin >> choise;
    return celestialBodies[--choise];
}

void SolarSystem::listBodyNames()
{
    std::cout << "\n";
    for (int i = 0; i < celestialBodies.size(); i++)
    {
        std::cout << i+1 << ". ";
        std::cout << celestialBodies[i].getName() << std::endl;
    }
}

void SolarSystem::scaleFrequency()
{
    SolarSystem::setFrequencyScaleParameters();
    for (int i = 0; i < celestialBodies.size(); i++)
    {
        celestialBodies[i].setOrbitTimeInHz(_frequencyScaleFactor * celestialBodies[i].getOrbitTimeInHz().getMeasurement());
    }
}

void SolarSystem::scaleSolarSystem()
{
    SolarSystem::setScaleParameters();

    for (int i = 0; i < celestialBodies.size(); i++)
    {
        celestialBodies[i].setDiameter(celestialBodies[i].getDiameter().toMeters() *_scaleFactor);
        celestialBodies[i].setVolume();
        celestialBodies[i].setMass(celestialBodies[i].getMass().toKilos() * getMassScaleFactor());
        celestialBodies[i].setDensity();
        celestialBodies[i].setDistanceFromSun(celestialBodies[i].getDistanceFromSun().toMeters() * _scaleFactor);
        celestialBodies[i].setDistanceFromInnerNeighbour(celestialBodies[i].getDistanceFromInnerNeighbour().toMeters() * _scaleFactor);       
    }
}

int SolarSystem::getNumberOfCelestialBodies()
{
    return celestialBodies.size();
}

void SolarSystem::printPlanetInfo(int index)
{
    std::string name = celestialBodies[index].getName();
    std::string innerBodyName = celestialBodies[index - 1].getName();
    std::string diameter = celestialBodies[index].getDiameter().toString();
    std::string distanceFromSun = celestialBodies[index].getDistanceFromSun().toString();
    std::string distanceFromInnerNeighbour = celestialBodies[index].getDistanceFromInnerNeighbour().toString();
    std::string mass = celestialBodies[index].getMass().toString();
    std::string orbitTimeInEarthYears = celestialBodies[index].getOrbitTimeInEarthYears().toString();
    std::string orbitTimeInHz = celestialBodies[index].getOrbitTimeInHz().toString();
    std::string volume = celestialBodies[index].getVolume().toString();
    std::string density = celestialBodies[index].getDensity().toString();

    std::cout << name << ":\n\t";
    std::cout << "Diameter\t\t" << diameter << "\n\t";
    std::cout << "Mass\t\t\t" << mass << "\n\t";
    std::cout << "Volume \t\t\t" << volume << "\n\t";
    std::cout << "Desity \t\t\t" << density << "\n\t";

    if (name == "Sun")
        std::cout
            << "\n";
    else
    {
        std::cout << "Distance from sun\t" << distanceFromSun << "\n\t";
        std::cout << "Distance from " << innerBodyName << "\t" << distanceFromInnerNeighbour << "\n\t";
        std::cout << "Orbit time\t\t" << orbitTimeInEarthYears << "\n\t";
        std::cout << "Orbit frequency\t\t" << orbitTimeInHz << "\n\n";
    }
}

double SolarSystem::getDistanceFromInnerNeighbour(int index) 
{
    return celestialBodies[index].getDistanceFromSun().toMeters() - celestialBodies[index - 1].getDistanceFromSun().toMeters();
}

double SolarSystem::getMassScaleFactor()
{
    return pow(_scaleFactor, 3);
}

