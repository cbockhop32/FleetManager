#pragma once

#include <map>
#include <string>

extern std::map<std::string,struct Car> carFleet;
void CreateNewFleet();
void ListCarsInFleet(); 
void AddCarToFleet();
void RemoveCarFromFleet(std:: string vin);
bool EditCarDetails(std::string vin);
bool CarExists(std::string vin);
struct Car *LookUpCarByVIN(std::string vin);
void displayCarDetails(std::string vin);
void HelpPage();
void fleetStats();
void getCarAttributes(struct Car& newCar);
void addCarToFleetPrompt(struct Car* newCar);
void getVinPrompt(struct Car* newCar);
void uppercaseCarAttributes(struct Car* newCar);