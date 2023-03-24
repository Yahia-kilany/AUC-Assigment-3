#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person
{
private:
    std::string name;
    int ID;
    int age;
public:
    Person () {}; //default constructor
    void setName (std::string); //setter for memeber variable name
    void setID (int); //setter for memeber variable ID
    void setAge (int); //setter for member variable age
    std::string getName () const; //returns member variable name
    int getID () const; //returns member variable ID
    int getAge () const; //returns member variable age
    void printInfo (); //prints the person's information
    struct Appointment
    {
        int hours;
        int mins;
    };
};


#endif //PERSON_H