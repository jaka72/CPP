#include <array>
#include <iostream>
#include <string_view>
#include <tuple>
#include <type_traits>

// namespace a::b::c
// {
//     inline constexpr std::string_view str{ "hello" };
// }

// template <class... T>
// std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args)
// {
//     return { sizeof...(T), (args + ...) };
// }

int main()
{
    // auto [iNumbers, iSum]{ sum(1, 2, 3) };
    // std::cout << a::b::c::str << ' ' << iNumbers << ' ' << iSum << '\n';

    // std::array arr{ 1, 2, 3 };

    // std::cout << std::size(arr) << '\n';

    //////////////////////////////////////////////////////////
    // int a;
    // int b = 3;

    // int c {};
    // int d {0};

    // int e ();
    // int f (4);

    // std::cout << a << b << c << d << e << f;

    // printf("\naaaaa\n");

    ////////////////////////////////////////////////////////////////

    std::cout << "Enter two numbers separated by a space: ";

    int x{};            // define variable x to hold user input (and zero-initialize it)
    int y{};            // define variable y to hold user input (and zero-initialize it)
    std::cin >> x >> y; // get two numbers and store in variable x and y respectively
    std::cout << "You entered " << x << " and " << y << '\n';

    std::cout << "\naaa"
                 "bbb\n";

    return 0;
}