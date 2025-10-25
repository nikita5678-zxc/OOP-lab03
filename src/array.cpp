#include "../include/array.h"
#include <iostream>


Array::Array() 
    : data(new Figure*[8]),
    size(0),
    capacity(8)
{}

Array::~Array() {
    for(size_t i = 0; i < size; i++) {
        delete data[i];
    }

    delete[] data;
}

Array::Array(const Array& other) {
    capacity = other.capacity;
    size = other.size;
    data = new Figure*[capacity];

    for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i]->clone();
    }
}

Array &Array::operator=(const Array& other) {
    if (this == &other) {
        return *this;
    }

    for (size_t i = 0; i < size; i++) {
        delete data[i];
    }

    size = other.size;
    capacity = other.capacity;
    data = new Figure*[capacity];

    for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i]->clone();
    }

    return *this;
}

Array::Array(Array&& other) noexcept 
    : data(other.data),
    size(other.size),
    capacity(other.capacity)
{
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

Array &Array::operator=(Array&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    for (size_t i = 0; i < size; i++) {
        delete data[i];
    } 
    
    delete[] data;

    data = other.data;
    size = other.size;
    capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;

    return *this;
}

void Array::resize() {
    size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
    Figure ** new_data = new Figure*[new_capacity];

    for (size_t i = 0; i < size; i++) {
        new_data[i] = data[i];
    }
    delete[] data;

    data = new_data;
    capacity = new_capacity;
}


void Array::add(Figure * fig) {
    if (size == capacity) {
        resize();
    }

    data[size] = fig;
    size++;
}

void Array::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    delete data[index];
    
    for (size_t i = index; i < size - 1; i++) {
        data[i] = data[i+1];
    }

    size--;
}

void Array::printFigures() const{
    for (size_t i = 0; i < size; i++) {
        std::cout << "Figure" << i << ":\n";
        std::cout << *data[i] << "\n";
    }
}

void Array::totalArea() const {
    double total = 0.0;
    for (size_t i = 0; i < size; ++i) {
        total += *data[i];
    }
    std::cout << total << std::endl;
}

void Array::printCenters() {
    for (size_t i = 0; i < size; ++i) {
        Point c = data[i]->Center();
        std::cout << "(" << c.first << ", " << c.second << ")" << std::endl;
    }
}

void Array::printAreas() {
    for (size_t i = 0; i < size; ++i) {
        std::cout << static_cast<double>(*data[i]) << std::endl;
    }
}

size_t Array::Size() const{
    return size;
}