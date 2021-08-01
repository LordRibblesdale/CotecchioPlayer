/* Created by LordRibblesdale on 01/08/2021.
 * MIT License
 */

#include <iostream>
#include <memory>

#include "xmlHandler.hpp"


void loadXMLSettings(const rapidxml::xml_document<>& document);


void loadXML(const std::string& path, XMLFiles type) {
    std::ifstream file(path);

    if (file.is_open()) {
        std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        buffer.push_back('\0');

        rapidxml::xml_document<> document;
        document.parse<0>(buffer.data());

        switch (type) {
            case SETTINGS:
                loadXMLSettings(document);
                break;
        }
    } else {
        // TODO check if terminal prints them out
        std::cout << "ERR001: Error loading XML file! Default values are used." << std::endl;
    }

    file.close();
}

void loadXMLSettings(const rapidxml::xml_document<>& document) {
    try {
        rapidxml::xml_node<>* rootNode = document.first_node("settings");

        // Network
        rapidxml::xml_node<>* currentNode = rootNode->first_node("network");
        Network::ipAddress = currentNode->first_attribute("ip")->value();
        Network::port = std::stoi(currentNode->first_attribute("port")->value());

        // Language
        currentNode = rootNode->first_node("language");
        /*
        Language::languageResource = std::make_unique<LanguageResource>(Language::languagePath,
                                                                        currentNode->first_attribute("language")->value(),
                                                                        currentNode->first_attribute("country")->value());
                                                                        */

        Settings::areSettingsLoaded = true;
    } catch (std::exception& e) {
        std::cout << "ERR002: exception thrown in " << __PRETTY_FUNCTION__ << std::endl << e.what() << std::endl;
    }
}