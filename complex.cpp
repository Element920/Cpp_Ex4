// #include "complex.hpp"

// Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

// double Complex::get_real() const {
//     return real;
// }

// double Complex::get_imaginary() const {
//     return imaginary;
// }

// Complex Complex::operator+(const Complex& other) const {
//     return Complex(real + other.real, imaginary + other.imaginary);
// }

// Complex Complex::operator-(const Complex& other) const {
//     return Complex(real - other.real, imaginary - other.imaginary);
// }

// Complex Complex::operator*(const Complex& other) const {
//     return Complex(real * other.real - imaginary * other.imaginary,
//                    real * other.imaginary + imaginary * other.real);
// }

// Complex Complex::operator/(const Complex& other) const {
//     double denominator = other.real * other.real + other.imaginary * other.imaginary;
//     return Complex((real * other.real + imaginary * other.imaginary) / denominator,
//                    (imaginary * other.real - real * other.imaginary) / denominator);
// }

// bool Complex::operator==(const Complex& other) const {
//     return (real == other.real) && (imaginary == other.imaginary);
// }

// bool Complex::operator!=(const Complex& other) const {
//     return !(*this == other);
// }

// std::ostream& operator<<(std::ostream& os, const Complex& complex) {
//     os << complex.real;
//     if (complex.imaginary >= 0) {
//         os << " + " << complex.imaginary << "i";
//     } else {
//         os << " - " << -complex.imaginary << "i";
//     }
//     return os;
// }
//   std::ostream& operator<<(std::ostream& os, const Complex& c) {
//         os << c.real << " + " << c.imaginary << "i";
//         return os;
//     }

    