//
// Created by Asus on 29.08.2024.
//
#include <iostream>
#include "Board.h"
#include "Player.h"
#include <iomanip>
using namespace std;
#include <iostream>

Board::Board(int numberOfSlots) {
    int numSlots = numberOfSlots;
    // p1 = nullptr;
    // p2 = nullptr;
    first = new Node();
    Node* current = first;
    for (int i = 1; i < numberOfSlots; i++) {
        current->next = new Node();
        current = current->next;
    }
    current->next = first;
}

Board::~Board() {
    Node* current = first;
    Node* nextNode;

    do {
        nextNode = current->next;  // Store the pointer to the next node
        delete current;            // Delete the current node
        current = nextNode;        // Move to the next node
    } while (current != first);    // Continue until the loop is back at the start
}

string Board::who_owns(Node *node) const {
    return node->owner;
}

Node *Board::getFirst() const {
    return first;
}

#include "Board.h"
#include "Player.h"

void Board::display() const {
    Node* p ;
    int numberOfSlots = 0;
    p = first;

    // Calculate the number of slots for dynamic arrow display
    do {
        numberOfSlots++;
        p = p->next;
    } while (p != first);

    do {
        cout << left << setw(4) << (p->owner);
        if (p->next != first) cout << "->"; // Formatting for arrows between slots
        p = p->next;
    } while (p != first);
    cout << endl;

    cout << "^" << right << setw((numberOfSlots * 6) - 3) << "|" << endl;
    cout << "|";
    cout << "----";

    for (int i = 1; i < (numberOfSlots - 1); i++) {
        cout << "<-----";
    }
    cout << "<---v" << endl;
}
