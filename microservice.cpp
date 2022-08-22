
#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include <chrono>
#include <sstream>

#include "microservice.hpp"
#include "fleet_functions.hpp"
#include "carFleet.hpp"

using namespace std;
using namespace boost::asio;

void getImgURL(string vin) {
    if(!CarExists(vin)){
        cout << "Car Does Not Exist In Your Fleet\n\n";
        return;
    }

    boost::system::error_code ec;

    Car* requestedCar = LookUpCarByVIN(vin);
    string make = requestedCar->make;
    string model = requestedCar->model;

    fixStringCasing(make);
    fixStringCasing(model);

    ostringstream oss;
    oss <<"GET /?content=" << make << "_" << model <<" HTTP/1.1\r\n\r\n";
    
    io_service svc;
    ip::tcp::socket sock(svc);
    sock.connect({ {}, 3000 }); 

    // send request
    string request = oss.str();
    sock.send(buffer(request));
    std::string response;
    do {
        char buf[1024];
        size_t bytes_transferred = sock.receive(buffer(buf), {}, ec);
        if (!ec) response.append(buf);
    } while (!ec);

    string url = "https:";
    url.append(extractURL(response));

    requestedCar->imgURL = url;

    cout << "Image URL has been set for your " << make << " " << model <<  endl;
 
}


string extractURL(string inString) {
    size_t start = 0;
    size_t nextQuote = 0;
    string extractedURL;

    while(nextQuote = inString.find("\"/", start), nextQuote != string::npos)
    {
        size_t endQuote = inString.find('\"', nextQuote+1);
        if(endQuote == string::npos)
        {
            throw logic_error("Unmatched quotes");
        }
        extractedURL = inString.substr(nextQuote +1, endQuote-nextQuote- 1);
        start = endQuote+1;
    }
    return extractedURL;
}


void fixStringCasing(string &inString)
{
    transform(inString.begin(), inString.end(), inString.begin(), ::tolower);
    inString[0] = toupper(inString[0]);
}
