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
bool checkVIN(std::string vin);
void HelpPage();
void getImgURL(std::string vin );