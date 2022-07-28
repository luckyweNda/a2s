#include "cialloo/a2s.hpp"
#include <chrono>
#include <iostream>

namespace cialloo {
namespace a2s {

client::client(std::string host, std::string port)
    : socket_(io_, net::ip::udp::v4()),
      resolver_(io_),
      timeout_(A2S_DEFAULT_TIMEOUT)
{
    target_ = resolver_.resolve(host, port);
}

client::~client()
{
    socket_.close();
    io_.stop();
}

std::shared_ptr<a2s_info> client::get_info()
{
    std::shared_ptr<a2s_info> info_p{nullptr};
    std::unique_ptr<unsigned char[]> info_byte =  std::make_unique<unsigned char[]>(A2S_PACKET_MAX_SIZE);
    socket_.send_to(net::buffer(query_info), *target_);
    socket_.async_receive_from(net::buffer(info_byte.get(), A2S_PACKET_MAX_SIZE), endpoint_, [this, &info_byte, &info_p](boost::system::error_code error, std::size_t bytes_recvd){
        if(error || bytes_recvd < 4) 
            std::cout << "Error with receive info: " << error.message() << std::endl << "receive bytes: " << bytes_recvd << std::endl;
        else 
            info_p = std::make_shared<a2s_info>(process_info(info_byte));
    });
    check_for_timeout();

    return info_p;
}

void client::check_for_timeout()
{
    io_.restart();
    io_.run_for(std::chrono::milliseconds(timeout_));
    if(!io_.stopped())
    {
        socket_.cancel();
        io_.stop();
    }
}

a2s_info client::process_info(std::unique_ptr<unsigned char[]>& ptr)
{
    a2s_info info;
    uint16_t i = 6;
    while(ptr[i] != '\0')
    {
        info.name += static_cast<char>(ptr[i]);
        i++;
    }
    i++;
    while(ptr[i] != '\0')
    {
        info.map += static_cast<char>(ptr[i]);
        i++;
    }
    i++;
    while(ptr[i] != '\0')
    {
        info.folder += static_cast<char>(ptr[i]);
        i++;
    }
    i++;
    while(ptr[i] != '\0')
    {
        info.game += static_cast<char>(ptr[i]);
        i++;
    }
    i++;
    info.id = bytes_to_int16(ptr.get() + i);
    i++;
    i++;
    info.players = static_cast<uint16_t>(ptr[i]);
    i++;
    info.max_players = static_cast<uint16_t>(ptr[i]);
    i++;
    info.bots = static_cast<uint16_t>(ptr[i]);
    i++;
    info.server_type = ptr[i];
    i++;
    info.environment = ptr[i];
    i++;
    info.visibility = (0b1 & ptr[i]);
    i++;
    info.vac = (0b1 & ptr[i]);
    
    return info;
}

int16_t client::bytes_to_int16(unsigned char* p)
{
    return static_cast<int16_t>(*p | *(p + 1) << 8);
}

void client::set_timeout(uint32_t time)
{
    timeout_ = time;
}

} // namespace a2s
} // namespace cialloo