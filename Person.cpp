#include "Person.h"
#include <iostream>
using namespace std;
void Person::setName (string str)
{
    name = str;
}
void Person::setID (int id)
{
    ID = id;
}
void Person::setAge (int n)
{
    age = n;
}
string Person::getName () const
{
    return name;
}
int Person::getID () const
{
    return ID;
}
int Person::getAge () const
{
    return age;
}
void Person::printInfo ()
{
    cout << "Name: " << name << endl << "ID: " << ID << endl << "Age: " << age << endl;

}