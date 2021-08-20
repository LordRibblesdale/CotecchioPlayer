/* Created by LordRibblesdale on 01/08/2021.
 * MIT License
 */

#ifndef SOCKETCONNECTION_HPP
#define SOCKETCONNECTION_HPP

#include <string>

extern std::string receivedString;

void initialiseConnection();

void sendStringToServer(std::string& message);
std::string receiveStringFromServer();

#endif // SOCKETCONNECTION_HPP
