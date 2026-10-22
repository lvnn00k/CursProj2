#include "receiptitem.hpp"

namespace receipt 
{
    
ReceiptItem::ReceiptItem(std::weak_ptr<Product> product, int amount) 
    : m_product { product }
    , m_amount { amount }
    , m_sum { m_amount*GetPrice() }
{}

ReceiptItem::~ReceiptItem() 
{   
    std::cout << "Позиция чека удалена" << std::endl;
}

}