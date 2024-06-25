#ifndef COMPLEXNUMBER_HPP
#define COMPLEXNUMBER_HPP

#include <iostream>
#include <cmath>

class ComplexNumber {
public:
    double real;
    double imag;

    ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {}

    bool operator==(const ComplexNumber& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    bool operator!=(const ComplexNumber& other) const {
        return !(*this == other);
    }

    bool operator<(const ComplexNumber& other) const {
        return std::abs(real) + std::abs(imag) < std::abs(other.real) + std::abs(other.imag);
    }

    bool operator>(const ComplexNumber& other) const {
        return std::abs(real) + std::abs(imag) > std::abs(other.real) + std::abs(other.imag);
    }

    bool operator<=(const ComplexNumber& other) const {
        return !(*this > other);
    }

    bool operator>=(const ComplexNumber& other) const {
        return !(*this < other);
    }

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};

#endif // COMPLEXNUMBER_HPP
