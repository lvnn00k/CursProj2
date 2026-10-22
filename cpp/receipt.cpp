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
        if (!(number < 0 or number > 3)) 
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
    
    AppendElementToItemsArray(number-1, count);

}

void Receipt::AppendElementToItemsArray(int productId, int count) 
{
    m_arraySize ++;

    std::unique_ptr<ReceiptItem[]> newItems = std::make_unique<ReceiptItem[]>(m_arraySize);

    for (int i = 0; i < m_arraySize-1; i++)
    {
        newItems[i] = std::move(m_items[i]);
    } 

    auto product = WeakAtProduct(productId);
    auto newItem = std::make_unique<ReceiptItem>(product, count);
    
    newItems[m_arraySize-1] = std::move(*newItem);
    m_items = std::move(newItems);
}

std::weak_ptr<Product> Receipt::WeakAtProduct(int i) 
{
    auto owner = Products::instance();
    std::shared_ptr<Product> product(owner, &owner.get()[i]);
    return product;
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
        if (!(number < 0 or number > m_arraySize)) 
        {
            break; 
        }
        std::cout << "Позиции с таким номером нет.\n";
    }
    
    RemoveElementFromItemsArray(number-1);

}

void Receipt::RemoveElementFromItemsArray(int index) 
{
    
    for (int i = index; i < m_arraySize-1; i++)
    {
        m_items[i] = std::move(m_items[i+1]);
    } 

    m_arraySize --;
    std::unique_ptr<ReceiptItem[]> newItems = std::make_unique<ReceiptItem[]>(m_arraySize);

    for (int i = 0; i < m_arraySize; i++) 
    {
        newItems[i] = std::move(m_items[i]);
    }
    
    m_items = std::move(newItems);

}

void Receipt::ShowAll() {
    if (IsReceiptEmpty()) 
    {
        return;
    }

    for (int i = 0; i < m_arraySize; i++) 
    {
        auto* item = &m_items[i];
        std::cout << item->GetName() << "\t" << item->GetPrice() << "*" << item->GetAmount() << "\t=" << item->GetSum() <<"\n";
        std::cout << "НДС " << item->GetNDS() << "%\n";
    }
}

bool Receipt::IsReceiptEmpty() {
    if (m_arraySize == 0) 
    { 
        std::cout << "Чек пуст" << std::endl;
        return true;
    }
    return false;
}

}