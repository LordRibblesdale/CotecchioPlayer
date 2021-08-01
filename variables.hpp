/* Created by LordRibblesdale on 01/08/2021.
 * MIT License
 */

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>
#include <memory>
#include <boost/asio.hpp>

#include "translator/multi_language_library.hpp"

typedef boost::asio::ip::tcp tcp;

typedef boost::asio::io_context io_context;
typedef tcp::socket tcp_socket;
typedef boost::system::error_code error_code;

typedef boost::asio::streambuf streambuf;

namespace Network {
    extern std::string ipAddress;
    extern unsigned int port;

    extern bool isConnected;
    extern io_context asyncIO;
    extern tcp_socket socket;
    extern error_code currentNetworkError;

    extern streambuf currentBuffer;
}

namespace Settings {
    extern bool areSettingsLoaded;
    extern const std::string settingsPath;
}

namespace Language {
    extern const std::string languagePath;
    extern std::unique_ptr<LanguageResource> languageResource;
}

#endif // CONSTANTS_HPP
