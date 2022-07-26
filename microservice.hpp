#pragma once

#include <boost/asio.hpp>

#include <string>

void getImgURL(std::string vin);
void GrabData(boost::asio::ip::tcp::socket& socket);
std::string extractURL(std::string inString);
void fixStringCasing(std::string &inString);