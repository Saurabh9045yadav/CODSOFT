#include <iostream>
#include <limits>

int main() {
    
    double num1, num2, result;
    char operation;
    bool validInput = false;

    std::cout << "--- Basic Arithmetic Calculator ---\n";

    while (!validInput) {
        std::cout << "Enter the first number: ";
        if (std::cin >> num1) {
            validInput = true;
        } else {
            std::cout << "Invalid input. Please enter a valid number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    validInput = false; 

    while (!validInput) {
        std::cout << "Enter the second number: ";
        if (std::cin >> num2) {
            validInput = true;
        } else {
            std::cout << "Invalid input. Please enter a valid number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << "\nChoose an operation (+, -, *, /): ";
    std::cin >> operation;

    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "\nResult: " << num1 << " + " << num2 << " = " << result << std::endl;
            break;

        case '-':
            result = num1 - num2;
            std::cout << "\nResult: " << num1 << " - " << num2 << " = " << result << std::endl;
            break;

        case '*':
            result = num1 * num2;
            std::cout << "\nResult: " << num1 << " * " << num2 << " = " << result << std::endl;
            break;

        case '/':

            if (num2 != 0) {
                result = num1 / num2;
                std::cout << "\nResult: " << num1 << " / " << num2 << " = " << result << std::endl;
            } else {
                std::cout << "\nError: Division by zero is undefined.\n";
            }
            break;

        default:
            
            std::cout << "\nError: Invalid operation selected. Please choose +, -, *, or /.\n";
            break;
    }

    std::cout << "\nProgram finished.\n";
    return 0; 
}