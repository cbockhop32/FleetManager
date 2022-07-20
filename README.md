
# Compiling Fleet Manager

g++ -std=c++11 -o main2 main.cpp fleet_functions.cpp help_functions.cpp -lboost_system


g++ -std=c++11 -o main2 -I /opt/homebrew/include -L /opt/homebrew/lib -lboost_system main.cpp fleet_functions.cpp help_functions.cpp

# Using Microservice






