/* Created by LordRibblesdale on 01/08/2021.
 * MIT License
 */

#include "xml/xmlHandler.hpp"
#include "network/socketConnection.hpp"

int main(int argc, char* argv[]) {
    loadXML(Settings::settingsPath, SETTINGS);
    initialiseConnection();

    std::string message("TEST MESSAGE");
    sendStringToServer(message);

    return 0;
}