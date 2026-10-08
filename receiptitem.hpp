#pragma once

#include "receiptitem.hpp"

#include "product.hpp"
#include <iostream>

namespace receipt 
{
    
class ReceiptItem 
{
private:
    Product* m_product;
    int m_amount;
    double m_sum;

public:
    
    ReceiptItem(Product &product, int amount); 
    ~ReceiptItem();

    [[nodiscard]] double GetPrice() const
    {
        return m_product->GetPrice();
    }

    [[nodiscard]] double GetNDS() const 
    {
        return m_product->GetNDS();
    }

    [[nodiscard]] std::string GetName() const 
    {
        return m_product->GetName();
    }

    [[nodiscard]] int GetAmount() const 
    {
        return m_amount;
    }

    [[nodiscard]] double GetSum() const 
    {
        return m_sum;
    }
    
}; 
}