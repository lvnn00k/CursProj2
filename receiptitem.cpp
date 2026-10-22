#include "receiptitem.hpp"

namespace receipt 
{
    
ReceiptItem::ReceiptItem(Product &product, int amount) 
    : m_product { &product }
    , m_amount { amount }
    , m_sum { m_amount*GetPrice() }
{}

ReceiptItem::~ReceiptItem() 
{   
    std::cout << "Позация чека удалена" << std::endl;
}

}