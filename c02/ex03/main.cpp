#include <iostream>
#include "Point.hpp"

// bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point p1(2, 2);        // inside (simple, integer-safe)
    Point p2(0, 0);        // vertex
    Point p3(5, 0);        // edge
    Point p4(10, 10);      // outside
    Point p5(3.3f, 3.3f);  // ⚠️ inside, but fragile for area method

    std::cout << bsp(a, b, c, p1) << " expected 1" << std::endl;
    std::cout << bsp(a, b, c, p2) << " expected 0" << std::endl;
    std::cout << bsp(a, b, c, p3) << " expected 0" << std::endl;
    std::cout << bsp(a, b, c, p4) << " expected 0" << std::endl;
    std::cout << bsp(a, b, c, p5) << " expected 1 (area method may fail)" << std::endl;

    return 0;
}
