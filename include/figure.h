#pragma once

#include <iostream>
#include <utility>

using Point = std::pair<double, double>;

class Figure {
public:
    virtual ~Figure() noexcept = default;
    virtual operator double() const = 0;
    virtual Point Center() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.print(os);
        return os;
    }

    friend std::istream& operator >>(std::istream& os, Figure& fig) {
        fig.read(os);
        return os;
    }

    virtual Figure* clone() const = 0;
    virtual bool operator==(const Figure& other) const = 0;

protected:
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
};