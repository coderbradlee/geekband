#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

class Fruit
{
   int no;
   double weight;
   char key;
public:
   void print() {   }
   virtual void process(){   }
};
    
class Apple: public Fruit{
   int size;
   char type;
public:
   void save() {   }
   virtual void process(){   }
};

#endif