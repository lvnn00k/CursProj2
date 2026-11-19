#pragma once

#include "shift.hpp"


#include "receipt.hpp"
#include "report.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

namespace shift
{

enum ReceiptAction {
    AddItem       = 1, 
    DeleteItem    = 2, 
    Show          = 3, 
    Back = 4
};

class Shift 
{
public:
    ~Shift();
    Shift() = default;

    void CreateNewReceipt();
    void PrintXReport();

private:
    int m_arraySize = 0;
    std::unique_ptr<std::unique_ptr<receipt::BaseReceipt>[]> m_receipts = std::make_unique<std::unique_ptr<receipt::BaseReceipt>[]>(m_arraySize);
    void AppendReceiptToShift(std::unique_ptr<receipt::BaseReceipt> newReceipt);
    void NewReceiptActions(std::unique_ptr<receipt::BaseReceipt>& receipt); 
};

}