#pragma once

#include "product.hpp"

#include <vector>
#include <string>
#include <iostream>

namespace receipt 
{

class Product 
{
private:
    std::string m_name;
    double m_price;
    int m_nds;

public:
    Product(std::string name, double price, int nds);
    ~Product();

    [[nodiscard]] std::string GetName() const
    {
        return m_name;
    }

    [[nodiscard]] double GetPrice() const
    {
        return m_price;
    }

    [[nodiscard]] int GetNDS() const
    {
        return m_nds;
    }

};

class Products
{
public:
    static std::vector<Product>& instance() {
        static std::vector<Product> products = [] {
            std::vector<Product> v;
            v.reserve(3);
            v.emplace_back("one", 100.00, 22);
            v.emplace_back("two", 200.00, 0);
            v.emplace_back("three", 300.00, 22);
            return v;
        }();
        
        return products;
    }
    Products() = delete;
};

}