/* Created by LordRibblesdale on 01/08/2021.
 * MIT License
 */

#ifndef XMLHANDLER_HPP
#define XMLHANDLER_HPP

#include <fstream>
#include <vector>

#include "rapidxml/rapidxml.hpp"
#include "../variables.hpp"

enum XMLFiles : unsigned int {
    SETTINGS = 0
};

void loadXML(const std::string& path, XMLFiles type);

#endif // XMLHANDLER_HPP
