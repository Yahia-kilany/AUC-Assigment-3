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
            //while loop to create a dynamic array customers from the Customers.txt file
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

    cout << "The customers are: " << endl;
    for (int i = 0; i < CustomerSize;i++)
    {

        (customers + i)->printInfo ();
    }
    customerfile.close ();
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
            //while loop to fill the array mechanics from the Mechanics.txt file
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
    cout << "The mechanics are: " << endl;
    for (int i = 0; i < MechanicSize;i++)
    {
        (mechanics + i)->setArraySize (CustomerSize);
        //set the size of the array booked inside of the objecs in the array mechanics with the size of the customers
        (mechanics + i)->printInfo ();
    }
    int mechanicIndex = 0;
    int currentMechanicIndex;
    for (int i = 0; i < CustomerSize; i++)
    {
        for (int j = 0; j < MechanicSize; j++)
        {
            currentMechanicIndex = (mechanicIndex + j) % MechanicSize;
            if ((mechanics + currentMechanicIndex)->isAvailable ((customers + i)->getAppointment ())) {
                (mechanics + currentMechanicIndex)->addAppoinment ((customers + i)->getAppointment ());
                (customers + i)->setMechanicID ((mechanics + currentMechanicIndex)->getID ());
                break;
            }
        }
        mechanicIndex = (mechanicIndex + 1) % MechanicSize;
    }
    bool swapped;
    for (int i = 0; i < CustomerSize - 1; i++)
        //bubble sorting algorithm to sort array customers ascendingly according to the appointments in each object
    {
        cout << "";
        swapped = false;
        for (int j = 0; j < CustomerSize - i - 1; j++)
        {
            if (*(customers + j) > *(customers + (j + 1)))
            {
                Customer temp = *(customers + (j + 1));
                *(customers + (j + 1)) = *(customers + (j));
                *(customers + (j)) = temp;
                swapped = true;
            }
        }

        //  IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }



    Queue <Customer>customerQueue (CustomerSize);
    for (int i = 0; i < CustomerSize; i++)
        //push the sorting array into a queue
    {
        customerQueue.push (*(customers + i));
    }
    for (int i = 0; i < CustomerSize; i++)
        //start to output the information of the customers and the mechanics that they have an appointment with
    {
        if (customerQueue.top ().getMechanicID () == -1)
            //sees if the custmomer's appointment was rejected
        {
            cout << "The appointment of the customer " << customerQueue.top ().getName () << " was cancelled because no mechanic is available at " <<
                customerQueue.top ().getAppointment ().hours << ":";
            if (customerQueue.top ().getAppointment ().mins <= 9)
                cout << 0;
            cout << customerQueue.top ().getAppointment ().mins << endl;
            customerQueue.pop ();
        }
        else
        {
            for (int j = 0;j < MechanicSize;j++)
            //for loop that finds the mechanic that the customer has an appointment with
            {
                if (customerQueue.top ().getMechanicID () == (mechanics + j)->getID ())
                {
                    cout << "The customer " << customerQueue.top ().getName () << " has an appointment at "
                        << customerQueue.top ().getAppointment ().hours << ":";
                    if (customerQueue.top ().getAppointment ().mins <= 9)
                        cout << 0;
                    cout << customerQueue.top ().getAppointment ().mins << " with  the mechanic " << (mechanics + j)->getName () << endl;
                    customerQueue.pop ();
                    break;
                }
            }
        }
    }
    delete[] mechanics;
    delete[] customers;
    //freeing the memory in arrays mechanics and customers;
    return 0;
}