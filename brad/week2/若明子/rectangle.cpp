#include <memory>
#include <iostream>
#include "rectangle.h"
using namespace std;
Shape::Shape():no(0)
{}
Shape::Shape(int n):no(n)
{} 
int Shape::get_no()const
{
	return no;
}
       

int Point::get_x()const
{
  return x;
}
int Point::get_y()const
{
  return y;
}
Point::Point(int x,int y):x(x),y(y)
{
	cout<<"point constructor"<<endl;
}
Point::~Point()
{
	cout<<x<<":"<<y<<":point destructor"<<endl;
}
         

Rectangle::Rectangle(int width, int height, int x, int y):width(width),height(height),leftUp(new Point(x,y)),Shape(10)
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
	cout<<"before reset"<<endl;
	leftUp.reset(new Point(other.leftUp->get_x(),other.leftUp->get_y()));
	cout<<"after reset"<<endl;
	return *this;
}
     
void Rectangle::print()
{
	cout<<width<<":"<<height<<":"<<leftUp->get_x()<<":"<<leftUp->get_y()<<":"<<get_no()<<endl;
}



void test()
{
	Rectangle test(1,2,3,4);
	Rectangle test_copy(test);
	Rectangle test_assignment(5,6,7,8);
	test_assignment=test_copy;
	cout<<"============================"<<endl;
	test.print();
	test_copy.print();
	test_assignment.print();
}
int main()
{
	test();
	return 0;
}