#include <iostream>

using namespace std;

#include "help_functions.hpp"


void addHelp() {
    string helpInfo = 
        "\n*** ADD A CAR TO THE FLEET HELP ***\n"

        "\n\n To add a car, you will need the following information: \n"
        "   1. VIN Number (Required)\n"      
        "       - A VIN number is required to add a car\n"
        "       - You can add a car with only just the VIN number and then choose to edit the other details \n"
        "           later using the Edit functionality\n\n"
        "   2. Model Year (Optional)\n"      
        "       - A Model Year of the car is optional at first and can be added later using the Edit functionality\n"
        "       - Please enter a four digit year (example: 2018)\n\n"
        "   3. Make (Optional)\n"      
        "       - A Make of the car is optional at first and can be added later using the Edit functionality\n\n"
        "   4. Model (Optional)\n"      
        "       - A Model of the car is optional at first and can be added later using the Edit functionality\n\n"
        ;

        cout << helpInfo << endl;
};



void removeHelp() {
       string helpInfo = 
       "\n*** REMOVE A CAR FROM THE FLEET HELP ***\n"
        "\n"
        "   To remove a car, you will need the VIN number of the car that you want to be removed. \n"
        "   The car needs to exist in order to use the remove functionality. If a VIN number is entered that does not exist in the fleet.\n"      
        "   The program will return back to the main menu.\n\n"
        "   Once a valid VIN number is entered, the program will prompt the user to confirm the removal of the car, providing the \n"
        "   details of the car to removed. \n\n"
        "   Once the user has confirmed the removal of the car, the user can check that the car has been removed from the fleet by going to the\n"
        "   main menu and using the 'List All Current Cars' functionality to check if the car has been removed."
        ;

        cout << helpInfo << endl;
};


void editHelp() {
    string helpInfo = 
        "\n*** EDIT A CAR'S DETAILS HELP ***\n"
        "\n\n To edit the details of a car, you first need to add the car in order to use this functionality. \n"
        "\n\n You will first be prompted to enter a VIN number of the car you would like to edit\n"
        " Again, the car has to exist within the fleet in order for the edit functionality to work\n\n"
        " You can either choose to enter a new value for a given attribute or you can keep the current value by pressing enter. \n"
        " You cannot change the VIN number of the car, if you want to change the VIN number, you first have to delete that specific car\n"
        " and then add another car with the desired VIN number"
        ;
    cout << helpInfo << endl;

};

void listAllHelp() {
    string helpInfo = 
        "\n*** LISTING ALL THE CURRENT CARS IN THE FLEET HELP ***\n"
        "\n\n This will list all the current cars that have been added to your fleet. \n"
        "\n\n This can be used to get information quickly on cars (i.e. look up VIN numbers, model years, etc.)\n"
        " If a specific vehicle attribute has been left blank by the user, it will display 'None' within the list of vehicles."
        ;
    cout << helpInfo << endl;};



void lookUpHelp() {

    cout << "look up help" << endl;

};


void fleetStatsHelp() {
    cout << "fleet help" << endl;

};


void newFeatures() {
    cout << "Here we will talk about new features that were added and how they help" << endl;
};