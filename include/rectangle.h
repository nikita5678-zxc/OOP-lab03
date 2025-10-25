#pragma once

#include "figure.h"

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(double x1, double y1, double x2, double y2);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    
    operator double() const override;
    Point Center() const override;
    Figure* clone() const override;
    bool operator==(const Figure& other) const override;

private:
    double x1, y1, x2, y2;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
 };