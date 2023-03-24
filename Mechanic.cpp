#include "Person.h"
#include "Mechanic.h"
#include <iostream>
void Mechanic::addAppoinment (Person::Appointment app)
{
    *(booked + counter) = app;
    counter++;
}
void Mechanic::setArraySize (int count)
{
    booked = new Person::Appointment[count];
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
    for (int i = 0; i < counter;i++)
    {
        if ((booked + i)->hours == a.hours)
        {
            if ((((booked + i)->mins + a.mins) != 30))
            {
                return false;
            }
        }
    }
    return true;
}