#include <iostream>

int main()
{
    std::cout << "Please enter a number.\n> ";
    int number{};
    std::cin >> number;
    std::cout << "You entered: " << number << "\n";
}