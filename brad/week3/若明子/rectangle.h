#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

/*为下面的 Rectangle 和 Circle 类重写 getArea 虚函数。然后创建一个数组。
使用一个循环,生成 10 个 Rectangle、10 个 Circle,根据循环遍历顺序为它
们设置 no 编号,位置、长、宽、半径等其他信息取随机 1~10 之间的整数值,
然后将它们加入到创建好的数组中。最后,将这个长度为 20 的数组中所有面
积小于 50 的形状删除。将剩下的形状组成一个新的数组返回。


               
注意: 1. 补齐任务所需的其他函数。2. 考虑正确的内存管理。3. 使用原生数
组,不使用 vector 等容器。
class Shape
{
int no;
public:
virtual int getArea()=0;
};
class Point
{
int x;
int y;
};
class Rectangle: public Shape
{
int width;
int height;
Point leftUp;
};
class Circle: public Shape
{
Point center;
int radius;
};
*/





class Shape
{  
public: 
   Shape();
   Shape(int n);
   int get_no()const;
   virtual double getArea()=0;
   virtual void print()=0;
private:                
   int no;
};              
class Point
{
   int x;
   int y;
public:
   int get_x()const;
   int get_y()const;
   Point(int x,int y);
   ~Point();
};              
class Rectangle: public Shape
{
   int width;
   int height;
   std::shared_ptr<Point> leftUp;
public:
   Rectangle(int width, int height, int x, int y,int no);
   Rectangle(const Rectangle& other);
   Rectangle& operator=(const Rectangle& other);
   ~Rectangle(){}       
   void print();
   double getArea();

};
class Circle: public Shape
{
Point center;
int radius;
public:
   Circle(int x,int y,int radius,int no);
   double getArea();
   void print();
};

#endif