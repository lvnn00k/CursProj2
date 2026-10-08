#include "receipt.hpp"

namespace receipt 
{

Receipt::~Receipt() 
{
    std::cout << "Чек удален" << std::endl;
}

void Receipt::AddNewItem() 
{   
    int number, count;
    while (1) 
    {
        std::cout << "Укажите номер товара: ";
        std::cin >> number;
        if (!(number < 0 or number > Products::instance().size())) 
        {
            break;
        }
        std::cout << "Такого товара не существует.\n";
    }
    while (1) 
    {
        std::cout << "Количество: ";
        std::cin >> count;
        if (count > 0) 
        {
            break;
        }
        std::cout << "Количесвто не может быть меньше 1.\n";
    } 
    m_items.push_back(std::make_unique<ReceiptItem>(Products::instance()[number-1], count));
}

void Receipt::DeleteItem() 
{
    if (IsReceiptEmpty()) 
    {
        return;
    }

    int number;
    while (1) 
    {
        std::cout << "Введите номер который хотите удалить: ";
        std::cin >> number;
        if (!(number < 0 or number > m_items.size())) 
        {
            break; 
        }
        std::cout << "Позиции с таким номером нет.\n";
    }
    
    auto item = m_items.begin() + number - 1;
    m_items.erase(item);
}

void Receipt::ShowAll() {
    if (IsReceiptEmpty()) 
    {
        return;
    }

    for (const auto& item : m_items) 
    {
        std::cout << item->GetName() << "\t" << item->GetPrice() << "*" << item->GetAmount() << "\t=" << item->GetSum() <<"\n";
        std::cout << "НДС " << item->GetNDS() << "%\n";
    }
}

bool Receipt::IsReceiptEmpty() {
    if (m_items.empty()) 
    { 
        std::cout << "Чек пуст\n" << std::endl;
        return true;
    }
    return false;
}

}