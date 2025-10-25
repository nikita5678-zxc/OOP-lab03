#pragma once

#include "figure.h"

class Array {
public:
    Array();
    ~Array();
    Array(const Array& other);
    Array& operator=(const Array& other);
    Array(Array&& other) noexcept;
    Array& operator=(Array&& other) noexcept;

    void add(Figure * fig);
    void remove(size_t index);
    void printFigures() const;
    void totalArea() const;
    void printCenters();
    void printAreas();
    size_t Size() const;

private:
    Figure ** data;
    size_t size;
    size_t capacity;
    void resize();
};