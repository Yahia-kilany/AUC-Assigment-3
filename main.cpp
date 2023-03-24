#include <iostream>
#include <fstream>
#include "Person.h"
#include "Customer.h"
#include "Mechanic.h"
#include "Queue.h"
using namespace std;

int main ()
{
    Customer* customers = new Customer[1]; // allocate memory for the new customers array
    int CustomerSize = 0; // initialize the counter for the size of the customers array
    ifstream customerfile;
    customerfile.open ("Customers.txt");
    if (customerfile.fail ())
    {
        cout << "there was an error while opening this file" << endl;
        exit (1);
    }
    else
    {
        string name;
        int age;
        int id;
        Person::Appointment a;
        Customer* temporaryCustomer = NULL;

        while (getline (customerfile , name))
        {
            // set new customer
            temporaryCustomer = new Customer[CustomerSize + 1];

            // copy the existing customers to the new memory block
            for (int i = 0; i < CustomerSize; i++)
            {
                *(temporaryCustomer + i) = *(customers + i);
            }

            // read in the new customer data
            customerfile >> id;
            customerfile >> age;
            (temporaryCustomer + CustomerSize)->setName (name);
            (temporaryCustomer + CustomerSize)->setAge (age);
            (temporaryCustomer + CustomerSize)->setID (id);

            customerfile >> a.hours;
            customerfile >> a.mins;
            (temporaryCustomer + CustomerSize)->setAppointment (a);

            CustomerSize++; // increment the size of the customers array

            // update the pointer
            delete[] customers;
            customers = temporaryCustomer;
            temporaryCustomer = nullptr;
            customerfile.ignore (1000 , '\n'); // skip to the next line
        }
    }
    customerfile.close ();

    //print out the customer information
    for (int i = 0; i < CustomerSize; i++)
    {
        (customers + i)->printInfo ();
    }

    Mechanic* mechanics = new Mechanic[1]; // allocate memory for the new mechanics array
    int MechanicSize = 0; // initialize the counter for the size of the mechanics array
    ifstream MechanicFile ("Mechanics.txt");

    if (MechanicFile.fail ())
    {
        cout << "there was an error while opening this file" << endl;
        exit (1);
    }
    else
    {
        string name;
        int age;
        int id;
        Mechanic* temporaryMechanic = nullptr;

        while (MechanicFile >> name >> id >> age)
        {
            // set new mechanic
            temporaryMechanic = new Mechanic[MechanicSize + 1];

            // copy the existing mechanics to the new memory block
            for (int i = 0; i < MechanicSize; i++)
            {
                *(temporaryMechanic + i) = *(mechanics + i);
            }

            // read in the new mechanic data

            (temporaryMechanic + MechanicSize)->setName (name);
            (temporaryMechanic + MechanicSize)->setAge (age);
            (temporaryMechanic + MechanicSize)->setID (id);
            // (temporaryMechanic + MechanicSize)->setArraySize(CustomerSize);
            MechanicSize++; // increment the size of the mechanics array

            // update the pointer
            delete[] mechanics;
            mechanics = temporaryMechanic;
            temporaryMechanic = nullptr;
        }
    }
    MechanicFile.close ();
    for (int i = 0; i < MechanicSize; i++)
    {
        (mechanics + i)->printInfo ();
    }
    int mechanicIndex = 0;
    for (int i = 0; i < CustomerSize; i++)
    {
        bool assigned = false;
        for (int j = 0; j < MechanicSize; j++) {
            int currentMechanicIndex = (mechanicIndex + j) % MechanicSize;
            if ((mechanics + currentMechanicIndex)->isAvailable ((customers + i)->getAppointment ())) {
                (mechanics + currentMechanicIndex)->addAppoinment ((customers + i)->getAppointment ());
                (customers + i)->setMechanicID ((mechanics + currentMechanicIndex)->getID ());
                assigned = true;
                break;
            }
        }
        mechanicIndex = (mechanicIndex + 1) % MechanicSize;
    }
    int i , j;
    bool swapped;
    for (i = 0; i < CustomerSize - 1; i++)
    {
        swapped = false;
        for (j = 0; j < CustomerSize - i - 1; j++)
        {
            if (*(customers+j) > *(customers+(j + 1)))
            {
                Customer temp = *(customers+j);
                *(customers+j) = *(customers+(j+1));
                *(customers+(j+1)) = temp;
            }
        }

        
        if (swapped == false)
            break;
    }
    Queue <Customer>customerQueue;
    for (int i = 0; i < CustomerSize; i++)
    {
        customerQueue.Enqueue(*(customers+i));
    }
    

    return 0;
}