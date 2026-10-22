#include <iostream>
#include "receipt.hpp"
using namespace receipt;

enum ItemAction {
    AddItem = 1, 
    DeleteItem = 2, 
    Show = 3, 
    BackToReceipt = 4
};

enum ReceiptAction {
    NewReceipt = 1, 
    DeleteReceipt = 2, 
    Exit = 3
};

void NewReceiptSwitch(std::unique_ptr<Receipt>& receipt) {
    ItemAction itemAction;
    int input;
    if (!receipt) 
    {
        receipt = std::make_unique<Receipt>();
    }
    do {
        std::cout << "1. Добавить позицию чека\n";
        std::cout << "2. Удалить позицию чека\n"; 
        std::cout << "3. Вывести все\n";
        std::cout << "4. Вернуться к чекам\n";
        std::cout << "Выберите пункт: ";
        std::cin >> input;
        itemAction = static_cast<ItemAction>(input);
        switch (itemAction) {
        case AddItem:
            receipt->AddNewItem();
            break;
        case DeleteItem:
            receipt->DeleteItem();
            break;
        case Show:
            receipt->ShowAll();
            break; 
        case BackToReceipt:
            std::cout << "\n";
            break;
        }
    } while (itemAction != BackToReceipt);
    return;
}

int main() {
    int input;
    ReceiptAction receiptAction;
    std::unique_ptr<Receipt> receipt;
    do {
        std::cout << "1. Создать чек\n";
        std::cout << "2. Удалить чек\n";
        std::cout << "3. Выход\n";
        std::cout << "Выберите пункт: ";
        std::cin >> input;
        receiptAction = static_cast<ReceiptAction>(input);
        switch (receiptAction) {
        case NewReceipt:
            NewReceiptSwitch(receipt);
            break;
        case DeleteReceipt:
            if (receipt) 
            {
                receipt = nullptr;
            } 
            else 
            {
                std::cout << "Чек еще не создан.\n";
            }
            break;
        case Exit:
            std::cout << "Работа завершена.\n";
            break;
        }
    } while (receiptAction != Exit);

    return 0;
}