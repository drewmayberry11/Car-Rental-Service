#include "Customer.h"

// Constructor already provided
Customer::Customer(size_t ID, std::string first, std::string last, bool memberStatus)
    : customerID(ID), firstName(first), lastName(last), _isMember(memberStatus) {}

// Getters
size_t Customer::getCustomerID() const { return customerID; }
std::string Customer::getFirstName() const { return firstName; }
std::string Customer::getLastName() const { return lastName; }
bool Customer::isMember() const { return _isMember; }
std::shared_ptr<Car> Customer::getCarRental() const { return Rental; }

// Setters
void Customer::setFirstName(const std::string &first) { firstName = first; }
void Customer::setLastName(const std::string &last) { lastName = last; }
void Customer::setIsMember(bool memberStatus) { _isMember = memberStatus; }
void Customer::setCarRental(std::shared_ptr<Car> rental)
{
    Rental = rental;
}

void Customer::printCustomer() const
{
    std::cout << std::left << std::setw(2) << customerID << " " << firstName << " " << lastName << std::endl;
}

void Customer::clearCarRental()
{
    Rental.reset();
}