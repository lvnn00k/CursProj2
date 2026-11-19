#include "shift.hpp"

namespace shift 
{
Shift::~Shift() 
{
    Z_Report z_report;
    z_report.Print(m_receipts, m_arraySize);
    X_Report x_report;
    x_report.ResetCount();
    std::cout << "\nСмена закрыта" << std::endl;
}

void Shift::PrintXReport()
{
    X_Report report;
    report.Print(m_receipts, m_arraySize);
}

void Shift::CreateNewReceipt() 
{
    int input;
    std::cout << "1. Чек прихода\n2. Чек возврата\n3. Вернуться назад\nВведите тип создаваемого чека: ";
    std::cin >> input;
    std::unique_ptr<receipt::BaseReceipt> newReceipt;
    switch(input) 
    {
        case 1:
            newReceipt = std::make_unique<receipt::Receipt>();
            NewReceiptActions(newReceipt);
            break;
        case 2: 
            double returnSum;
            std::cout << "Введите сумму возврата: ";
            std::cin >> returnSum;
            newReceipt = std::make_unique<receipt::ReturnReceipt>(returnSum);
            break;
        default:
            return;
    }
    AppendReceiptToShift(std::move(newReceipt));
}

void Shift::NewReceiptActions(std::unique_ptr<receipt::BaseReceipt>& receipt) 
{
    int input;
    ReceiptAction receiptAction;
    do {
        std::cout << "1. Добавить позицию чека\n";
        std::cout << "2. Удалить позицию чека\n"; 
        std::cout << "3. Вывести все\n";
        std::cout << "4. Закончить работу с чеком\n";
        std::cout << "Выберите пункт: ";
        std::cin >> input;
        receiptAction = static_cast<ReceiptAction>(input);
        switch (receiptAction) {
        case AddItem:
            receipt->AddNewItem();
            break;
        case DeleteItem:
            receipt->DeleteItem();
            break;
        case Show:
            receipt->Show();
            break; 
        case Back:
            std::cout << "\n";
            break;
        }
    } while (receiptAction != Back);

}

void Shift::AppendReceiptToShift(std::unique_ptr<receipt::BaseReceipt> newReceipt) 
{
    m_arraySize ++;

    std::unique_ptr<std::unique_ptr<receipt::BaseReceipt>[]> tempArray = std::make_unique<std::unique_ptr<receipt::BaseReceipt>[]>(m_arraySize);

    for (int i = 0; i < m_arraySize-1; i++)
    {
        tempArray[i] = std::move(m_receipts[i]);
    } 
    
    tempArray[m_arraySize-1] = std::move(newReceipt);
    m_receipts = std::move(tempArray);
}

}