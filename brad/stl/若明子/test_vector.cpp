#include <memory>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;
// 给定一个 vector:v1 = [0, 0, 30, 20, 0, 0, 0, 0, 10, 0],希望通过
// not_equal_to 算法找到到不为零的元素,并复制到另一个 vector: v2
void print(std::vector<int>& v)
{
	for(const auto& i:v)
	{
		cout<<i<<endl;
	}
	cout<<"--------------------------"<<endl;
}
void test()
{
	std::vector<int> v{0, 0, 30, 20, 0, 0, 0, 0, 10, 0};
	std::vector<int> u;
	for(std::vector<int>::iterator it=v.begin();it!=v.end();)
	{
		//two way,bind and lambda
		//auto i=find_if(it,v.end(),bind(not_equal_to<int>(),0,placeholders::_1));
		auto i=find_if(it,v.end(),[](int i){ return i!=0;});
		if(i!=v.end())
		{
			u.push_back(*i);
			it=++i;
		}
		else
		{
			it=i;
		}			
	}
	
	print(v);
	print(u);
	
}
int main()
{
	try
	{
		test();
	}
	catch(const exception& e)
	{
		cout<<e.what()<<endl;
	}
	
	return 0;
}