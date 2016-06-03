#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
using namespace std;
class Fruit
{
   int no;
   double weight;
   char key;
public:
   void print() {   }
   virtual void process(){   }
};
    
// class Apple: public Fruit
// {
//    int size;
//    char type;
// public:
//    void save() {   }
//    virtual void process(){   }
// };
class bad{};
class Apple: public Fruit
{
public:
     Apple():m_id(0)
     {
        cout<<"Apple default constructor,this="<<this<<" id="<<m_id<<endl;
     }
     Apple(int i):m_id(i)
     {
        cout<<"Apple constructor,this="<<this<<" id="<<m_id<<endl;
        throw bad();
     }
    ~ Apple()
    {
        cout<<"Apple destructor,this="<<this<<" id="<<m_id<<endl;
    }
    void *operator new(size_t size)
    {
        Apple* p=(Apple*)malloc(size);
        cout<<"operator new:"<<size<<endl;
        return p;
    }
    void *operator new[](size_t size)
    {
        Apple* p=(Apple*)malloc(size);
        cout<<"operator new[]:"<<size<<endl;
        return p;
    }
    void operator delete(void* v,size_t size)
    {
        cout<<"operator delete:"<<size<<endl;
        free(v);
    }
    void operator delete[](void* v,size_t size)
    {
        cout<<"operator delete[]:"<<size<<endl;
        free(v);
    }
    /////////////////////////
    void* operator new(size_t size,void *start)
    {
        return start;
    }
    void* operator new(size_t size,long extra)
    {
        return malloc(size+extra);
    }
    void* operator new(size_t size,long extra,char init)
    {
        return malloc(size+extra);
    }
    // void* operator new(long extra,char init)
    // {}
    
    void operator delete(void*,void*)
    {
        cout<<"operator delete(void*,void*)"<<endl;
    }
    void operator delete(void*,long)
    {
        cout<<"operator delete(void*,long)"<<endl;
    }
    void operator delete(void*,long,char)
    {
        cout<<"operator delete(void*,long,char)"<<endl;
    }
private:
    int m_id;
    long m_data;
    string m_str;
    int size;
    char type;
public:
   void save() {   }
   virtual void process(){   }
};
#endif