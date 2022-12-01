#include <iostream> 
#include <vector> 
#include <cmath> 
#include <numeric> 

using std::vector; 
using real = long double;  
struct Point { 
real x; 
real y; 

Point() = default; 
~Point() = default; 
Point(const Point&) = default; 
explicit Point(real x, real y): x(x), y(y) {} 
}; 

Point operator+ (const Point& A, const Point& B) { 
return Point((A.x + B.x), (A.y + B.y)); 
} 

Point operator- (const Point& A, const Point& B) { 
return Point((A.x - B.x), (A.y - B.y)); 
} 

real dist(Point A, Point B) { 
return sqrtl(powl((A.x - B.x), 2) + powl((A.y - B.y), 2)); 
}  
struct Shape { 
virtual ~Shape() = default; 
virtual real area() = 0; 
virtual real perimeter() = 0 ; 
virtual void info() = 0; 
};  
struct Ellipse: public Shape { 
Point F1; 
Point F2; 
real a; 

Ellipse() = default; 
~Ellipse() = default; 
Ellipse(const Ellipse&) = default; 
Ellipse(Point F1, Point F2, real dist): F1(F1), F2(F2), a(dist / 2) {} 

real area() override { 
real b = sqrtl((a / 2) * (a / 2) - dist(F1, F2) / 2); 
return M_PI * a * b; 
} 

real perimeter() override { 
real b = sqrtl((a / 2) * (a / 2) - dist(F1, F2) / 2); 
return 4 * (M_PI * a * b + (a - b)) / (a + b); 
} 

void info() override { 
std::cout « "Focal points : (" « F1.x « "," « F1.y « ") and (" « F2.x « "," « F2.y « "). Distance : " « 2 * a « "."; 
} 
};  
struct Circle: public Ellipse { 
Circle() = default; 
~Circle() = default; 
Circle(const Circle&) = default; 
Circle(Point O, real R): Ellipse(O, O, 2*R) {} 

real area() override { 
return M_PI * a * a; 
} 

real perimeter() override { 
return 2 * M_PI * a; 
} 

void info() override { 
std::cout « "Center : (" « F1.x « "," « F1.y « ")." « "Radius : " « a « "."; 
} 
};  
struct Rectangle: public Shape { 
Point A; 
Point B; 
Point C; 
Point D; 
Rectangle() = default; 
~Rectangle() = default; 
Rectangle(const Rectangle&) = default; 
Rectangle(Point A, Point C): A(A), C(C) {} 
Rectangle(real x1, real y1, real x2, real y2): A(Point(x1, y1)), C(Point(x2, y2)) {}  

real area() override { 
return dist(A, B) * dist(B, C); 
} 

real perimeter() override { 
return 2 * (dist(A, B) + dist(B, C)); 
} 

void info() override { 
std::cout « "Vertices : " « ... 
} 
}; 
struct Square: public Rectangle { 
Square() = default; 
~Square() = default; 
Square(const Square&) = default; 
Square(Point A, Point B): Rectangle(A, Point((A.x + (B.y - A.y)), B.y)) {} 

real area() override { 
return powl(dist(A, B), 2); 
} 

real perimeter() override { 
return 4 * dist(A, B); 
} 

void info() override { 
std::cout « "Vertices : " « ... 
} 
};


