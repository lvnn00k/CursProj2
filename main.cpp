#include <iostream>
#include "receipt.hpp"
using namespace receipt;

int main() {
    int choice;
    Receipt* rec = nullptr;
    do {
        std::cout << "1. Создать чек\n";
        std::cout << "2. Удалить чек\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите пункт: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            if (!rec) 
            {
                rec = new Receipt();
            }
            int recChoice;
            do {
                std::cout << "1. Добавить позицию чека\n";
                std::cout << "2. Удалить позицию чека\n"; 
                std::cout << "3. Вывести все\n";
                std::cout << "0. Вернуться к чекам\n";
                std::cout << "Выберите пункт: ";
                std::cin >> recChoice;
                switch (recChoice) {
                case 1:
                    rec->AddNewItem();
                    break;
                case 2:
                    rec->DeleteItem();
                    break;
                case 3:
                    rec->ShowAll();
                    break; 
                case 0:
                    std::cout << "-----------------------------\n";
                    break;
                default:
                    std::cout << "Такого пункта нет.\n";
                }
            } while (recChoice != 0);
            break;
        case 2:
            if (rec) 
            {
                delete rec;
                rec = nullptr;
            } 
            else 
            {
                std::cout << "Чек еще не создан.\n";
            }
            break;
        case 0:
            std::cout << "Работа завершена.\n";
            break;
        default:
            std::cout << "Такого пункта нет.\n";
        }
    } while (choice != 0);

    return 0;
}