#include <iostream>
#include "board.h"

int main() {
    Board board;

    int i = 0;
    for (const Cell& c : board.cells) {
        std::cout << i << ". " << c.name
                  << " | цена: " << c.price
                  << " | рента: " << c.rent
                  << " | группа: " << c.group << "\n";
        i++;
    }
    
    return 0;
}