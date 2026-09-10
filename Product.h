// Product.h
#pragma once
#include <string>

class Supplier;

// Продукт. хранит указатель, но не владеет им.
class Product {
public:
    // Статическое поле - счётчик созданных объектов Product
    static int s_instanceCount;

    // Статические методы для работы со статическим полем
    static int  getInstanceCount();
    static void resetInstanceCount();

    Product(std::string name, double price, Supplier* supplier);
    ~Product();

    Product(const Product&)            = delete;
    Product& operator=(const Product&) = delete;

    const std::string& getName()     const;
    double             getPrice()    const;
    Supplier*          getSupplier() const;   // НЕ владеет

private:
    std::string m_name;
    double      m_price;
    Supplier*   m_supplier;   // агрегация
};