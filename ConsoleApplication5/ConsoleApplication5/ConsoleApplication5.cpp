// main.cpp
#include "Product.h"
#include "Supplier.h"
#include "Warehouse.h"
#include <iostream>

int main() {
    std::cout << "Старт программы\n";

    // singleton: оба вызова возвращают один и тот же объект
    Warehouse& w1 = Warehouse::getInstance();
    Warehouse& w2 = Warehouse::getInstance();
    std::cout << "Один и тот же склад? "
        << (&w1 == &w2 ? "Да" : "Нет") << "\n\n";

    Supplier farmer("FarmerJohn", "USA");

    {
        Supplier importer("GlobalFoods", "Germany");

        Product apple("Apple", 0.5, &farmer);
        Product banana("Banana", 0.3, &importer);

        std::cout << "Product count: " << Product::getInstanceCount() << "\n";

        w1.addSupplier(&farmer);
        w1.addSupplier(&importer);
        w1.addProduct(&apple);
        w1.addProduct(&banana);

        // Проверка на nullptr
        w1.addProduct(nullptr);
        w1.addSupplier(nullptr);

        w1.printState();

        // убираем ссылки со склада ДО выхода из блока
        // чтобы в складе не осталось висячих указателей
        w1.removeProduct(&apple);
        w1.removeProduct(&banana);
        w1.removeSupplier(&importer);

    }

    std::cout << "Product count после блока: "
        << Product::getInstanceCount() << "\n";
    std::cout << "Поставщик farmer всё ещё жив: "
        << farmer.getName() << "\n";

    // Склад пуст - печать безопасна
    w1.printState();

    // Явно убираем последнего поставщика (farmer жив, но склад
    // больше не должен на него ссылаться до конца программы).
    w1.removeSupplier(&farmer);

    std::cout << "Конец программы\n";
    return 0;
}