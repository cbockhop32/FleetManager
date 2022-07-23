
#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>
#include <string>
#include <chrono>

#include "microservice.hpp"



using namespace std;
using namespace boost::asio;

vector<char> vBuffer(20*1024);

void GrabData(ip::tcp::socket& socket) 
{
    socket.async_read_some(buffer(vBuffer.data(), vBuffer.size()),
        [&](error_code ec, size_t length)
        {
            if(!ec)
            {
                // cout << "\n\n Read " << length << "bytes\n\n";

                for(int i=0; i < length; i++) {
                    cout << vBuffer[i];
                }

                GrabData(socket);
            }
        }
    );
}


void getImgURL(string vin) {


    error_code ec;

    io_context context;

    // Keep context busy so its doesnt close
    io_context::work idleWork(context);

    // Start context
    thread thrContext = thread([&]() {context.run(); });

    ip::tcp::socket sock(context);

    sock.connect({{}, 8080});


    if(!ec) {
        cout << "Connected" << endl;
    } else 
    {
        cout << "Failed to connect to adress: \n" << ec.message() << endl;
    }

    if(sock.is_open()){
        GrabData(sock);

        // Need to send make and model here
        string request("GET HTTP/1.1\r\n\r\n");

        sock.send(buffer(request));
        sock.write_some(buffer(request.data(),request.size()));

        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        context.stop();
        if(thrContext.joinable()) {
            thrContext.join();
        }
    }


}