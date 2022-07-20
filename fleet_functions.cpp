#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>
#include <ios>
#include <limits>
#include <chrono>
#include <thread>
#include <variant>
#include <typeinfo>
#include <boost/asio.hpp>


#include "fleet_functions.hpp"
#include "help_functions.hpp"
#include "carFleet.hpp"


using namespace std;
using namespace boost::asio;


map<string,struct Car> carFleet;
vector<string> optionalAttributeNames ={"Model Year", "Make", "Model", "MSRP (Price)", "City MPG", "Highway MPG"};





void AddCarToFleet()
{
    string vin;
    int currIdx = 1;
    Car newCar;
    int vinTries = 0;
  

    cout <<"Please enter the following details to add a car to your fleet: \n" << endl;

    while(true) {
        cout <<"Please Enter the VIN Number of the Vehicle (Required):";
        if(vinTries == 0) {
            cin.ignore();           
        }
    
        getline(cin, vin);

        if(vin.empty()) {
            cout << "Please enter a value for the VIN number it is required" << endl;
            cin.clear();
            vinTries++;
            continue;
        } else {
            newCar.vin = vin;
            break;
        }
    }


    if(CarExists(newCar.vin)) {
        cout << "A car within your fleet already exists with the VIN number: " << newCar.vin << "\n\nGoing back to main menu\n";
        return;
    }

   
    for(string &currOption : optionalAttributeNames) {
        cout << "Enter value for " << currOption << ":  ";

        string currInput;
        getline(cin, currInput); 

        if(currInput.empty()) {
            newCar[currIdx] = "None";
            cin.clear();
        } else {
             newCar[currIdx] = currInput;
        }

        // Controls which member of the Car struct it is addressing
        currIdx++;
    }

        // Uppercasing strings
    transform(newCar.vin.begin(), newCar.vin.end(), newCar.vin.begin(), ::toupper);
    transform(newCar.make.begin(), newCar.make.end(), newCar.make.begin(), ::toupper);
    transform(newCar.model.begin(), newCar.model.end(), newCar.model.begin(), ::toupper);

    ostringstream outss;
    outss << "\nYou entered the following details: \n\n VIN: " << newCar.vin << "\n\n Model Year: " << newCar.year 
    << "\n Make: " << newCar.make << "\n Model: " << newCar.model << "\n\n MSRP: " << newCar.MSRP << "\n MPG (City / Highway): "
    << newCar.cityMpg << " / " << newCar.highwayMPG << '\n';

    string reviewPrompt = outss.str();
    string reviewCmd;

    cout << reviewPrompt << endl;
 


    while(true) {
        cout << "Do you want to add this Vehicle to your fleet? (yes/no)" << endl;
        cin >> reviewCmd;
        if(reviewCmd == "yes") {
            cout << "Car has been added to your fleet" << endl;
        

            carFleet.insert(pair<string, Car>(newCar.vin, newCar));
            break;
        }else if (reviewCmd == "no") {
            cout << "Going back to main menu" << endl;
            break;

        } else {
            cin.clear();
            continue;
        }

    }



};

void RemoveCarFromFleet(string vin)
{
        if(!CarExists(vin)) {
            cout << "That car does not exist. Returning to Main Menu" << endl;
            return;
        }

        Car *carToBeRemoved = LookUpCarByVIN(vin);

        cout << "\nYou want to remove the following car: "<< carToBeRemoved->year << " " << carToBeRemoved->make << " " << carToBeRemoved->model << "\n"<< endl;

        string reviewCmd;
        while(true) {
        cout << "Do you want to remove this vehicle to your fleet? (yes/no)" << endl;
        cin >> reviewCmd;
        if(reviewCmd == "yes") {
            cout << "\nCar has been removed from your fleet" << endl;
            carFleet.erase(vin);
            break;
        }else if (reviewCmd == "no") {
            cout << "Going back to main menu" << endl;
            break;

        } else {
            cin.clear();
            continue;
        }

    }
};


void ListCarsInFleet() {
 

    if(carFleet.empty()) {
        cout << "\nThere are currently no cars within your fleet.\n ";
    } else {
        map<string,Car>::iterator it;
        int count = 1;

        cout << "  " << "   " << "VIN" << "  " << "Year" << "  " <<"Make" << "  " << "Model" << "\n";


        for(it = carFleet.begin(); it != carFleet.end();it++) {
            cout << count << ".   " << it->first << "  " << it->second.year << "  " <<it->second.make << "  " << it->second.model << "\n";
            count += 1;
        }
    }

  
};


bool EditCarDetails(string vin) {
    struct Car *currCar = LookUpCarByVIN(vin);
    int currIdx = 1;

    if(currCar){
        cout << "You have chosen to edit:  " << currCar->year << " " << currCar->make << " " <<  currCar->model << endl;
    } else {
        cout << "\n\n Car Does Not Exist. Going back to main menu." << endl;
        return false;
    }

    cout << "\n If you would like to edit a certain value, enter a new value when prompted. If you would like to keep the current value, simply press Enter \n \n" << endl;
    
    cin.ignore();

    for(string &currOption : optionalAttributeNames) {
        cout << "Enter value for " << currOption << ":  ";

        string currInput;
        getline(cin, currInput); 

        if(currInput.empty()) {
            cout << "value saved" << endl;
        } else {
            transform(currInput.begin(), currInput.end(), currInput.begin(), ::toupper);

            switch(currIdx) {
                case 1 : 
                    currCar->year = currInput;
                    break;
                case 2 : 
                    currCar->make = currInput;
                    break;
                case 3 : 
                    currCar->model = currInput;
                    break;
                case 4 : 
                    currCar->MSRP = currInput;
                    break;
                case 5 :
                    currCar->cityMpg = currInput;
                    break;
                case 6 : 
                    currCar->highwayMPG = currInput;
                    break;
                default: return false;

            }
        }
        // Controls which member of the Car struct it is addressing
        currIdx++; 
    }


    ostringstream outss;
    outss << "\nThe car with the VIN number: " << currCar->vin << "now reflects the following: \n" << "\n\n Model Year: " << currCar->year
    << "\n Make: " << currCar->make << "\n Model: " << currCar->model << "\n\n MSRP: " << currCar->MSRP << "\n MPG (City / Highway): "
    << currCar->cityMpg << " / " << currCar->highwayMPG << '\n';

    string editEnd = outss.str();

    cout << editEnd<< endl;

    return true;
};





bool CarExists(std::string vin) {
    map<string,Car>::iterator it;

    for(it = carFleet.begin(); it != carFleet.end();it++) {
        if(vin == it->first) {
            return true;
        }
    }

    return false;

}

Car *LookUpCarByVIN(std::string vin) {
    
    map<string,Car>::iterator it;

    for(it = carFleet.begin(); it != carFleet.end();it++) {
        if(vin == it->first) {
            return &it->second;
        }
    } 
    return nullptr;


};

void displayCarDetails(string vin) {
    struct Car *currCar = LookUpCarByVIN(vin);

    ostringstream outss;
    outss << "\nDetails of car: \n\n VIN: " << currCar->vin << "\n\n Model Year: " << currCar->year 
    << "\n Make: " << currCar->make << "\n Model: " << currCar->model  << "\n\n MSRP: " << currCar->MSRP << "\n MPG (City / Highway): "
    << currCar->cityMpg << " / " << currCar->highwayMPG << '\n';

    string displayDetails = outss.str();
    cout << displayDetails << endl;
}


void HelpPage() {

        bool helpRunning = true;

        string help = 
        "\n ~~ Fleet Manager - Help Page ~~ \n\n"
        "Below is a list of commands that you can enter in order to get more information on certain functionalities\n";
        
        string helpCommands = 
        "\n\n Enter the following numbers to get more info: \n\n"
        "1 :  How To Add A Car\n"
        "2 :  How To Remove A Car\n"
        "3 :  How to Edit Existing Car Details \n"
        "4 :  List All Current Cars \n"
        "5 :  Look Up Car In Fleet By VIN \n"
        "6 :  Fleet Statistics and Calculation Methodology \n"
        "7 :  Info On New Features That Have Been Added \n"
        "0 :  Go Back To Main Menu\n\n"
        "Enter a menu option: ";


        

        do{
            cout << helpCommands;
            int helpCmd;
            cin >> helpCmd;
          
          

            switch (helpCmd)
            {
                case 1:
                    addHelp();
                    break;
                case 2:
                    removeHelp();           
                    break;
                case 3:
                    editHelp();
                    break;
                case 4:
                    listAllHelp();
                    break;
                case 5:
                    lookUpHelp();
                    break;
                case 6:
                    fleetStatsHelp();
                    break;
                case 7:
                    newFeatures();
                    break;
                case 0:
                    cout << "Going back to main menu" <<endl;
                    helpRunning = false;
                    break;
                default:
                    cout << "Invalid command" << endl;
            
            }

            // Slight delay before help menu pops up again unless you're going back to the main menu
            if(helpCmd != 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));

            }

        } while(helpRunning != false);


        
};



bool checkVIN(string vin) {
    return false;
}


void getImgURL(string vin) {
    // error_code ec;

    // io_service service;
    // ip::tcp::socket sock(service);
    // sock.connect({{}, 8080});

    // std::string request("GET HTTP/1.1\r\n\r\n");
    // sock.send(buffer(request));

    // string response;

    

    // do {
    //     char buf[1024];
    //     size_t bytes_transferred = sock.receive(buffer(buf), {}, ec);
    //     if (!ec) response.append(buf, buf + bytes_transferred);
    // } while (!ec);

    // cout << response << endl;



}