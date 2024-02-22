#ifndef RENTALMANAGER_H
#define RENTALMANAGER_H

#pragma once

#include <memory>
#include "Rental.h"
#include <algorithm>

class RentalManager
{
public:
    RentalManager() : nextRentalID(1) {}

    std::vector<std::shared_ptr<Rental>> getRentals() const;
    std::vector<std::shared_ptr<Rental>> getRentalHistory() const;
    void addRental(std::shared_ptr<Rental> rental);
    void addRentalHistory(std::shared_ptr<Rental> addRental);
    float calculateTotalCost() const;
    void returnRental(size_t rentalID);
    std::shared_ptr<Rental> getRentalByID(size_t rentID);
    void displayRentalHistory();
    void displayRentals();
    void rentACar(CustomerManager &customerList, CarManager &carList);

private:
    std::vector<std::shared_ptr<Rental>> rentalList;
    std::vector<std::shared_ptr<Rental>> rentalHistory;
    size_t nextRentalID = 1; // Add this line to declare the nextRentalID variable
};

#endif // RENTALMANAGER_H
