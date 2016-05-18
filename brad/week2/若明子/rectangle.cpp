#include <memory>
#include "rectangle.h"
Rectangle::Rectangle(int width, int height, int x, int y):width(width),height(height),leftUp(new Point(x,y))
{

}
Rectangle::Rectangle(const Rectangle& other)
{
	width=other.width;
	height=other.height;
	leftUp=new Point(other.leftUp->x,other.leftUp->y);
}

Rectangle::Rectangle& operator=(const Rectangle& other)
{
	if(this==&other)
		return *this;
	width=other.width;
	height=other.height;
	leftUp.reset(new Point(other.leftUp->x,other.leftUp->y));
	return *this;
}
Rectangle::~Rectangle()
{

}

int main()
{
	
	return 0;
}