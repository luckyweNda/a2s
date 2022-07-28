#include "cialloo/a2s.hpp"
#include <iostream>

int main()
{
    cialloo::a2s::client client("49.233.47.147", "27015");
    auto p = client.get_info();
    if(p.get() == nullptr)
        std::cout << "NULL PTR\n";
    else
        std::cout << "GET INFO\n";

    std::cout << (*p).name << '\t'
              << (*p).map << '\t'
              << (*p).folder << '\t'
              << (*p).game << '\t'
              << (*p).id << '\t'
              << (*p).players << '\t'
              << (*p).max_players << '\t'
              << (*p).bots << '\t'
              << '\n';

    std::cout << "server type: " << (*p).server_type << '\t' << "env: " << (*p).environment << std::endl;
    if(!(*p).visibility)
        std::cout << "public" << std::endl;
    else
        std::cout << "private" << std::endl;
    if(!(*p).vac)
        std::cout << "secure" << std::endl;
    else 
        std::cout << "insecure\n";
}