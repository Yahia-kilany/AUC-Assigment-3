#ifndef MECHANIC_H
#define MECHANIC_H
#include "Person.h"
class Mechanic:public Person
{
private:
    int counter;//keeps track of the appointments that the mechanic has
    Appointment* booked=nullptr;//stores the appointment that the mechanic has
public:
    Mechanic () {};//default constructor
    ~Mechanic () { delete[] booked; }
    void setArraySize (int);//initializes the array booked to a certain size
    void addAppoinment (Appointment);//increments counter by 1 and adds an appointment to the array booked
    int getCounter () const;//returns the variable counter
    Appointment getAppointment (int index)const;//returns an appointment object at index (index) while checking if index is smaller than counter
    bool isAvailable (Appointment); //checks if the Mechanic is available at the appointment 
};
#endif //MECHANIC_H