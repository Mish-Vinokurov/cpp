#include <iostream>
#include <cmath>

class Complex{
public:
    Complex() = default;
    Complex(double real, double imaginary)
            : _real(real), _imaginary(imaginary) {
    }
    Complex(double real)
            : _real(real), _imaginary(0) {
    }
    Complex& operator=(const Complex& other) { 
      _real = other._real;
      _imaginary = other._imaginary;
      return *this;
    }
    double Re() { return _real; }
    double Im() { return _imaginary; }
    double Re() const { return _real; }
    double Im() const { return _imaginary; }
    Complex operator+();
    Complex operator-();
private:
    double _real;
    double _imaginary;
};

Complex operator + (const Complex& lhs, const Complex& rhs);
Complex operator + (const Complex& lhs, double rhs);
Complex operator + (double lhs, const Complex& rhs);

Complex operator - (const Complex& lhs, const Complex& rhs);
Complex operator - (const Complex& lhs, double rhs);
Complex operator - (double lhs, const Complex& rhs);

Complex operator * (const Complex& lhs, const Complex& rhs);
Complex operator * (const Complex& lhs, double rhs);
Complex operator * (double lhs, const Complex& rhs);

Complex operator / (const Complex& lhs, const Complex& rhs);
Complex operator / (const Complex& lhs, double rhs);
Complex operator / (double lhs, const Complex& rhs);

double abs(Complex& complex);

Complex operator + (const Complex& lhs,  const Complex& rhs) {
    Complex c = Complex(lhs.Re() + rhs.Re(), lhs.Im() + rhs.Im());
    return c;
}
Complex operator + (const Complex& lhs,  double rhs) {
    Complex c = Complex(lhs.Re() + rhs, lhs.Im());
    return c;
}
Complex operator + (double lhs,  const Complex& rhs) {
    Complex c = Complex(rhs.Re() + lhs, rhs.Im());
    return c;
}

Complex operator - (const Complex& lhs,  const Complex& rhs) {
    Complex c = Complex(lhs.Re() - rhs.Re(), lhs.Im() - rhs.Im());
    return c;
}
Complex operator - (const Complex& lhs,  double rhs) {
    Complex c = Complex(lhs.Re() - rhs, lhs.Im());
    return c;
}
Complex operator - (double lhs,  const Complex& rhs) {
    Complex c = Complex(rhs.Re() - lhs, rhs.Im());
    return c;
}

Complex operator * ( const Complex& lhs,  const Complex& rhs) {
    Complex c = Complex(lhs.Re() * rhs.Re() - lhs.Im() * rhs.Im(), lhs.Re() * rhs.Im() + lhs.Im() * rhs.Re());
    return c;
}
Complex operator * (double lhs,  const Complex& rhs) {
    Complex c = Complex(lhs * rhs.Re(), lhs * rhs.Im());
    return c;
}
Complex operator * ( const Complex& lhs,  double rhs) {
    Complex c = Complex(lhs.Re() * rhs, lhs.Im() * rhs);
    return c;
}

Complex operator / ( const Complex& lhs,  const Complex& rhs) {
    Complex c = Complex((lhs.Re() * rhs.Re() + lhs.Im() * rhs.Im()) / (rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im()), (rhs.Re() * lhs.Im() - rhs.Im() * lhs.Re()) / (rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im()));
    return c;
}
Complex operator / (double lhs,  const Complex& rhs) {
    Complex c = Complex((lhs * rhs.Re()) / (rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im()), (- rhs.Im() * lhs) / (rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im()));
    return c;
}
Complex operator / ( const Complex& lhs, double rhs) {
    Complex c = Complex((lhs.Re() * rhs) / (rhs * rhs), (rhs * lhs.Im()) / (rhs * rhs));
    return c;
}


Complex Complex::operator + () {
    return Complex(_real, _imaginary);
}

Complex Complex::operator - () {
    if(_real == 0)
        return Complex(0, -_imaginary);
    else if(_imaginary == 0)
        return Complex(-_real, 0);
    else if(_real == 0 && _imaginary == 0)
        return Complex(0, 0);
    else
        return Complex(-_real, -_imaginary);
}


double abs(Complex& complex) {
    return pow(complex.Re() * complex.Re() + complex.Im() * complex.Im(), 0.5);
}
