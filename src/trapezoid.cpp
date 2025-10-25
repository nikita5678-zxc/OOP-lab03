#include "../include/trapezoid.h"
#include <iostream>
#include <utility>
#include <cmath>

Trapezoid::Trapezoid()
    : topBase(1.0), bottomBase(2.0), height(1.0), center{0.0, 0.0} {}

Trapezoid::Trapezoid(double top, double bottom, double h, Point center)
    : topBase(top), bottomBase(bottom), height(h), center(center) {}

Trapezoid::Trapezoid(const Trapezoid& other)
    : topBase(other.topBase)
    , bottomBase(other.bottomBase)
    , height(other.height)
    , center(other.center) {}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept
    : topBase(other.topBase)
    , bottomBase(other.bottomBase)
    , height(other.height)
    , center(std::move(other.center)) {
    other.topBase = 0.0;
    other.bottomBase = 0.0;
    other.height = 0.0;
    other.center = {0.0, 0.0};
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this == &other) return *this;
    topBase = other.topBase;
    bottomBase = other.bottomBase;
    height = other.height;
    center = other.center;
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this == &other) return *this;
    topBase = other.topBase;
    bottomBase = other.bottomBase;
    height = other.height;
    center = std::move(other.center);
    other.topBase = 0.0;
    other.bottomBase = 0.0;
    other.height = 0.0;
    other.center = {0.0, 0.0};
    return *this;
}

Trapezoid::operator double() const {
    return (topBase + bottomBase) * height / 2.0;
}

Point Trapezoid::Center() const {
    return center;
}

Figure* Trapezoid::clone() const {
    return new Trapezoid(*this);
}

bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* trap = dynamic_cast<const Trapezoid*>(&other);
    if (!trap) return false;

    const double eps = 1e-9;
    return (std::abs(topBase - trap->topBase) < eps) &&
           (std::abs(bottomBase - trap->bottomBase) < eps) &&
           (std::abs(height - trap->height) < eps) &&
           (std::abs(center.first - trap->center.first) < eps) &&
           (std::abs(center.second - trap->center.second) < eps);
}

void Trapezoid::print(std::ostream& os) const {
    os << topBase << ' ' << bottomBase << ' ' << height << ' '
       << center.first << ' ' << center.second;
}

void Trapezoid::read(std::istream& is) {
    is >> topBase >> bottomBase >> height >> center.first >> center.second;
}