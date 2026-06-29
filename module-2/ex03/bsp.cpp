#include "Point.hpp"
#include <iostream>

Fixed parea(const Point& p1, const Point& p2, const Point& p3)
{
	Fixed parea;

	parea = p1.getX() * (p2.getY() - p3.getY()) 
		  + p2.getX() * (p3.getY() - p1.getY())
		  + p3.getX() * (p1.getY() - p2.getY());

	int pareaRawValue = std::abs(parea.getRawBit());
	parea.setRawBit(pareaRawValue);
	
	return parea;
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed pabc = parea(a,b,c);
	
	Fixed pabp = parea(a,b,point);
	Fixed pacp = parea(a,c,point);
	Fixed pbcp = parea(b,c,point);

	if (pabp == 0 || pacp == 0 || pbcp == 0)
	{
		std::cout << "The point is on the edge\n";
		return false;
	}
	else if (pabc == (pabp + pacp + pbcp))
	{
		std::cout << "The point is in the triangle !\n";
		return true;
	}
	else
	{
		std::cout << "The point is outside the triangle !\n";
		return false;
	}
}
