#include <memory>
#include <iostream>
#include "rectangle.h"
#include <random>
using namespace std;

void test()
{
	Apple start;
    Apple* p1=new Apple;
    Apple* p2=new(&start)Apple;
    Apple* p3=new(100)Apple;
    Apple* p4=new(100,'a')Apple;
    //Apple* p5=new(100)Apple(1);
    //Apple* p6=new(100,'a')Apple(1);
    //Apple* p7=new(&start)Apple(1);
    Apple* p8=new Apple(1);
}
int main()
{
	test();
	return 0;
}