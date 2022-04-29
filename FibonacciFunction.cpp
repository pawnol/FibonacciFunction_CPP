/*
Fibonacci Function
Pawelski
4/29/2022
Please follow the instructions on the activity guide.
*/

#include <iostream>
#include <string>
#include <stdexcept>

/// <summary>
/// Calculates the Fibonacci number at the given position.
/// </summary>
/// <param name="position">Position of number in the sequence. Should be >= 1.</param>
/// <returns>Fibonacci number at the given position.</returns>
unsigned long long int Fibonacci(int position)
{
    if (position == 1)
    {
        return 0;
    }
    else if (position == 2 || position == 3)
    {
        return 1;
    }
    else if (position > 3)
    {
        unsigned long long int previous1 = 1;
        unsigned long long int previous2 = 1;
        unsigned long long int current;
        for (int i = 3; i < position; i++)
        {
            current = previous1 + previous2;
            previous2 = previous1;
            previous1 = current;
        }
        return current;
    }
    else
    {
        throw std::invalid_argument("Invalid argument. Position must be >= 1.");
    }
}

int main()
{
    std::string repeat;
    do
    {
        int position;
        std::cout << "What position do you want to calculate? >> ";
        std::cin >> position;
        try
        {
            std::cout << "The Fibonacci number at " << position << " is: " 
                << Fibonacci(position) << std::endl;
        }
        catch (std::invalid_argument e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "Do you want to calculate another position? (y/n) >> ";
        std::cin >> repeat;
    } while (repeat == "y");
}
