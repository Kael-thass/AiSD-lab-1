// Warehouse.h
#pragma once
#include <vector>

class Product;
class Supplier;

// склад - Singleton.
// АГРЕГИРУЕТ Product и Supplier: хранит указатели, но НЕ владеет ими.
class Warehouse {
public:
    //Singleton
    static Warehouse& getInstance();

    Warehouse(const Warehouse&) = delete;
    Warehouse& operator=(const Warehouse&) = delete;

    //Агрегация: Product
    void addProduct(Product* p);
    void removeProduct(Product* p);

    //Агрегация: Supplier
    void addSupplier(Supplier* s);
    void removeSupplier(Supplier* s);

    //Печать
    void printState() const;

private:
    Warehouse();
    ~Warehouse();   // НЕ удаляет агрегируемые объекты

    std::vector<Product*>  m_products;    // агрегация
    std::vector<Supplier*> m_suppliers;   // агрегация
};