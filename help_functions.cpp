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
    cout << helpInfo << endl;
};



void lookUpHelp() {
    string helpInfo = 
        "\n*** LOOK UP CAR BY VIN NUMBER HELP ***\n"
        "\n\n You can look up a car within your fleet by VIN number \n"
        " The VIN number must be valid as-in a car exists in your fleet with that exact VIN number\n"
        " If your fleet does not contain a car with your VIN number then it will return to the main menu\n"
        "\n\n Once the car is found then it will display all the details/attributes associated with that car\n";
    cout << helpInfo << endl;

};


void fleetStatsHelp() {
    string helpInfo = 
        "\n*** SEE CURRENT FLEET STATISTICS HELP ***\n"
        "\n\n You can generate the current statistics accross your entire fleet. \n"
        " You will be able to see the average MSRP (price) across all your vehichles in your fleet.\n"
        "   This is calculated by taking each of the car's respective MSRPs and then dividing it by the number of cars in your fleet\n"
        "\n\n You will be able to see the averge fuel economy (in miles per gallon) across all your vehichles in your fleet\n"
        "   This will be listed by the average city MPG and then the average highway MPG\n"
        "   This is calculated by adding up the city and highway MPG across all the cars in your fleets and then dividing it by the number of vehichles in your fleet\n";


    cout << helpInfo << endl;

};


void newFeatures() {
    string helpInfo = 
        "\n*** NEW FEATURES HELP ***\n"
        "\n\n1) Edit functionality \n"
        "   You will be able to edit your car's attributes after you have already added the car\n"
        "   This allows you to go back correct any errors that occured when the car was first intitialized within the system\n"
        "   Also if you choose to add a car with only the VIN number, this allows you to go back later to enter in the rest of the car's attributes\n"
        "\n\n2) Get Image URL for car\n"
        "   You are now able to us a microservice that when called, will go and fetch an image URL for that specific car\n"
        "   The program will send an HTTP request to this external microservice, that microservice will then go out and fetch a URL for an image \n"
        "   The URL will be saved as an attribute of the car that can then be used for later use. \n";

    cout << helpInfo << endl;};

void getImgUrlHelp() {
       string helpInfo = 
        "\n*** RETRIEVE IMAGE URL HELP ***\n"
        "\n\nFleet manager can use an external microservice that will take in a Make and Model and will retrieve a URL to \n"
        "an image of your car. That URL will be saved inside the database.\n\n"
        "In a seperate terminal, have the microservice running by typing 'npm start'. The microservice should output that the server\n"
        "is running on port 3000.\n"
        "\n\nOnce you have done that, you can go to the main menu and selection option (7). This will then prompt you for a VIN number of a car within your fleet\n"
        "Type in the VIN number and Fleet Manger will now send an HTTP GET request to the server that was initialized on port 3000.\n"
        "The microservice will find the Wikipedia page for the specific car that you passed in and then retrieve a URL to an image of that car.\n"
        "The URL is automatically saved within Fleet Manager and attached to the respective car\n";

    cout << helpInfo << endl;
};
