#pragma once
#include <stdexcept>
#include <iostream>
#include <istream>
#include <ostream>
#include <cmath>

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
  }
};

class Rational {
 private:
  int64_t num_;
  int64_t den_;

 public:
  Rational();
  Rational(int64_t num);  // NOLINT
  Rational(int64_t num, int64_t den);
  int64_t GetNumerator() const;
  int64_t GetDenominator() const;
  void SetNumerator(int64_t num);
  void SetDenominator(int64_t den);
  void Reduce();
  Rational& operator=(const Rational& other);
  Rational& operator+=(const Rational& other);
  Rational& operator-=(const Rational& other);
  Rational& operator/=(const Rational& other);
  Rational& operator*=(const Rational& other);
  Rational operator+();
  Rational operator-();
  Rational operator+() const;
  Rational operator-() const;
  friend std::istream& operator>>(std::istream& is, Rational& r);
  friend std::ostream& operator<<(std::ostream& os, const Rational& r);
  Rational operator++(int);
  Rational operator--(int);
  Rational& operator++();
  Rational& operator--();
};

void Reduce(int64_t& x, int64_t& y);
Rational operator+(const Rational& x, const Rational& y);
Rational operator-(const Rational& x, const Rational& y);
Rational operator/(const Rational& x, const Rational& y);
Rational operator*(const Rational& x, const Rational& y);
bool operator<(const Rational& x, const Rational& y);
bool operator>(const Rational& x, const Rational& y);
bool operator==(const Rational& x, const Rational& y);
bool operator<=(const Rational& x, const Rational& y);
bool operator>=(const Rational& x, const Rational& y);
bool operator!=(const Rational& x, const Rational& y);
int64_t GCD(int64_t x, int64_t y);
int64_t Max(int64_t x, int64_t y);
int64_t Min(int64_t x, int64_t y);

Rational::Rational() : num_(0), den_(1) {
}

Rational::Rational(int64_t num) : num_(num), den_(1) {
}

Rational::Rational(int64_t num, int64_t den) : num_(num), den_(den) {
  if (den == 0) {
    throw RationalDivisionByZero{};
  }
  this->Reduce();
}

int64_t Rational::GetNumerator() const {
  return num_;
}

int64_t Rational::GetDenominator() const {
  return den_;
}

void Rational::SetNumerator(int64_t num) {
  num_ = num;
  this->Reduce();
}

void Rational::SetDenominator(int64_t den) {
  if (den == 0) {
    throw RationalDivisionByZero{};
  }
  den_ = den;
  this->Reduce();
}

Rational& Rational::operator=(const Rational& other) {
  if (this == &other) {
    return *this;
  }
  num_ = other.GetNumerator();
  den_ = other.GetDenominator();
  this->Reduce();
  return *this;
}

Rational& Rational::operator+=(const Rational& other) {
  int64_t x = num_, y = den_;
  num_ = x * other.GetDenominator() + y * other.GetNumerator();
  den_ = y * other.GetDenominator();
  this->Reduce();
  return *this;
}

Rational& Rational::operator-=(const Rational& other) {
  int64_t x = num_, y = den_;
  num_ = x * other.GetDenominator() - y * other.GetNumerator();
  den_ = y * other.GetDenominator();
  this->Reduce();
  return *this;
}

Rational& Rational::operator/=(const Rational& other) {
  if (other.GetNumerator() == 0) {
    throw RationalDivisionByZero{};
  }
  num_ *= other.GetDenominator();
  den_ *= other.GetNumerator();
  this->Reduce();
  return *this;
}

Rational& Rational::operator*=(const Rational& other) {
  num_ *= other.GetNumerator();
  den_ *= other.GetDenominator();
  this->Reduce();
  return *this;
}

Rational Rational::operator+() {
  return {num_, den_};
}

Rational Rational::operator+() const {
  return {num_, den_};
}

Rational Rational::operator-() {
  return {-num_, den_};
}

Rational Rational::operator-() const {
  return {-num_, den_};
}

Rational Rational::operator++(int) {
  Rational old_value;
  old_value = *this;
  num_ += den_;
  return {old_value.num_, old_value.den_};
}

Rational Rational::operator--(int) {
  Rational old_value(this->GetNumerator(), this->GetDenominator());
  num_ -= den_;
  return {old_value.num_, old_value.den_};
}

Rational& Rational::operator++() {
  num_ += den_;
  return *this;
}

Rational& Rational::operator--() {
  num_ -= den_;
  return *this;
}

void Rational::Reduce() {
  int64_t a, b;
  a = Max(abs(num_), abs(den_));
  b = Min(abs(num_), abs(den_));
  int64_t x;
  x = GCD(a, b);
  num_ /= x;
  den_ /= x;
  if (den_ < 0) {
    den_ *= -1;
    num_ *= -1;
  }
}

void Reduce(int64_t& x, int64_t& y) {
  int64_t a, b;
  a = Max(abs(x), abs(y));
  b = Min(abs(x), abs(y));
  int64_t z;
  z = GCD(a, b);
  x /= z;
  y /= z;
  if (y < 0) {
    x *= -1;
    y *= -1;
  }
}

std::istream& operator>>(std::istream& is, Rational& r) {
  is >> r.num_;
  if (is.peek() == '/') {
    is.ignore(1);
    is >> r.den_;
    if (r.den_ == 0) {
      throw RationalDivisionByZero{};
    }
    if (r.num_ == 0) {
      r.den_ = 1;
    }
  } else {
    r.den_ = 1;
  }
  r.Reduce();
  return is;
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
  if (r.den_ == 1) {
    os << r.num_;
  } else {
    os << r.num_ << '/' << r.den_;
  }
  return os;
}

Rational operator+(const Rational& x, const Rational& y) {
  int64_t a, b;
  a = x.GetNumerator() * y.GetDenominator() + x.GetDenominator() * y.GetNumerator();
  b = x.GetDenominator() * y.GetDenominator();
  Reduce(a, b);
  return {a, b};
}

Rational operator-(const Rational& x, const Rational& y) {
  int64_t a, b;
  a = x.GetNumerator() * y.GetDenominator() - x.GetDenominator() * y.GetNumerator();
  b = x.GetDenominator() * y.GetDenominator();
  Reduce(a, b);
  return {a, b};
}

Rational operator*(const Rational& x, const Rational& y) {
  int64_t a, b;
  a = x.GetNumerator() * y.GetNumerator();
  b = x.GetDenominator() * y.GetDenominator();
  Reduce(a, b);
  return {a, b};
}

Rational operator/(const Rational& x, const Rational& y) {
  if (y.GetNumerator() == 0) {
    throw RationalDivisionByZero{};
  }
  int64_t a, b;
  a = x.GetNumerator() * y.GetDenominator();
  b = x.GetDenominator() * y.GetNumerator();
  Reduce(a, b);
  return {a, b};
}

bool operator<(const Rational& x, const Rational& y) {
  if (x.GetNumerator() * y.GetDenominator() - x.GetDenominator() * y.GetNumerator() < 0 &&
      x.GetDenominator() * y.GetDenominator() > 0) {
    return true;
  }
  return (x.GetNumerator() * y.GetDenominator() - x.GetDenominator() * y.GetNumerator() > 0 &&
          x.GetDenominator() * y.GetDenominator() < 0);
}

bool operator>(const Rational& x, const Rational& y) {
  return (y < x);
}

bool operator==(const Rational& x, const Rational& y) {
  return (!(y < x) && !(x < y));
}

bool operator<=(const Rational& x, const Rational& y) {
  return (!(y < x));
}

bool operator>=(const Rational& x, const Rational& y) {
  return (!(x < y));
}

bool operator!=(const Rational& x, const Rational& y) {
  return (y < x || x < y);
}

int64_t GCD(int64_t x, int64_t y) {
  if (y == 0) {
    return x;
  }
  x %= y;
  return GCD(y, x);
}

int64_t Max(int64_t x, int64_t y) {
  return x > y ? x : y;
}

int64_t Min(int64_t x, int64_t y) {
  return x > y ? y : x;
}
