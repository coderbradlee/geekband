#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
class Shape
{  
public: 
   Shape();
   Shape(int n);
   int get_no()const;
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
   Rectangle(int width, int height, int x, int y);
   Rectangle(const Rectangle& other);
   Rectangle& operator=(const Rectangle& other);
   ~Rectangle();        
   void print();

};


#endif