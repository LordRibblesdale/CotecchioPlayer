/* Created by LordRibblesdale on 01/08/2021.
 * MIT License
 */

#include <iostream>
#include "xml/XmlHandler.hpp"
#include "network/SocketConnection.hpp"

int main(int argc, char* argv[]) {
    loadXML(Settings::settingsPath, SETTINGS);
    initialiseConnection();

    std::string message;
    std::cin >> message;

    sendStringToServer(message);
    std::cout << receiveStringFromServer() << std::endl;

    return 0;
}