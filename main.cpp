#include <iostream>
#include "CelestialBody.cpp"
#include "SolarSystem.cpp"
#include "Measurement.cpp"

SolarSystem solarSystem;

int displayMenu()
{
    std::cout << "\n\n";
    std::cout << "1. Scale solar system";
    std::cout << "\n2. Reset solar system to real scale";
    std::cout << "\n3. Scale orbit time frequency in hertz";

    std::cout << "\n0. Quit";
    int choise; std::cin >> choise;
    return choise;
}

void showSolarSystem()
{
    for (int i = 0; i < solarSystem.getNumberOfCelestialBodies(); i++)
    {
        solarSystem.printPlanetInfo(i);
    }
}

int main()
{
    int menuChoise;
    do
    {
        showSolarSystem();
        int menuChoise = displayMenu();

        switch (menuChoise)
        {
            case 1:
                solarSystem.scaleSolarSystem();
                break;
            
            case 2:
                solarSystem = SolarSystem();
                break;
            case 3:
                solarSystem.scaleFrequency();
                break;
            case 0:
                std::exit(0);
                break;
        }
    } while (menuChoise != 0);
    
    return 0;
}

