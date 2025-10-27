#include <iostream>
#include <vector>

// Clears the console screen (cross-platform)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to print the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    clearScreen();
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << std::endl;
    std::cout << "     |     |     " << std::endl;
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // If any cell is not X or O, game is not a draw
            }
        }
    }
    return true; // All cells are filled
}

int main() {
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        std::vector<std::vector<char>> board = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
        };
        char currentPlayer = 'X';
        bool gameIsOver = false;

        while (!gameIsOver) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            int move;
            std::cin >> move;

            // Input validation
            if (std::cin.fail() || move < 1 || move > 9) {
                std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
                std::cin.clear(); // Clear error flags
                std::cin.ignore(10000, '\n'); // Discard bad input
                continue;
            }

            // Convert move (1-9) to board coordinates (0-2)
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            // Check if the cell is already taken
            if (board[row][col] == 'X' || board[row][col] == 'O') {
                std::cout << "This cell is already taken. Try again." << std::endl;
                // A small delay to let the user read the message
                for(long i = 0; i < 900000000; ++i) {} 
                continue;
            }

            // Update board
            board[row][col] = currentPlayer;

            // Check for win
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                gameIsOver = true;
            } 
            // Check for draw
            else if (checkDraw(board)) {
                displayBoard(board);
                std::cout << "The game is a draw!" << std::endl;
                gameIsOver = true;
            } 
            // Switch players
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        // Ask to play again
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    }

    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}
