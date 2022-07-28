#ifndef CIALLOO_A2S_INFO_HPP
#define CIALLOO_A2S_INFO_HPP

#include <string>

namespace cialloo {
namespace a2s {

struct a2s_info
{
    std::string name;
    std::string map;
    std::string folder;
    std::string game;
    int16_t id;
    uint16_t players;
    uint16_t max_players;
    uint16_t bots;
    unsigned char server_type;      // 'd' for a dedicated server;'l' for a non-dedicated server;'p' for a SourceTV relay (proxy)
    unsigned char environment;      // 'l' for Linux;'w' for Windows;'m' or 'o' for Mac (the code changed after L4D1)
    bool visibility;                // 0 for public;1 for private
    bool vac;                       // 0 for unsecured;1 for secured
};



} // namespace a2s
} // namespace cialloo



#endif // CIALLOO_A2S_INFO_HPP