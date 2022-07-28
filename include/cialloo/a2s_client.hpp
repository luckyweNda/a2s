#ifndef CIALLOO_A2S_CLIENT_HPP
#define CIALLOO_A2S_CLIENT_HPP

#include <boost/asio.hpp>
#include "cialloo/a2s.hpp"
#include <string>
#include <memory>

namespace cialloo {
namespace a2s {

class client
{
    net::io_context io_;
    net::ip::udp::socket socket_;
    net::ip::udp::endpoint endpoint_;
    net::ip::udp::resolver resolver_;
    net::ip::udp::resolver::results_type target_;
public:
    client(std::string host, std::string port);
    ~client();
    client(const client&) = delete;
    client operator=(const client&) = delete;
};



} // namespace a2s
} // namespace cialloo

#endif // CIALLOO_A2S_CLIENT_HPP