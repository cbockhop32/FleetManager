#pragma once

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

#include <string>

void getImgURL(std::string vin);
void GrabData(boost::asio::ip::tcp::socket& socket);