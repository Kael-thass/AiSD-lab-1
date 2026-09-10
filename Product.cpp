// Product.cpp
#include "Product.h"
#include "Supplier.h"
#include <iostream>
#include <utility>
#include <stdexcept>

int Product::s_instanceCount = 0;

int  Product::getInstanceCount()   { return s_instanceCount; }
void Product::resetInstanceCount() { s_instanceCount = 0; }

Product::Product(std::string name, double price, Supplier* supplier)
    : m_name(std::move(name)), m_price(price), m_supplier(supplier)
{
    if (!m_supplier)
        throw std::invalid_argument("Product: supplier == nullptr");

    ++s_instanceCount;
    std::cout << "[Product] Создан: " << m_name
              << " (поставщик: " << m_supplier->getName() << ")\n";
}

Product::~Product() {
    // m_supplier НЕ удаляем - агрегация
    --s_instanceCount;
    std::cout << "[Product] Уничтожен: " << m_name << "\n";
}

const std::string& Product::getName()     const { return m_name; }
double             Product::getPrice()    const { return m_price; }
Supplier*          Product::getSupplier() const { return m_supplier; }