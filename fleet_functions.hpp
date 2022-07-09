#pragma once

#include <map>
#include <string>

extern std::map<std::string,struct Car> carFleet;
void CreateNewFleet();
void ListCarsInFleet(); 
void AddCarToFleet();
void RemoveCarFromFleet(std:: string vin);
bool EditCarDetails(std::string vin);
void UpdateValue(std::string member, std::string* var, struct Car* currCar);
bool CarExists(std::string vin);
struct Car *LookUpCarByVIN(std::string vin);
bool checkVIN(std::string vin);
void HelpPage();