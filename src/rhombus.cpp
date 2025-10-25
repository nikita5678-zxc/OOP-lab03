#include "../include/rhombus.h"
#include <iostream>
#include <utility>
#include <cmath>

Rhombus::Rhombus() : center{0.0, 0.0}, d1(1.0), d2(1.0) {}

Rhombus::Rhombus(double d1, double d2, Point center)
    : center(center), d1(d1), d2(d2) {}

Rhombus::Rhombus(const Rhombus& other)
    : center(other.center), d1(other.d1), d2(other.d2) {}

Rhombus::Rhombus(Rhombus&& other) noexcept
    : center(std::move(other.center))
    , d1(other.d1)
    , d2(other.d2) {
    other.center = {0.0, 0.0};
    other.d1 = 0.0;
    other.d2 = 0.0;
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this == &other) return *this;
    center = other.center;
    d1 = other.d1;
    d2 = other.d2;
    return *this;
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this == &other) return *this;
    center = std::move(other.center);
    d1 = other.d1;
    d2 = other.d2;
    other.center = {0.0, 0.0};
    other.d1 = 0.0;
    other.d2 = 0.0;
    return *this;
}

Rhombus::operator double() const {
    return std::abs(d1 * d2) / 2.0;
}

Point Rhombus::Center() const {
    return center;
}

Figure* Rhombus::clone() const {
    return new Rhombus(*this);
}

bool Rhombus::operator==(const Figure& other) const {
    const Rhombus* rh = dynamic_cast<const Rhombus*>(&other);
    if (!rh) return false;
    const double eps = 1e-9;
    return (std::abs(center.first - rh->center.first) < eps) &&
           (std::abs(center.second - rh->center.second) < eps) &&
           (std::abs(d1 - rh->d1) < eps) &&
           (std::abs(d2 - rh->d2) < eps);
}

void Rhombus::print(std::ostream& os) const {
    os << d1 << ' ' << d2 << ' ' << center.first << ' ' << center.second;
}

void Rhombus::read(std::istream& is) {
    is >> d1 >> d2 >> center.first >> center.second;
}