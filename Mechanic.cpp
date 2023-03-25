#include "Person.h"
#include "Mechanic.h"
#include <iostream>
#include <cmath>
void Mechanic::addAppoinment (Person::Appointment app)
{
    if (counter < capacity)
    {
        (booked + counter)->hours = app.hours;
        (this->booked + this->counter)->mins = app.mins;
        counter++;
    }
    else
    {
        std::cout << "array is full" << std::endl;
        exit (1);
    }
}
void Mechanic::setArraySize (int size)
{
    capacity = size;
    booked = new Person::Appointment[capacity];

    for (int i = 0;i < size;i++)
    {
        booked[i].hours = -1;
        booked[i].mins = -1;
    }
}

int Mechanic::getCounter () const
{
    return counter;
}
Person::Appointment Mechanic::getAppointment (int index) const
{
    if (index < counter)
    {
        return *(booked + index);
    }
    else
    {
        std::cout << "Error wrong index" << std::endl;
        exit (1);
    }
}
bool Mechanic::isAvailable (Appointment a)
{
    for (int i = 0; i < counter; i++) {
        // Calculate the time difference in minutes
        int timeDiff = (a.hours - (booked + i)->hours) * 60 + (a.mins - (booked + i)->mins);
        // If the time difference is within 30 minutes, the appointment is not available
        if (abs (timeDiff) < 30) {
            return false;
        }
    }
    // If no conflicting appointment is found, the appointment is available
    return true;
}
