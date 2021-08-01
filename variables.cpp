/* Created by LordRibblesdale on 01/08/2021.
 * MIT License
 */

#include "variables.hpp"

std::string Network::ipAddress("localhost");
unsigned int Network::port = 443;
bool Network::isConnected = false;
error_code Network::currentNetworkError;
io_context Network::asyncIO;
tcp::socket Network::socket(asyncIO);

streambuf Network::currentBuffer;

bool Settings::areSettingsLoaded = false;
const std::string Settings::settingsPath("./settings.xml");

const std::string Language::languagePath("./languages");
std::unique_ptr<LanguageResource> Language::languageResource;