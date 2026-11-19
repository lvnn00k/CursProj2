#pragma once

#include "report.hpp"

#include "receipt.hpp"
#include <string>
#include <iostream>
#include <memory>

namespace shift
{
class BaseReport {
   
public:
    BaseReport() = default;
    void Print(std::unique_ptr<std::unique_ptr<receipt::BaseReceipt>[]>& allReceipts, int array_size) const;

protected:
    virtual std::string GetName() const = 0;
};

class X_Report : public BaseReport {
private:
    inline static int m_count{0}; 
public:
    static int GetCount() 
    {
        return ++m_count;
    }

    static void ResetCount()
    {
        m_count = 0;
    }

    std::string GetName() const override
    {
        return std::string("X-отчет\t№") + std::to_string(GetCount()) + "\n";
    }
}; 

class Z_Report final : public BaseReport {
public:
    std::string GetName() const override
    {
        return "Z-отчет\n";
    }
};

}