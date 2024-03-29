/*
C++ Classes/Objects

C++ is an object-oriented programming language.

  Everything in C++ is associated with classes and objects, along with its 
  attributes and methods. 

  For example: in real life, a car is an object. 

    The car has attributes, such as weight and color, and methods, such as drive and brake.

  Attributes and methods are basically variables and functions that belongs to the class. 

    These are often referred to as "class members".

  A class is a user-defined data type that we can use in our program, and it works as an 
  object constructor, or a "blueprint" for creating objects.
*/

#include<iostream>
#include<string>
using namespace std;

class MyClass {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
};

/*
Create an Object

  In C++, an object is created from a class. 

  We have already created the class named MyClass, so now we can use this to 
  create objects.

  To create an object of MyClass, specify the class name, followed by the object name.

  To access the class attributes (myNum and myString), use the dot syntax (.) 
  on the object:
*/

int main() {
  MyClass myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.myNum = 15; 
  myObj.myString = "Some text";

  cout << myObj.myNum << "\n";
  cout << myObj.myString;
  return 0;
}