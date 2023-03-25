#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.h"
class Customer:public Person
{
private:
    int MechanicID = -1;//the ID of the mecahanic that the customer was assigned to initialized to -1 to indicate that the customer has no mechanic
    Appointment appointment;//stores the appointment of the customer
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