#pragma once
#include "Person.h"
#include "Client.h"
#include <vector>
#include <fstream>

class Employee : public Person {
protected:
    //Attributes
    double salary;
    static int employeeCounter; // Counter for unique ID generation
    vector<Client> clients; // Vector to store clients data



public:
    // Constructors
    //1-Defaule Cons
    //==========================
    Employee() {
        salary = 0;
    }

    //2-Parameterized Cons
    //============================
    Employee(int id, const string& name, const string& password, double salary) : Person(id, name, password) {
        setID(id);
        setSalary(salary);
    }

    // Setters
    void setSalary(double salary) {
        if (Validation::validateMinSalary(salary))
            this->salary = salary;
        else
            cout << "Invalid Salary" << endl;
    }

    void setID(int id) {
        this->id = employeeCounter++;
    }

    // Getters
    double getSalary() {
        return salary;
    }

    //Methods:

    void addClient(Client& client) {
        clients.push_back(client);
        saveClientsToFile();
    }

    void saveClientsToFile() {
        ofstream file("Clients.txt", ios::trunc);
        for (const auto& client : clients) {
            file << client.getId() << " " << client.getName() << " " << client.getPassword() << " " << client.getBalance() << endl;
        }
        file.close();
        cout << "Clients data saved to file." << endl;
    }

    Client* searchClient(int id) {
        for (auto& client : clients) {
            if (client.getId() == id) {
                return &client;
            }
        }
        return nullptr; // Return null if client not found
    }

    void listClients() {
        if (clients.empty()) {
            cout << "No clients available." << endl;
            return;
        }
        cout << "List of Clients:" << endl;
        for (const auto& client : clients) {
            cout << "ID: " << client.getId() << ", Name: " << client.getName()
                << ", Balance: " << client.getBalance() << " EGP" << endl;
        }
    }

    void editClient(int id, string name, string password, double balance) {
        Client* client = searchClient(id);
        if (client) {
            client->setName(name);
            client->setPassword(password);
            client->setBalance(balance);
            saveClientsToFile();
            cout << "Client information updated successfully." << endl;
        }
        else {
            cout << "Client with ID " << id << " not found in the system." << endl;
        }
    }

    //Extra Methods
    void viewClientDetails(string clientID) {
        cout << "Viewing details for client ID: " << clientID << endl;
        // Read client details from Clients.txt
    }

    void approveLoan(string clientID, double amount) {
        cout << "Loan approved for client ID: " << clientID << " Amount: " << amount << " EGP" << endl;
        // Update loan data in client file
    }

    void blockClient(string clientID) {
        cout << "Client ID: " << clientID << " has been blocked!" << endl;
        // Update client status in file
    }

    void updateClientBalance(string clientID, double newBalance) {
        cout << "Updated balance for client ID: " << clientID << " New Balance: " << newBalance << " EGP" << endl;
        // Update client balance in file
    }

    void generateEmployeeReport() {
        cout << "Generating Employee Report..." << endl;
        // Generate a report about employee performance
    }

    // Display Info method (override)
    void displayInfo() {
        cout << "     ** Employee Info **" << endl;
        cout << "Employee ID     : " << id << endl;
        cout << "Employee Name   : " << name << endl;
        cout << "Employee Salary : " << salary << endl;
        cout << "\n==============================\n";
    }
};