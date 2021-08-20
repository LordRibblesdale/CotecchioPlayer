/* Created by LordRibblesdale on 19/08/2021.
 * MIT License
 */

#ifndef COTECCHIOPLAYER_TRANSCODER_HPP
#define COTECCHIOPLAYER_TRANSCODER_HPP

#include <string>

enum Command {
    LOGIN,
    LOGOUT
};

class Transcoder {
public:
    std::string static encode(const Command& command);
    void static decode(const std::string& input);
};


#endif //COTECCHIOPLAYER_TRANSCODER_HPP
