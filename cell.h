#pragma once
#include <string>

enum class CellType{
    Start,
    Street,
    Station,
    Utility,
    Tax,
    Chance,
    Jail,
    GoToJail,
    Parking
};
struct Cell{
    std::string name;
    CellType type;
    int price;
    int rent;
    int group;
    int owner = -1;
};