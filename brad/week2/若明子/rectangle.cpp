#include <memory>
#include "rectangle.h"
Rectangle::Rectangle(int width, int height, int x, int y):width(width),height(height),leftUp(new Point(x,y))
{

}
Rectangle::Rectangle(const Rectangle& other)
{
	width=other.width;
	height=other.height;
	leftUp=std::shared_ptr<Point>((new Point(other.leftUp->get_x(),other.leftUp->get_y())));
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if(this==&other)
		return *this;
	width=other.width;
	height=other.height;
	leftUp.reset(new Point(other.leftUp->get_x(),other.leftUp->get_y()));
	return *this;
}
Rectangle::~Rectangle()
{

}

int main()
{
	Rectangle test(1,2,3,4);
	Rectangle test_copy(test);
	Rectangle test_assignment=test_copy;
	test.print();
	test_copy.print();
	test_assignment.print();
	return 0;
}