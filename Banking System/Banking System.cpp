#include <iostream>
#include <string>
#include <stdexcept>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Validation.h"

int Client::clientCounter = 0;
const string Client::bankKey = "2025";
int Employee::employeeCounter = 1;

int main() {

    Client c(0, "Route Academy", "Route@Academy", 5000);
    Client c1(0, "Route academy", "Route@Academy", 5000);

    Employee e(2, "Yazan Osama", "Yazan@Osama", 7000);
    Employee e1(2, "Yazan Osama", "Yazan@Osama", 7000);

    Admin a(0, "Osama Farag", "Osama@Farag", 10000);

    c.displayInfo();
    c1.displayInfo();

    e.displayInfo();
    e1.displayInfo();

    a.displayInfo();
}
