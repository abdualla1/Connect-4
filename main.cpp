// Program: Connect 4 game , display board and allow 2 playesr to play in terms of X and O


// Author:  Abdualla ayman, S3,4, 20230226


// Version: v3.0


// Date:    2/3/2024
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
// Constants for grid size
const int I = 6;
const int J = 7;
// Vector to represent the game grid
vector<char> Grid(I * J, ' ');
// Function to display the game grid
void display() {
    for (int i = I - 1; i >= 0; --i) {
        for (int j = 0; j < J; ++j) {
            cout << Grid[i * J + j] << '|';
        }
        cout << endl;
    }
    cout << "-------------" << endl;
    cout << "1 2 3 4 5 6 7" << endl;
}

// Function to handle player's turn
bool turn(int column, char player) {
    for (int i = 0; i < I; ++i) {
        if (Grid[i * J + column - 1] == ' ') {
            Grid[i * J + column - 1] = player;
            return true;
        }
    }
    return false;
}

// Function to check if a player has won
bool isWinner(char player) {
    // Check horizontally
    for (int i = 0; i < I; ++i) {
        for (int j = 0; j <= J - 4; ++j) {
            if (Grid[i * J + j] == player && Grid[i * J + j] == Grid[i * J + j + 1] &&
                Grid[i * J + j] == Grid[i * J + j + 2] && Grid[i * J + j] == Grid[i * J + j + 3]) {
                return true;
            }
        }
    }
    // Check vertically
    for (int i = 0; i <= I - 4; ++i) {
        for (int j = 0; j < J; ++j) {
            if (Grid[i * J + j] == player && Grid[i * J + j] == Grid[(i + 1) * J + j] &&
                Grid[i * J + j] == Grid[(i + 2) * J + j] && Grid[i * J + j] == Grid[(i + 3) * J + j]) {
                return true;
            }
        }
    }
    // Check diagonally
    for (int i = 0; i <= I - 4; ++i) {
        for (int j = 0; j <= J - 4; ++j) {
            if (Grid[i * J + j] == player && Grid[i * J + j] == Grid[(i + 1) * J + j + 1] &&
                Grid[i * J + j] == Grid[(i + 2) * J + j + 2] && Grid[i * J + j] == Grid[(i + 3) * J + j + 3]) {
                return true;
            }
        }
    }
    for (int i = 0; i <= I - 4; ++i) {
        for (int j = 3; j < J; ++j) {
            if (Grid[i * J + j] == player && Grid[i * J + j] == Grid[(i + 1) * J + j - 1] &&
                Grid[i * J + j] == Grid[(i + 2) * J + j - 2] && Grid[i * J + j] == Grid[(i + 3) * J + j - 3]) {
                return true;
            }
        }
    }
    return false;
}

// Function to get valid input from the player
int prmpt() {
    int column;
    cout << "Pick a column: ";
    while (!(cin >> column) || column < 1 || column > 7) {
        cout << "Invalid input. Please choose a column between 1 and 7: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return column;
}

int main() {
    cout <<"Welcome to Connect four" << endl;
    // Player names input
    string player1, player2;
    cout << "Enter name for Player 1: " << endl;
    cin >> player1;
    cout << "Enter name for Player 2: " << endl;
    cin >> player2;

    char playing = 'X'; // Player X starts the game
    while (true) {
        display(); // Display the game grid
        int column = prmpt(); // Get column choice from the player

        // If the turn is successful
        if (turn(column, playing)) {
            // Check if the current player has won
            if (isWinner(playing)) {
                display(); // Display the winning grid
                cout << "Player " << (playing == 'X' ? player1 : player2) << " wins!" << endl; // Display the winner
                break; // End the game
            }
            // Switch to the next player
            playing = (playing == 'X') ? 'O' : 'X';
        } else {
            cout << "Can't Play Here, Pick Again" << endl; // Inform the player if the chosen column is full
        }
    }
    return 0;
}
