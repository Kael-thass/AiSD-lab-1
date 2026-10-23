// Supplier.cpp
#include "Supplier.h"
#include <iostream>
#include <utility>

Supplier::Supplier(std::string name, std::string country)
    : m_name(std::move(name)), m_country(std::move(country))
{
    std::cout << "[Supplier] Создан: " << m_name << "\n";
}

Supplier::~Supplier() {
    std::cout << "[Supplier] Уничтожен: " << m_name << "\n";
}

const std::string& Supplier::getName()    const { return m_name; }
const std::string& Supplier::getCountry() const { return m_country; }