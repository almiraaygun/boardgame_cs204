#include "Player.h"
#include "Board.h"
#include <iostream>

using namespace std;

// Constructor: Initializes the player's name, balance, and starting position
Player::Player(Board& b, const string& playerName, int initialBalance)
        : board(b), name(playerName), balance(initialBalance) {
    currentPos = board.getFirst(); // Start the player at the first slot on the board
}

// Moves the player a given number of steps on the board
// Returns 1 if the player passes the starting slot, 0 otherwise
int Player::move(int steps) {
    bool passedStart = false;

    for (int i = 0; i < steps; ++i) {
        currentPos = currentPos->next;
        if (currentPos == board.getFirst()) {
            passedStart = true; // Player passed the starting slot
        }
    }

    return passedStart ? 1 : 0;
}

// Returns a pointer to the current position of the player on the board
Node* Player::where_am_I() const {
    return currentPos;
}

// Transfers money from this player to another player
void Player::pay_to_player(Player& otherPlayer, int amount) {
    balance -= amount;
    otherPlayer.balance += amount;
}

// Returns the player's current balance
int Player::get_balance() const {
    return balance;
}

// Deposits a given amount of money into the player's balance
void Player::deposit_money(int amount) {
    balance += amount;
}

// Buys the slot the player is currently on, deducting the price from their balance
void Player::buy_slot(int price) {
    if (currentPos->owner == "None" && balance >= price) {
        currentPos->owner = name;
        balance -= price;
    }
}

// Checks if the player is bankrupt (i.e., balance < 0)
bool Player::is_bankrupt() const {
    return balance < 0;
}

// Displays the player's name and balance
void Player::display() const {
    Node* first = board.getFirst();
    Node* p = first;

    int curr_position = 0;

    while (p!= currentPos) {
        curr_position++;
        p = p->next;
    }


    for (int i = 0; i < curr_position; i++)
    {
        cout << "      ";
    }

    cout << name <<" "<<balance << endl;
}