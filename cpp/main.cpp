#include <iostream>
#include "shift.hpp"

using namespace shift;

enum ShiftActions 
{
    CreateReceipt = 1, 
    PrintReport = 2, 
    BackTo = 3
};

enum Action 
{
    OpenShift = 1, 
    CloseShift = 2, 
    Exit = 3
};

void ShiftSwitch(std::unique_ptr<Shift>& shift) 
{
    ShiftActions shiftActions;
    int input;
    if (!shift) 
    {
        shift = std::make_unique<Shift>();
    }
    do {
        std::cout << "1. Создать новый чек\n"; 
        std::cout << "2. X-отчет\n";
        std::cout << "3. Вернуться к смене\n";
        std::cout << "Выберите пункт: ";
        std::cin >> input;
        shiftActions = static_cast<ShiftActions>(input);
        switch (shiftActions) {
        case CreateReceipt:
            shift->CreateNewReceipt();
            break;
        case PrintReport:
            shift->PrintXReport();
            break;
        case BackTo:
            std::cout << "\n";
            break;
        }
    } while (shiftActions != BackTo);
    return;
}

int main() {
    int input;
    Action action;
    std::unique_ptr<Shift> shift;
    do {
        std::cout << "1. Открыть/Продолжить смену\n";
        std::cout << "2. Закрыть смену\n";
        std::cout << "3. Выход\n";
        std::cout << "Выберите пункт: ";
        std::cin >> input;
        action = static_cast<Action>(input);
        switch (action) {
        case OpenShift:
            ShiftSwitch(shift);
            break;
        case CloseShift:
            if (shift) 
            {
                shift = nullptr;
            } 
            else 
            {
                std::cout << "Смена еще не создана.\n";
            }
            break;
        case Exit:
            std::cout << "Работа завершена.\n";
            break;
        }
    } while (action != Exit);

    return 0;
}