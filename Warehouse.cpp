// Warehouse.cpp
#include "Warehouse.h"
#include "Product.h"
#include "Supplier.h"
#include <iostream>
#include <algorithm>

//Singleton

Warehouse& Warehouse::getInstance() {
    static Warehouse instance;
    return instance;
}

Warehouse::Warehouse()  { std::cout << "[Warehouse] Singleton создан\n"; }

Warehouse::~Warehouse() {
    // Агрегация: склад НЕ удаляет продукты и поставщиков.
    std::cout << "[Warehouse] Singleton уничтожен "
                 "(агрегируемые объекты не тронуты)\n";
}

//Агрегация: Product

void Warehouse::addProduct(Product* p) {
    if (!p) {
        std::cerr << "[Warehouse] addProduct: nullptr — пропущено\n";
        return;
    }
    m_products.push_back(p);
}

void Warehouse::removeProduct(Product* p) {
    m_products.erase(std::remove(m_products.begin(), m_products.end(), p),
                     m_products.end());
}

//Агрегация: Supplier

void Warehouse::addSupplier(Supplier* s) {
    if (!s) {
        std::cerr << "[Warehouse] addSupplier: nullptr — пропущено\n";
        return;
    }
    m_suppliers.push_back(s);
}

void Warehouse::removeSupplier(Supplier* s) {
    m_suppliers.erase(std::remove(m_suppliers.begin(), m_suppliers.end(), s),
                      m_suppliers.end());
}

//Вывод

void Warehouse::printState() const {
    std::cout << "\nСостояние склада\n";
    std::cout << "Продуктов: " << m_products.size() << "\n";
    for (auto* p : m_products) {
        std::cout << "  - " << p->getName() << " (" << p->getPrice() << ")";
        if (Supplier* s = p->getSupplier())
            std::cout << " от " << s->getName()
                      << " [" << s->getCountry() << "]";
        std::cout << "\n";
    }
    std::cout << "Поставщиков: " << m_suppliers.size() << "\n";
    for (auto* s : m_suppliers)
        std::cout << "  - " << s->getName()
                  << " [" << s->getCountry() << "]\n";
    std::cout << "\n\n";
}