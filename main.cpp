#include <iostream>
#include <string>
#include <vector>

#include "carFleet.hpp"
#include "fleet_functions.hpp"

using namespace std;

int main()
{   
    bool isRunning = true;
    string introPrompt = 
        "\n ~~ Welcome to Fleet Manager ~~ \n\n"
        "Fleet Manager will allow you to easily manage your fleet of automobiles.\n"
        "It will keep track of important details about specific cars as well as provide\n"
        "important details and statistics of your entire fleet.\n\n"
        "To see additional details about the Fleet manger, type --help\n"
        "To begin using Fleet Manager type -run \n"
        "To exit, type -exit\n";

    string commandPrompt = 
        "\n\n Enter the following numbers to execute the following commands: \n\n"
        "1 :  Add A Car\n"
        "2 :  Remove A Car\n"
        "3 :  Edit An Existing Cars Details \n"
        "4 :  List All Current Cars \n"
        "5 :  Look Up Car In Fleet By VIN \n"
        "6 :  List Feet Statistics \n"
        "7 :  Help Page \n";

    string cmd;
    int functionCmd;

   

    do
    {

        cout << introPrompt << endl;
        cout << "Enter a command : ";
        cin >> cmd;
        
        if(cmd == "-run") {


            do{
                cout << commandPrompt << endl;
                cin >> functionCmd;
                string vin;

                switch (functionCmd)
                {
                    case 1:
                        AddCarToFleet();
                        break;
                    case 2:
                        
                        cout << "Enter VIN number of car you would like to delete:  ";
                        cin >> vin;
                        RemoveCarFromFleet(vin);
                        break;
                    case 3:
                        cout << "Enter VIN number of car you would like to edit:  ";
                        cin >> vin;
                        EditCarDetails(vin);
                        break;
                    case 4:
                        ListCarsInFleet();
                        break;
                    case 5:
                        cout << "Looking up car by VIN" << endl;
                        break;
                    case 6:
                        cout << "listing fleet stastics" << endl;
                        break;
                    case 7:
                        HelpPage();
                        break;
                    default:
                        cout << "Invalid command" << endl;
                
                }

            } while(isRunning != false);
   
        } else if (cmd == "-exit") {
            return 0;
        } else {
            cout << "Invalid command" << endl;
        }

    } while (isRunning != false);
    

   
}