#include <memory>
#include <iostream>
#include "rectangle.h"
#include <random>
using namespace std;

void test()
{
	cout<<sizeof(char)<<endl;
	cout<<sizeof(int)<<endl;
	cout<<sizeof(double)<<endl;
	cout<<sizeof(Fruit)<<endl;
	cout<<sizeof(Apple)<<endl;
}
int main()
{
	test();
	return 0;
}