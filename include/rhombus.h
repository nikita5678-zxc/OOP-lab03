#pragma once

#include "figure.h"

class Rhombus : public Figure {
public:
    Rhombus();
    Rhombus(double d1, double d2, Point center = {0.0, 0.0});
    Rhombus(const Rhombus& other);
    Rhombus(Rhombus&& other) noexcept;
    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;
    
    operator double() const override;
    Point Center() const override;
    Figure* clone() const override;
    bool operator==(const Figure& other) const override;

private:
    Point center;
    double d1, d2;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
 };
