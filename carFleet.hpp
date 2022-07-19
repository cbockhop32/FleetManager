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
    std::string year;
    std::string make;
    std::string model;
    std::string MSRP;
    std::string cityMpg;
    std::string highwayMPG;


    std::string &operator[](size_t idx) {
        switch (idx) {
            case 0 : return vin;
            case 1: return year;
            case 2: return make;
            case 3: return model;
            case 4: return MSRP;
            case 5: return cityMpg;
            case 6: return highwayMPG;
            default: throw std::runtime_error("bad index");
        }
       
    };


};



