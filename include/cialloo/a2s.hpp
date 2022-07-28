#ifndef CIALLOO_A2S_HPP
#define CIALLOO_A2S_HPP

#include <boost/asio.hpp>
#include "cialloo/a2s_client.hpp"
#include "cialloo/a2s_info.hpp"

#define A2S_PACKET_MAX_SIZE 1400
#define A2S_DEFAULT_TIMEOUT 200         // milisecond

namespace cialloo {
namespace a2s {

namespace net = boost::asio;

const unsigned char query_info[] = {0xFF, 0xFF, 0xFF, 0xFF, 0x54, 
                                    0x53, 0x6F, 0x75, 0x72, 0x63, 
                                    0x65, 0x20, 0x45, 0x6E, 0x67, 
                                    0x69, 0x6E, 0x65, 0x20, 0x51, 
                                    0x75, 0x65, 0x72, 0x79, 0x00};

} // namespace a2s
} // namespace cialloo

#endif // CIALLOO_A2S_HPP