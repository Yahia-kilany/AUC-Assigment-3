#include "Person.h"
#include "Customer.h"
#include <iostream>
using namespace std;

void Customer::setMechanicID (int num)
{
    MechanicID = num;
}
void Customer::setAppointment (Appointment app)
{
    appointment = app;
}
int Customer::getMechanicID () const
{
    return MechanicID;
}
Person::Appointment Customer::getAppointment () const
{
    return appointment;
}
bool Customer::operator <(const Customer& customer)
{
    bool ans;
    if (this->appointment.hours < customer.appointment.hours)
    {
        ans = true;
    }
    else if (this->appointment.hours == customer.appointment.hours)
    {
        if (this->appointment.mins < customer.appointment.mins)
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
    }
    return ans;
}
bool Customer::operator >(const Customer& customer)
{
    bool ans;
    if (this->appointment.hours > customer.appointment.hours)
    {
        ans = true;
    }
    else if (this->appointment.hours == customer.appointment.hours)
    {
        if (this->appointment.mins > customer.appointment.mins)
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
    }
    return ans;
}
bool Customer::operator ==(const Customer& customer)
{
    bool ans;
    if ((this->appointment.hours == customer.appointment.hours) && this->appointment.mins == customer.appointment.mins)
    {
        ans = true;
    }
    else
    {
        ans = false;
    }
    return ans;
}
