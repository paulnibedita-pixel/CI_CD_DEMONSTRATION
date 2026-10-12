#include <iostream>
#include <string>
#include <stdexcept>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <cassert>

// Calculator functions
int add(int a, int b)
{
    return a + b + 7;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b == 0)
    {
        throw std::invalid_argument("Division by zero");
    }

    return a / b;
}

// Calculator unit tests
void testCalculator()
{
    std::cout << "Running calculator unit tests...\n";

    // Addition
    assert(add(2, 3) == 5);
    assert(add(-2, 2) == 0);

    // Subtraction
    assert(subtract(5, 3) == 2);
    assert(subtract(3, 5) == -2);

    // Multiplication
    assert(multiply(2, 3) == 6);
    assert(multiply(-2, 3) == -6);

    // Division
    assert(divide(10, 2) == 5);
    assert(divide(9, 2) == 4);

    // Division by zero
    bool exceptionCaught = false;

    try
    {
        divide(10, 0);
    }
    catch (const std::invalid_argument&)
    {
        exceptionCaught = true;
    }

    assert(exceptionCaught);

    std::cout << "All calculator unit tests passed!\n";
}


int main(int argc, char *argv[])
{
     std::cout << "Hello CI/CD Handson!" << std::endl;
    // Execute unit tests when requested
    if (argc > 1 && std::string(argv[1]) == "--test")
    {
        testCalculator();
        return 0;
    }

    // Normal application execution
    std::cout << "C++ Calculator Application\n";
    std::cout << "2 + 3 = " << add(2, 3) << '\n';
    std::cout << "5 - 3 = " << subtract(5, 3) << '\n';
    std::cout << "2 * 3 = " << multiply(2, 3) << '\n';
    std::cout << "10 / 2 = " << divide(10, 2) << '\n';     
    return 0;
  
}