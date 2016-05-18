#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
class Shape
{                   
   int no;
};              
class Point
{
   int x;
   int y;
public:
   int get_x()const
   {
      return x;
   }
   int get_y()const
   {
      return y;
   }
   Point(int x,int y):x(x),y(y)
   {}
};              
class Rectangle: public Shape
{
   int width;
   int height;
   std::shared_ptr<Point> leftUp;
public:
   Rectangle(int width, int height, int x, int y);
   Rectangle(const Rectangle& other);
   Rectangle& operator=(const Rectangle& other);
   ~Rectangle();         
   void print()
   {
      cout<<width<<":"<<height<<":"<<leftUp->get_x()<<":"<<leftUp->get_y()<<":"<<endl;
   }
};


#endif