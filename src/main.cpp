#include "cialloo/a2s.hpp"
#include <iostream>

int main()
{
    cialloo::a2s::client client("82.156.11.240", "27015");
    auto p = client.get_info();
    if(p.get() == nullptr)
        std::cout << "NULL PTR\n";
    else
        std::cout << "GET INFO\n";
}