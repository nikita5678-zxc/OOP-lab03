#pragma once

#include "figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(double top, double bottom, double h, Point center = {0.0, 0.0});
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;

    operator double() const override;
    Point Center() const override;
    Figure* clone() const override;
    bool operator==(const Figure& other) const override;

private:
    double topBase, bottomBase, height;
    Point center;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};