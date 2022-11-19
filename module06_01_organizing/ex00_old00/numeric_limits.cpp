#include <limits>
#include <cstddef>
#include <iostream>


#include<bits/stdc++.h> // overflow

int main()
{
    std::cout << "short: " << std::dec << std::numeric_limits<short>::max() <<"\n"
              << "      "  << std::dec << std::numeric_limits<short>::min() <<"\n"
//              << " or " << std::hex << std::showbase << std::numeric_limits<short>::max() << '\n'
              << "int: " << std::dec << std::numeric_limits<int>::max() <<"\n"
              << "    "  << std::dec << std::numeric_limits<int>::min() <<"\n"
              << "long: " << std::dec << std::numeric_limits<long>::max() <<"\n"
              << "long: " << std::dec << LONG_MAX <<"\n"
//              << " or " << std::hex << std::numeric_limits<int>::max() << '\n' << std::dec
//              << "streamsize: " << std::dec << std::numeric_limits<std::streamsize>::max() <<"\n"
//              << " or " << std::hex << std::numeric_limits<std::streamsize>::max() << '\n'
              << "size_t: " << std::dec << std::numeric_limits<std::size_t>::max() <<"\n"
//              << " or " << std::hex << std::numeric_limits<std::size_t>::max() << '\n'
              << "float: " << std::numeric_limits<float>::max() <<"\n"
//              << " or " << std::hexfloat << std::numeric_limits<float>::max() << '\n'
              << "double: " << std::defaultfloat << std::numeric_limits<double>::max() <<"\n";
//              << " or " << std::hexfloat << std::numeric_limits<double>::max() << '\n';
}