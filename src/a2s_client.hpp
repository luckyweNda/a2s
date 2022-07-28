#include "cialloo/a2s.hpp"

namespace cialloo {
namespace a2s {

client::client(std::string host, std::string port)
    : socket_(io_, net::ip::udp::v4()),
      resolver_(io_)
{
    target_ = resolver_.resolve(host, port);
}

} // namespace a2s
} // namespace cialloo