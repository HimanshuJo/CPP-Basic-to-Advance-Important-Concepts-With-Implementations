#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    Person();
    Person(string name, int age);
    virtual ~Person();

    string getName() const;
    int getAge() const;

    friend bool operator<(const Person &lhs, const Person &rhs);
    friend bool operator>(const Person &lhs, const Person &rhs);

private:
    string name;
    int age;
};

bool operator<(const Person &lhs, const Person &rhs)
{
    return lhs.getAge() < rhs.getAge();
}

bool operator>(const Person &lhs, const Person &rhs)
{
    return lhs.getAge() > rhs.getAge();
}

Person::Person()
{
}

Person::Person(string name, int age) : name(name), age(age)
{
}

Person::~Person()
{
}

string Person::getName() const
{
    return name;
}

int Person::getAge() const
{
    return age;
}

void SamplePriorityQueueStoreObject()
{
    vector<Person> personVector =
        {
            Person("Person 1", 25),
            Person("Person 2", 17),
            Person("Person 3", 35),
            Person("Person 4", 7),
            Person("Person 5", 50)};

    cout << "======== Less Priority Queue ======= " << endl;

    priority_queue<Person, vector<Person>, less<vector<Person>::value_type>> pqueue_less;

    //fill pqueue_less
    // push less to end
    for (auto it = personVector.cbegin(); it != personVector.cend(); it++)
    {
        pqueue_less.push(*it);
    }

    //iterate,display and pop
    while (!pqueue_less.empty())
    {
        Person value = pqueue_less.top();
        cout << value.getName() << " : " << value.getAge() << endl;

        pqueue_less.pop();
    }

    cout << endl
         << endl;

    cout << "======== Greater Priority Queue ======= " << endl;

    priority_queue<Person, vector<Person>, greater<vector<Person>::value_type>> pqueue_greater;
    //fill pqueue_greater
    // push greater to end
    for (auto it = personVector.cbegin(); it != personVector.cend(); it++)
    {
        pqueue_greater.push(*it);
    }

    //iterate,display and pop
    while (!pqueue_greater.empty())
    {
        Person value = pqueue_greater.top();
        cout << value.getName() << " : " << value.getAge() << endl;

        pqueue_greater.pop();
    }
}

int main(){
    SamplePriorityQueueStoreObject();
}