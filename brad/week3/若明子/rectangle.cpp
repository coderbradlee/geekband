#include <memory>
#include <iostream>
#include "rectangle.h"
#include <random>
using namespace std;
const double PI=3.1415926;
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
	//cout<<"point constructor"<<endl;
}
Point::~Point()
{
	cout<<x<<":"<<y<<":point destructor"<<endl;
}
         

Rectangle::Rectangle(int width, int height, int x, int y,int no):width(width),height(height),leftUp(new Point(x,y)),Shape(no)
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
	cout<<width<<":"<<height<<":"<<leftUp->get_x()<<":"<<leftUp->get_y()<<":"<<get_no()<<":"<<getArea()<<endl;
}
double Rectangle::getArea()
{
	return width*height;
}
Circle::Circle(int x,int y,int radius,int no):center(x,y),radius(radius),Shape(no)
{}
void Circle::print()
{
	cout<<center.get_x()<<":"<<center.get_y()<<":"<<radius<<":"<<get_no()<<":"<<getArea()<<endl;
}
double Circle::getArea()
{
	return PI*radius*radius;
}
int get_random_int(int a, int b) 
{  
    static std::default_random_engine e{std::random_device{}()}; 
    static std::uniform_int_distribution<int> u;  
   
    return u(e, decltype(u)::param_type(a, b));  
}

void test()
{
	// Rectangle test(1,2,3,4);
	// Rectangle test_copy(test);
	// Rectangle test_assignment(5,6,7,8);
	// test_assignment=test_copy;
	// cout<<"============================"<<endl;
	// test.print();
	// test_copy.print();
	// test_assignment.print();
	std::shared_ptr<Shape> shape_array[20]={0};
	for(int i=0;i<10;++i)
	{
		shape_array[i]=std::shared_ptr<Shape>(new Rectangle(get_random_int(1,10),get_random_int(1,10),get_random_int(1,10),get_random_int(1,10),i));
		shape_array[i+10]=std::shared_ptr<Shape>(new Circle(get_random_int(1,10),get_random_int(1,10),get_random_int(1,10),i+10));
	}
	std::shared_ptr<Shape> shape_array_small_area[20]={0};
	for(int i=0,j=0;i<20;++i)
	{
		if(shape_array[i]->getArea()<50)
		{
			shape_array_small_area[j++]=shape_array[i];
		}
	}
	for(int i=0;i<20;++i)
	{
		if(shape_array_small_area[i]!=0)
			shape_array_small_area[i]->print();
	}
}
int main()
{
	test();
	return 0;
}