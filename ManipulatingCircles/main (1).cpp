#include<iostream>
#include "Circle.h"
#include <fstream>
#include <vector>
#include<cstdlib>

#include <fstream>
#include <sstream>

//note that vectors have to be passed by reference
//opens the file using try catch
//if open fails, throw an exception and exit the program
//other wise populate read the data line by line from the data file
//create a new Circle with this data
//push this circle back onto the vector
void inputData(vector<Circle> &circleVector, string filename){
  ifstream inputFile(filename);
  istringstream instream;
  string data;
  int x,y,radius;
  try{
  if (inputFile){
    while (!inputFile.eof()){
      getline(inputFile,data);
       istringstream instream(data);
       instream>>x;
       instream>>y;
       instream>>radius;
       Circle circle(x,y,radius);
       circleVector.push_back(circle);    
  
    }

  }
  else throw string("File Not Found");
  }
  catch (string message){
    std::cout<<message<<std::endl;
    exit(0);
  }

}

int main(){
   //create a vector of circles
   vector<Circle> circleVector;

  //open the data file and populate the vector
   inputData(circleVector, "dataLab4.txt");

  //create an iterator to traverse the vector and print each Circle inside it
  
   vector<Circle>::iterator iter;
   std::cout<<"The circles created are :"<<std::endl;
   
   for ( iter =circleVector.begin();iter!=circleVector.end();iter++) {

    std::cout<<iter->toString()<<std::endl;
    //cout<<circleVector[i].toString();
   }
  
  // print the number of circles ever created using getCount on any element of the vector
    std::cout << "The number of circles ever created is " << Circle::getCount() << std::endl;

  // print the number of circles currently in the vector
   std::cout<<"The numher of circles, using vetor size method is "<<circleVector.size()<<std::endl;
  // erase all circles in the vector
   std::cout<<"Erasing the Vector of Circles"<<std::endl;
   circleVector.clear();
  //create another new circle using default constructor
   std::cout<<"Creating a new Circle"<<std::endl; 
  circleVector.push_back(Circle(0,0,0));//push this new circle onto the vector
  //print the number of circles using get count 
   std::cout << "The number of circles ever created is " << Circle::getCount() << std::endl;
  circleVector.clear();
  //print the number of circles using vector size
   std::cout<<"The number of circles remaining is "<<circleVector.size()<<std::endl;
   
   return 0;
}