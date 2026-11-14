#pragma ence
#include "cell.h"
#include <vector>

struct Board{
    std::vector<Cell> cells = {
    {"Старт",             CellType::Start,    0,   200, 0}, 
    {"Заводская",         CellType::Street,   60,  10,  1},
    {"Шанс",              CellType::Chance,   0,   0,   0}, 
    {"Складская",         CellType::Street,   60,  10,  1},
    {"Подоходный налог",  CellType::Tax,      0,   200, 0},
    {"Вокзал 1",          CellType::Station,  200, 25,  0},
    {"Парковая",          CellType::Street,   100, 15,  2},
    {"Шанс",              CellType::Chance,   0,   0,   0},
    {"Лесная",            CellType::Street,   100, 15,  2},
    {"Речная",            CellType::Street,   120, 20,  2},
    {"Тюрьма",            CellType::Jail,     0,   0,   0},
    {"Садовая",           CellType::Street,   140, 20,  3},
    {"Электростанция",    CellType::Utility,  150, 0,   0},
    {"Школьная",          CellType::Street,   140, 20,  3}, 
    {"Студенческая",      CellType::Street,   160, 25,  3}, 
    {"Вокзал 2",          CellType::Station,  200, 25,  0}, 
    {"Рабочая",           CellType::Street,   180, 30,  4}, 
    {"Шанс",              CellType::Chance,   0,   0,   0}, 
    {"Торговая",          CellType::Street,   180, 30,  4}, 
    {"Центральная",       CellType::Street,   200, 35,  4}, 
    {"Парковка",          CellType::Parking,  0,   0,   0}, 
    {"Набережная",        CellType::Street,   220, 35,  5}, 
    {"Шанс",              CellType::Chance,   0,   0,   0}, 
    {"Театральная",       CellType::Street,   220, 35,  5},
    {"Проспект Мира",     CellType::Street,   240, 40,  5}, 
    {"Вокзал 3",          CellType::Station,  200, 25,  0}, 
    {"Арбат",             CellType::Street,   260, 40,  6}, 
    {"Тверская",          CellType::Street,   260, 40,  6}, 
    {"Водоканал",         CellType::Utility,  150, 0,   0}, 
    {"Кутузовский",       CellType::Street,   280, 45,  6}, 
    {"Иди в тюрьму",      CellType::GoToJail, 0,   0,   0}, 
    {"Рублёвка",          CellType::Street,   300, 50,  7}, 
    {"Пушкинская",        CellType::Street,   300, 50,  7}, 
    {"Шанс",              CellType::Chance,   0,   0,   0}, 
    {"Красная площадь",   CellType::Street,   320, 55,  7}, 
    {"Вокзал 4",          CellType::Station,  200, 25,  0}, 
    {"Шанс",              CellType::Chance,   0,   0,   0}, 
    {"Кремлёвская",       CellType::Street,   350, 60,  8}, 
    {"Роскошный налог",   CellType::Tax,      0,   100, 0}, 
    {"Золотая миля",      CellType::Street,   400, 75,  8}, 
    };
    Cell& getCell(int index) {
        return cells[index % cells.size()];
    }
    int calcRent(const Cell& cell, double multiplier, int ownStations = 0,int diceRoll = 0, int ownedUtilities = 0) {
        switch (cell.type) {
            case CellType::Street:
                return static_cast<int>(cell.rent * multiplier);

            case CellType::Station: {
                const int stationRents[] = {25, 50, 100, 200};
                if (ownStations >= 1 && ownStations <= 4) {
                    return static_cast<int>(stationRents[ownStations - 1] * multiplier);
                }   
                return 0;
            }
            case CellType::Utility: {
                int factor = (ownedUtilities >= 2) ? 10 : 4;
                return static_cast<int>(diceRoll * factor * multiplier);
            }

            case CellType::Tax:
                return cell.rent;

            default:
                return 0;

        }
    };
    int calcPrice(const Cell& cell,double multiplier){
        return static_cast<int>(cell.price * multiplier);
    }   
};