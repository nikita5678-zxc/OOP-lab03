#include "../include/rectangle.h"
#include <iostream>
#include <utility>
#include <cmath>

static double computeArea(double x1, double y1, double x2, double y2) {
    return std::abs(x2 - x1) * std::abs(y2 - y1);
}

static Point computeCenter(double x1, double y1, double x2, double y2) {
    return { (x1 + x2) / 2.0, (y1 + y2) / 2.0 };
}

Rectangle::Rectangle() : x1(0.0), y1(0.0), x2(0.0), y2(0.0) {}

Rectangle::Rectangle(double x1, double y1, double x2, double y2)
    : x1(x1), y1(y1), x2(x2), y2(y2) {}

Rectangle::Rectangle(const Rectangle& other)
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2) {}

Rectangle::Rectangle(Rectangle&& other) noexcept
    : x1(std::move(other.x1)),
      y1(std::move(other.y1)),
      x2(std::move(other.x2)),
      y2(std::move(other.y2)) {}


Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this == &other) return *this;
    x1 = other.x1;
    y1 = other.y1;
    x2 = other.x2;
    y2 = other.y2;
    
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this == &other) return *this;
    x1 = std::move(other.x1);
    y1 = std::move(other.y1);
    x2 = std::move(other.x2);
    y2 = std::move(other.y2);
    other.x1 = other.y1 = other.x2 = other.y2 = 0.0;
    return *this;
}

Rectangle::operator double() const {
    return computeArea(x1, y1, x2, y2);
}

Point Rectangle::Center() const {
    return computeCenter(x1, y1, x2, y2);
}

Figure * Rectangle::clone() const {
    return new Rectangle(*this);
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* rect = dynamic_cast<const Rectangle*>(&other);
    if (!rect) return false;
    bool sameOrder = (x1 == rect->x1 && y1 == rect->y1 && x2 == rect->x2 && y2 == rect->y2);
    bool swappedOrder = (x1 == rect->x2 && y1 == rect->y2 && x2 == rect->x1 && y2 == rect->y1);

    return sameOrder || swappedOrder;
}

void Rectangle::print(std::ostream& os) const {
    os << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
}

void Rectangle::read(std::istream& is) {
    is >> x1 >> y1 >> x2 >> y2;
}