#pragma once

#include <iostream>
#include <string>
#include <vector>




struct Fleet {
    std::string fleetName;
    std::vector<struct Car> fleetCars;
};

struct Car {
    std::string vin;
    int year;
    std::string make;
    std::string model;
    int MSRP;
    int cityMpg;
    int highwayMPG;


};



