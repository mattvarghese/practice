#include <iostream>
#include <vector>
#include "05_input.h"
std::vector<double> get_prices(std::istream &input_stream)
{
    std::cout << "Please enter some numbers.\n>";
    std::vector<double> numbers{};
    auto number = stock_prices::get_number(input_stream);
    while (number.has_value())
    {
        numbers.push_back(number.value());
        std::cout << '>';
        number = stock_prices::get_number(input_stream);
    }
    return numbers;
}
int main()
{
    auto prices = get_prices(std::cin);
}