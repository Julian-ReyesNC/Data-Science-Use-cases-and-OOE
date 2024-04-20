#include<string>
using namespace std;
#ifndef CIRCLE_H// this is optional
#define CIRCLE_H // works with or without it
class Circle{  
private:
   static int count; // static variable that keeps global count
                     //across all Circle objects
   int radius;
   int x,y;
public:
Circle();
Circle(int xcoord,int ycoord, int r);
int getY();
int getX();
int getRadius();
static int getCount();// get count method to report the current count
double getArea();
double getCircumference();
double getDistance(Circle other);
bool intersects(Circle other);
Circle resize(int scale);//to copy self to other;
void resize(double scale);//for self

void setX(int xcoord);
void setY(int xcoord);
void setRadius(int r);
bool greaterThan(Circle * other);
string toString();
~Circle();
//regular functions
//void inputData(vector<Circle>);
};

#endif
