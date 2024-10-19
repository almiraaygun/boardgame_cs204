//
// Created by Asus on 29.08.2024.
//

#ifndef CS204_HW5_BOARD_H
#define CS204_HW5_BOARD_H
using namespace std;
#include <iostream>
#include <string>



// Node structure for the circular linked list
struct Node {
    string owner;  // The owner of this slot ("Ali", "Liz", or "None")
    Node* next;    // Pointer to the next node (slot) in the circular linked list


    // Constructor with default parameters
    Node(string o = "None", Node* p = nullptr) : owner(o), next(p) {}
};

class Board {
private:
    Node* first;  // Pointer to the first node in the circular linked list
    int numSlots;

public:
    // Constructor to initialize the board with a specific number of slots
    Board(int numberOfSlots);

    // Destructor to clean up the circular linked list
    ~Board();

    // Function to determine who owns a specific slot
    string who_owns(Node* node) const;

    // Function to display the ownership of all slots on the board
    void display() const;

    // Function to return the first node (useful for initializing players' positions)
    Node* getFirst() const;
};


#endif

