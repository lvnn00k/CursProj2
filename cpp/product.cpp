#include "product.hpp"

namespace receipt 
{

Product::Product(std::string name, double price, int nds) 
    : m_name { name }
    , m_price { price } 
    , m_nds { nds }
{}

Product::~Product() 
{
    std::cout << "Продукт удален" << std::endl;
}

}