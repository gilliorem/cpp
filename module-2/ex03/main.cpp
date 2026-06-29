#include "Fixed.hpp"
#include "Point.hpp"
#include <cmath>
#include <iostream>

int main( void )
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    Point inside(2, 2);
    Point outside(20, 20);
    Point edgeAB(5, 0);
    Point edgeAC(0, 5);
    Point edgeBC(5, 5);
    Point insideCloseEdge(5, 0.01f);
    Point outsideCloseEdge(5, -0.01f);

    std::cout << "Inside: "<< bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "EdgeAB: " << bsp(a, b, c, edgeAB) << std::endl;
    std::cout << "EdgeAC: " << bsp(a, b, c, edgeAC) << std::endl;
    std::cout << "EdgeBC: " << bsp(a, b, c, edgeBC) << std::endl;
    std::cout << "VertexA: " << bsp(a, b, c, a) << std::endl;
    std::cout << "VertexB: " << bsp(a, b, c, b) << std::endl;
    std::cout << "VertexC: " << bsp(a, b, c, c) << std::endl;
    std::cout << "InsideCloseEdge: "<< bsp(a, b, c, insideCloseEdge) << std::endl;
    std::cout << "OutsideCloseEdge: " << bsp(a, b, c, outsideCloseEdge) << std::endl;

    return 0;
}
