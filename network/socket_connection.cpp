/* Created by LordRibblesdale on 01/08/2021.
 * MIT License
 */

#include <iostream>

#include "socket_connection.hpp"
#include "../variables.hpp"

typedef boost::asio::ip::address_v4 address_v4;
typedef boost::asio::error::misc_errors errors;

std::string receivedString;

void initialiseConnection() {
    if (Settings::areSettingsLoaded && !Network::isConnected) {
        // address::from_string(Network::ipAddress)
        Network::socket.connect(tcp::endpoint(address_v4::from_string(Network::ipAddress), Network::port),
                                Network::currentNetworkError);

        if (!Network::currentNetworkError) {
            Network::isConnected = true;
        } else {
            // TODO check if false condition needs to be handled in some way
        }
    }
    // TODO check if false condition needs to be handled in some way
}

void sendStringToServer(std::string& message) {
    if (Network::isConnected) {
        boost::asio::write(Network::socket, boost::asio::buffer(message), Network::currentNetworkError);

        if (Network::currentNetworkError) {
            std::cout << "ERR004: failed transmission " << Network::currentNetworkError.message() << std::endl;
        }
    } else {
        // TODO check if false condition needs to be handled in some way
    }
}

std::string receiveStringFromServer() {
    if (Network::isConnected) {
        boost::asio::read(Network::socket, Network::currentBuffer, boost::asio::transfer_all(), Network::currentNetworkError);

        if (Network::currentNetworkError && Network::currentNetworkError != errors::eof) {
            std::cout << "ERR003: failed reception " << Network::currentNetworkError.message() << std::endl;
        } else {
            receivedString = boost::asio::buffer_cast<const char*>(Network::currentBuffer.data());
        }
    } else {
        // TODO check if false condition needs to be handled in some way
    }

    return receivedString;
}

// TODO create transfer data and get feedback
