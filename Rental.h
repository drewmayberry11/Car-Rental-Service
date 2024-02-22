#ifndef RENTAL_H
#define RENTAL_H

#include <memory> // Required for std::shared_ptr
#include "CustomerManager.h"
#include "CarManager.h"

class Rental
{
public:
    static size_t nextRentalID;

    // Constructor takes shared_ptrs to Customer and Car, plus rental days
    Rental(std::shared_ptr<Customer> customer, std::shared_ptr<Car> car, size_t rentDays);
    Rental(std::shared_ptr<Customer> customer, std::shared_ptr<Car> car, size_t rentDays, size_t rentalID = 0);

    // Getters to access rental properties
    std::shared_ptr<Car> getRentalCar() const;
    std::shared_ptr<Customer> getRentalCustomer() const;
    float getTotalCost() const;
    bool getIsActive() const;
    size_t getRentalID() const;

    // Setters for modifying rental properties
    void setRentalCar(std::shared_ptr<Car> car);
    void setRentalCustomer(std::shared_ptr<Customer> customer);
    void setIsActive(bool isActive);
    void setRentalDays(size_t rentDays);

    void displayRental() const;

private:
    std::shared_ptr<Car> car;
    std::shared_ptr<Customer> customer;
    size_t rentalID;
    size_t rentalDays;
    bool isActive;
    float totalCost;
};

#endif // RENTAL_H