#ifndef CIALLOO_A2S_CLIENT_HPP
#define CIALLOO_A2S_CLIENT_HPP

#include <boost/asio.hpp>
#include "cialloo/a2s.hpp"
#include "cialloo/a2s_info.hpp"
#include <string>
#include <memory>

namespace cialloo {
namespace a2s {

namespace net = boost::asio;

class client
{
    uint32_t timeout_;
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

    /**
     * @return      return a2s_info structure, if timeout or error will get nullptr
     */
    std::shared_ptr<a2s_info> get_info();
    
    void set_timeout(uint32_t time);

private:
    a2s_info process_info(std::unique_ptr<unsigned char[]>& p);
    void check_for_timeout();
    int16_t bytes_to_int16(unsigned char*);
};



} // namespace a2s
} // namespace cialloo

#endif // CIALLOO_A2S_CLIENT_HPP