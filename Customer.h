#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.h"
class Customer:public Person
{
private:
    int MechanicID=-1;
    Appointment appointment;
public:
    Customer () {};
    void setMechanicID (int); //setter for member variable MechanicID
    void setAppointment (Appointment); //setter for the member variable appointment
    int getMechanicID () const; //returns the member variable MechanicID
    Appointment getAppointment () const; //returns the member variable appointment
    bool operator < (const Customer&);
    bool operator > (const Customer&);
    bool operator == (const Customer&);
    // operator overloads to compare between customer’s appointment
};
#endif //CUSTOMER_H 