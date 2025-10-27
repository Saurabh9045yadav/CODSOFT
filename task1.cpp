#include <iostream>
#include <cstdlib>
#include <ctime>


void guessTheNumber() {
    
    std::srand(static_cast<unsigned int>(std::time(0)));

    const int secretNumber = (std::rand() % 100) + 1;
    int guess = 0;
    int attempts = 0;

    std::cout << "--- Number Guessing Game ---" << std::endl;
    std::cout << "I have generated a random number between 1 and 100." << std::endl;
    std::cout << "Can you guess it?" << std::endl;

    
    while (guess != secretNumber) {
        std::cout << "\nEnter your guess: ";
        
        if (!(std::cin >> guess)) {
            
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue; 
        }

        attempts++;

        if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "\nCongratulations! You guessed the number " << secretNumber << " correctly!" << std::endl;
            std::cout << "It took you " << attempts << " attempts." << std::endl;
        }
    }
}

int main() {
    guessTheNumber();
    return 0;
}