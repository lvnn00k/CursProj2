#pragma once

#include "receipt.hpp"

#include "receiptitem.hpp"
#include <iostream>
#include <memory>

namespace receipt 
{

class BaseReceipt 
{
public:
    BaseReceipt();
    virtual ~BaseReceipt();
    virtual void Show() {};
    virtual double GetSum() const = 0;
    virtual int GetTypeID() const = 0;
    virtual void AddNewItem() {};
    virtual void DeleteItem() {};
};

class ReturnReceipt final : public BaseReceipt 
{
private:
    double m_sum;

public:
    ReturnReceipt(double sum);
    void Show() override;

    double GetSum() const override
    {
        return m_sum;
    }

    int GetTypeID() const override
    {
        return 0;
    }
};
    
class Receipt final : public BaseReceipt 
{
private:
    size_t m_arraySize = 0;
    std::unique_ptr<ReceiptItem[]> m_items = std::make_unique<ReceiptItem[]>(m_arraySize);
    void RemoveElementFromItemsArray(int index);
    void AppendElementToItemsArray(int productId, int count);
    [[nodiscard]] bool IsReceiptEmpty();
    [[nodiscard]] std::weak_ptr<Product> WeakAtProduct(int i);

public:
    Receipt();
    ~Receipt() override;
    void AddNewItem() override;
    void DeleteItem()override;
    void Show() override;
    double GetSum() const override; 
    int GetTypeID() const override
    {
        return 1;
    }

}; 
}