#ifndef CIALLOO_A2S_PLAYER_HPP
#define CIALLOO_A2S_PLAYER_HPP

#include <string>
#include <vector>

namespace cialloo {
namespace a2s {

struct a2s_player
{
    uint16_t index;
    std::string name;
    int32_t score;
    float duration;
};


} // namespace a2s
} // namespace cialloo


#endif