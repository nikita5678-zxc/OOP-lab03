#include "include/rectangle.h"
#include "include/rhombus.h"
#include "include/trapezoid.h"
#include "include/array.h"
#include <iostream>

int main() {
    Array arr;

    arr.add(new Rectangle(0.0, 0.0, 4.0, 3.0));        
    arr.add(new Rhombus(6.0, 8.0, {1.0, 2.0}));        
    arr.add(new Trapezoid(2.0, 6.0, 4.0, {0.0, 0.0})); 

    std::cout << "=== Все фигуры ===\n";
    arr.printFigures();

    std::cout << "\n=== Центры фигур ===\n";

    std::cout << "\n=== Общая площадь ===\n";
    arr.totalArea(); 

    std::cout << "\n=== Удаляем фигуру по индексу 1 (ромб) ===\n";
    arr.remove(1);

    std::cout << "Оставшиеся фигуры:\n";
    arr.printFigures();

    std::cout << "\nНовая общая площадь:\n";
    arr.totalArea();

    return 0;
}