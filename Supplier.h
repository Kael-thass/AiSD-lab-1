// Supplier.h
#pragma once
#include <string>

// Поставщик. Живёт независимо, склад лишь агрегирует его.
class Supplier {
public:
    Supplier(std::string name, std::string country);
    ~Supplier();

    Supplier(const Supplier&)            = delete;
    Supplier& operator=(const Supplier&) = delete;

    const std::string& getName()    const;
    const std::string& getCountry() const;

private:
    std::string m_name;
    std::string m_country;
};