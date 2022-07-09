#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>
#include <ios>
#include <limits>
#include <chrono>
#include <thread>

#include "fleet_functions.hpp"
#include "help_functions.hpp"
#include "carFleet.hpp"


using namespace std;


map<string,struct Car> carFleet;



void AddCarToFleet()
{
    string vin;
    int year;
    string make;
    string model;
    int msrp;
    int cityMpg;
    int highwayMpg;


    cout <<"Please enter the following details to add a car to your fleet: \n" << endl;


    
    do {
        cout <<"Please Enter the VIN Number of the Vehicle (Required):";
        getline(cin,vin);

        

    } while(vin.length() != 0);


    // cout <<"Please Enter the VIN Number of the Vehicle (Required):";
    // cin >> vin;
    
 



    // Check if VIN already exists here
    bool carExists = checkVIN(vin);

    if(carExists) {
        cout << "Car is already included within the fleet. Please add a different Vehicle" << endl;
    }

    cout <<"Please Enter the model Year of the Vehicle: ";
    cin >> year;

    cout <<"Please Enter the Make of the Vehicle: ";
    cin >> make;
    
    cout <<"Please Enter the Model of the Vehicle: ";
    cin >> model;

    cout <<"Please Enter the MSRP of the Vehicle: ";
    cin >> msrp;

    cout <<"Please Enter the Estimated City MPG of the Vehicle: ";
    cin >> cityMpg;

    cout <<"Please Enter the Estimated City MPG of the Vehicle: ";
    cin >> highwayMpg;

    // Uppercasing strings
    transform(make.begin(), make.end(), make.begin(), ::toupper);
    transform(model.begin(), model.end(), model.begin(), ::toupper);

    ostringstream outss;
    outss << "You entered the following details: \n\n VIN: " << vin << "\n\n Model Year: " << year 
    << "\n Make: " << make << "\n Model: " << model << "\n\n MSRP: " << msrp << "\n MPG (City / Highway)"
    << cityMpg << " / " << highwayMpg;

    string reviewPrompt = outss.str();
    string reviewCmd;

    cout << reviewPrompt << endl;
    cout << "Do you want to add this Vehicle to your fleet? (yes/no)" << endl;
    cin >> reviewCmd;


    while(true) {
        if(reviewCmd == "yes") {
            cout << "Car has been added to your fleet" << endl;
            Car newCar;
            newCar.vin = vin;
            newCar.year = year;
            newCar.make = make;
            newCar.model = model;
            newCar.MSRP = msrp;
            newCar.cityMpg = cityMpg;
            newCar.highwayMPG = highwayMpg;

            carFleet.insert(pair<string, Car>(vin, newCar));




            break;
        }else if (reviewCmd == "no") {
            cout << "Going back to main menu" << endl;
            break;

        } else {
            continue;
        }

    }

};
void RemoveCarFromFleet(string vin)
{
        cout <<"This is the remove car function" << endl;
};


void ListCarsInFleet() {
    cout << "Listing cars in fleet" << endl;

    map<string,Car>::iterator it;
    int count = 1;

    for(it = carFleet.begin(); it != carFleet.end();it++) {


        cout << count << ".   " << it->first << "  " << it->second.year << it->second.make << "  " << it->second.model << "\n";
        count += 1;
    }


};
bool EditCarDetails(string vin) {
    // Have a similar interface where it goes through each data member of the Car struct but says that
    // if you want to keep the current value, just press enter, otherwise enter new value

    struct Car *currCar = LookUpCarByVIN(vin);

    if(currCar){

        cout << "You have chosen to edit:  " << currCar->year << " " << currCar->make << " " <<  currCar->model << endl;
    } else {
        cout << "\n\n Car Does Not Exist. Going back to main menu." << endl;
        return false;
    }


    cout << "\n If you would like to edit a certain value, enter a new value when prompted. If you would like to keep the current value, simply press Enter \n \n" << endl;
    
    int year;
    string make;
    string model;
    int msrp;
    int cityMpg;
    int highwayMpg;


 


    do
    {
        cout <<"Current Model Year: " << currCar->year << "  (Keep current by pressing 'Enter' or enter new Year):  ";
        cin >> year;

        if(year == '\n') {
                year = currCar->year;
                cout << "Value Kept" << endl;
        } else {
                cout << "Value changed" << endl;
        }

        cout <<"Current Make: " << currCar->make << "  (Keep current by pressing 'Enter' or enter new Make):  ";
        cin >> make;
        cout << make.length() << endl;


        if(make.length() == 0) {
                make = currCar->make;
                cout << "Value Kept" << endl;
        } else {
                cout << "Value changed" << endl;
        }

        // string* mkptr = &make;
        
        // UpdateValue("make", mkptr, currCar);
       
        // cout <<"Please Enter the Model of the Vehicle: ";
        // cin >> model;

        // cout <<"Please Enter the MSRP of the Vehicle: ";
        // cin >> msrp;

        // cout <<"Please Enter the Estimated City MPG of the Vehicle: ";
        // cin >> cityMpg;

        // cout <<"Please Enter the Estimated City MPG of the Vehicle: ";
        // cin >> highwayMpg;
        return true;
        
    } while (true);
    
 
    return true;





    
};


void UpdateValue(string member, string* var, Car* currCar) {
      if(*var == "\n") {
            // *var = currCar->member;
            cout << "Value Preserved" << endl;
        } else {
            cout << "Value changed" << endl;
        }
}





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
                this_thread::sleep_for(chrono::milliseconds(1500));

            }

        } while(helpRunning != false);


        
};



bool checkVIN(string vin) {
    return false;
}