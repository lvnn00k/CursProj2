#pragma once

#include "receipt.hpp"

#include "receiptitem.hpp"
#include <iostream>
#include <memory>

namespace receipt 
{
    
class Receipt 
{
private:
    size_t m_arraySize = 0;
    std::unique_ptr<ReceiptItem[]> m_items = std::make_unique<ReceiptItem[]>(m_arraySize);
    void RemoveElementFromItemsArray(int index);
    void AppendElementToItemsArray(int productId, int count);
    [[nodiscard]] bool IsReceiptEmpty();
    [[nodiscard]] std::weak_ptr<Product> WeakAtProduct(int i);

public:
    Receipt() = default;
    ~Receipt();

    void AddNewItem();
    void DeleteItem();
    void ShowAll();

}; 
}