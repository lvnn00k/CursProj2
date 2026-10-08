#pragma once

#include "receipt.hpp"

#include "receiptitem.hpp"
#include <iostream>
#include <vector>
#include <memory>

namespace receipt 
{
    
class Receipt 
{
private:
    std::vector<std::unique_ptr<ReceiptItem>> m_items;
    [[nodiscard]] bool IsReceiptEmpty();

public:
    Receipt() =default;
    ~Receipt();

    void AddNewItem();
    void DeleteItem();
    void ShowAll();

}; 
}