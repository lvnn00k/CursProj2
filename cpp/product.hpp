#pragma once

#include "product.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <memory>

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
    Product() = default;
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
    static std::shared_ptr<Product[]> instance() {
        static std::shared_ptr<Product[]> products = [] {
            auto p = std::make_shared<Product[]>(3);
            p[0] = Product("one", 100.00, 22); 
            p[1] = Product("two", 200.00, 0);
            p[2] = Product("three", 300.00, 22);
            return p;
        }();

        return products;
    }
    Products() = delete;
};

}