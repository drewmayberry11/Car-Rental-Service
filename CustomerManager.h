#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#pragma once

#include "Customer.h"

class CustomerManager
{
public:
    CustomerManager();

    void loadCustomersFromFile(const std::string &fileName);
    std::shared_ptr<Customer> getCustomerByID(size_t id); // Updated return type
    void createCustomer();                                // Added parameters for customer creation
    void displayAllCustomers() const;

    void addCustomer();

private:
    std::vector<std::shared_ptr<Customer>> customerList; // Use std::shared_ptr for customers
    size_t nextID;
};

#endif // CUSTOMERMANAGER_H