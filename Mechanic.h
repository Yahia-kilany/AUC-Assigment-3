#ifndef MECHANIC_H
#define MECHANIC_H
#include "Person.h"
class Mechanic:public Person
{
private:
    int capacity = 0;//to save the capacity of the array
    int counter = 0;//keeps track of the appointments that the mechanic has
    Appointment* booked = nullptr;//stores the appointment that the mechanic has
public:
    Mechanic () {};//default constructor
    ~Mechanic () { delete[] booked; }
    void setArraySize (int);//allocates the array to a certain size and equates capacity to the parameter
    void addAppoinment (Appointment);//increments counter by 1 and adds an appointment to the array booked
    int getCounter () const;//returns the variable counter
    Appointment getAppointment (int index)const;//returns an appointment object at index (index) while checking if index is smaller than counter
    bool isAvailable (Appointment); //checks if the mechanic is available at the specified appointment keeping in mind that each appointment takes 30 minutes
};
#endif //MECHANIC_H