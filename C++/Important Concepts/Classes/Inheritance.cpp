/*
Inheritance in C++ takes place between classes. 

In an inheritance (is-a) relationship, the class being inherited from is called 
the parent class, base class, or superclass, and the class doing the inheriting 
is called the child class, derived class, or subclass.

E.g 1.              Fruit <- Apple
                          <- Banana

In the above diagram, Fruit is the parent, and both Apple and Banana are children.

E.g 2.              Shape <- Triangle <- Right Triangle

                          <- Quadrilateral <- Rectangle <- Square

Here, Triangle is both a child (to Shape) and a parent (to Right Triangle)

-------

A child class inherits both behaviors (member functions) and properties 
(member variables) from the parent (subject to some access restrictions that 
we’ll cover in a future lesson).

These variables and functions become members of the derived class.

Because child classes are full-fledged classes, they can (of course) 
have their own members that are specific to that class.
*/

/*
A Person class
Here’s a simple class to represent a generic person:
*/

#include <string>
#include <iostream>

class Person
{
// In this example, we're making our members public for simplicity
public:
    std::string m_name{};
    int m_age{};

    Person(const std::string &name = "", int age = 0): m_name{ name }, m_age{ age }{}

    const std::string &getName() const { return m_name; }
    int getAge() const { return m_age; }
};

/*
Because this Person class is designed to represent a generic person, 
we’ve only defined members that would be common to any type of person. 
Every person (regardless of gender, profession, etc…) has a name and age, 
so those are represented here.

-------

A BaseballPlayer class

Let’s say we wanted to write a program that keeps track of information about some baseball players. 

Baseball players need to contain information that is specific to baseball players -- 

for example, 
    
    we might want to store a player’s batting average, and the number of home runs they’ve hit.
*/

/*
We also want to keep track of a baseball player’s name and age, 
and we already have that information as part of our Person class.

We have three choices for how to add name and age to BaseballPlayer:

    Add name and age to the BaseballPlayer class directly as members. 

        This is probably the worst choice, as we’re duplicating code that 
        already exists in our Person class. 

        Any updates to Person will have to be made in BaseballPlayer too.

    Add Person as a member of BaseballPlayer using composition.
    
        But we have to ask ourselves, “does a BaseballPlayer have a Person”? 
        No, it doesn’t. So this isn’t the right paradigm.

        Have BaseballPlayer inherit those attributes from Person. 
        Remember that inheritance represents an is-a relationship. 
        Is a BaseballPlayer a Person? Yes, it is. So inheritance is a good choice here.

    Making BaseballPlayer a derived class

        To have BaseballPlayer inherit from our Person class, the syntax is fairly simple. 
        After the class BaseballPlayer declaration, we use a colon, the word “public”, 
        and the name of the class we wish to inherit. 

        This is called public inheritance. We’ll talk more about what public inheritance 
        means in a future lesson.
*/

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
public:
    double m_battingAverage{};
    int m_homeRuns{};

    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
       : m_battingAverage{battingAverage}, m_homeRuns{homeRuns}
    {
    }
};

/*
An Employee derived class

Now let’s write another class that also inherits from Person. 

This time, we’ll write an Employee class. An employee “is a” person, so 
using inheritance is appropriate:
*/

// Employee publicly inherits from Person
class Employee: public Person
{
public:
    double m_hourlySalary{};
    long m_employeeID{};

    Employee(double hourlySalary = 0.0, long employeeID = 0)
        : m_hourlySalary{hourlySalary}, m_employeeID{employeeID}
    {
    }

    void printNameAndSalary() const
    {
        std::cout << m_name << ": " << m_hourlySalary << '\n';
    }
};

class Supervisor: public Employee
{
public:
    // This Supervisor can oversee a max of 5 employees
    long m_overseesIDs[5]{};
};

/*
Inheritance chains

    It’s possible to inherit from a class that is itself derived from another class. 
    There is nothing noteworthy or special when doing so -- everything proceeds 
    as in the examples above.

    For example, let’s write a Supervisor class. 

    A Supervisor is an Employee, which is a Person.

    We’ve already written an Employee class, so let’s use that as the base class 
    from which to derive Supervisor:
*/

/*
Person <- BaseballPlayer
    
       <- Employee <- Supervisor

All Supervisor objects inherit the functions and variables from both Employee 
and Person, and add their own m_overseesIDs member variable.

By constructing such inheritance chains, we can create a set of reusable classes 
that are very general (at the top) and become progressively more specific at 
each level of inheritance.
*/

int main()
{
    // Create a new BaseballPlayer object
    BaseballPlayer joe{};
    // Assign it a name (we can do this directly because m_name is public)
    joe.m_name = "Joe";
    // Print out the name
    std::cout << joe.getName() << '\n'; // use the getName() function we've acquired from the Person base class
    std::cout<< "------- ******* -------\n";
    Employee frank{20.25, 12345};
    frank.m_name = "Frank"; // we can do this because m_name is public
    frank.printNameAndSalary();
    return 0;
}

/*
    Output:

    Joe
    ------- ******* -------
    Frank: 20.25
*/