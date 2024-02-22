#ifndef CUSTOMER_H
#define CUSTOMER_H

#pragma once

#include <memory>       // Add this for std::shared_ptr
#include "CarManager.h" // Ensure this includes or forward declares Car

class Customer
{
public:
    Customer(size_t ID, std::string first, std::string last, bool memberStatus = false);

    size_t getCustomerID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    bool isMember() const;
    std::shared_ptr<Car> getCarRental() const; // Updated to use std::shared_ptr<Car>

    void setFirstName(const std::string &first);
    void setLastName(const std::string &last);
    void setIsMember(bool memberStatus);
    void setCarRental(std::shared_ptr<Car> rental); // Updated to use std::shared_ptr<Car>

    void printCustomer() const;
    void printRental() const;

    void clearCarRental(); // Declaration of the new method

private:
    size_t customerID;
    std::string firstName;
    std::string lastName;
    bool _isMember;
    std::shared_ptr<Car> Rental; // Updated to use std::shared_ptr<Car>
};

#endif