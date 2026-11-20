#pragma once

#include "receiptitem.hpp"

#include "product.hpp"
#include <iostream>

namespace receipt 
{
    
class ReceiptItem 
{
private:
    std::weak_ptr<Product> m_product;
    int m_amount;
    double m_sum;

public:
    
    ReceiptItem(std::weak_ptr<Product> product, int amount); 
    ReceiptItem() = default; 
    ~ReceiptItem();

    [[nodiscard]] double GetPrice() const
    {
        if (auto prod = m_product.lock()) 
        {
            return prod->GetPrice();
        }
        return 0;
    }

    [[nodiscard]] double GetNDS() const 
    {
        if (auto prod = m_product.lock()) 
        {
            return prod->GetNDS();
        }
        return 0;
    }

    [[nodiscard]] std::string GetName() const 
    {
        if (auto prod = m_product.lock()) 
        {
            return prod->GetName();
        }
        return 0;
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