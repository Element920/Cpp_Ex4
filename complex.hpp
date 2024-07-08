// israelmor555@gmail.com
// 206508954

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>
#include <sstream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double real = 0.0, double imaginary = 0.0) : real(real), imaginary(imaginary) {}

    double get_real() const { return real; }
    double get_imaginary() const { return imaginary; }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imaginary * other.imaginary,
                       real * other.imaginary + imaginary * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        return Complex((real * other.real + imaginary * other.imaginary) / denominator,
                       (imaginary * other.real - real * other.imaginary) / denominator);
    }

    bool operator==(const Complex& other) const {
        return real == other.real && imaginary == other.imaginary;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

   std::string to_string() const {
        std::stringstream ss;
        ss << real;
        if (imaginary >= 0) {
            ss << " + " << imaginary << "i";
        } else {
            ss << " - " << -imaginary << "i";
        }
        return ss.str();
    }
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex) {
        os << complex.to_string();
        return os;
    }
};

#endif // COMPLEX_HPP
