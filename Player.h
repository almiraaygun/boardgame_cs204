//
// Created by Asus on 29.08.2024.
//

#ifndef CS204_HW5_PLAYER_H
#define CS204_HW5_PLAYER_H
#include <iostream>
#include "Board.h"
using namespace std;
class Player {

private:

    string name;      // Player's name ("Ali" or "Liz")
    int balance;      // Player's current balance
    Node* currentPos; // Pointer to the current position of the player on the board
    Board& board;     // Reference to the shared Board object


public:
    // Constructor: Initializes the player's name, balance, and starting position
    Player(Board& b, const string& playerName, int initialBalance);

    // Moves the player a given number of steps on the board
    // Returns 1 if the player passes the starting slot, 0 otherwise
    int move(int steps);

    // Returns a pointer to the current position of the player on the board
    Node* where_am_I() const;

    // Transfers money from this player to another player
    void pay_to_player(Player& otherPlayer, int amount);

    // Returns the player's current balance
    int get_balance() const;

    // Deposits a given amount of money into the player's balance
    void deposit_money(int amount);

    // Buys the slot the player is currently on, deducting the price from their balance
    void buy_slot(int price);

    // Checks if the player is bankrupt (i.e., balance < 0)
    bool is_bankrupt() const;

    // Displays the player's name and balance
    void display() const;
};


#endif //CS204_HW5_PLAYER_H
