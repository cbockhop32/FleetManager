
# Compiling Fleet Manager

g++ -std=c++11 -o main2 main.cpp fleet_functions.cpp help_functions.cpp -lboost_system


g++ -std=c++11 -o main2 -I /opt/homebrew/include -L /opt/homebrew/lib -lboost_system main.cpp fleet_functions.cpp help_functions.cpp microservice.cpp 
# Using Microservice


# Code Smells
    1) Obsolete Comment
    2) Commented-Out Code
    3) Redundtant Comment
    4) Long Comment
    5) Long Function
    6) Function with many jobs
    7) Function with many parametes
    8) Duplicate Code
    9) Long Lines
    10) Inconsisten Convetions
    11) Vague Naming



