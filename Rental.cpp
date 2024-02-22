#include "Rental.h"

size_t Rental::nextRentalID = 1;

Rental::Rental(std::shared_ptr<Customer> customer, std::shared_ptr<Car> car, size_t rentDays)
    : customer(customer), car(car), rentalDays(rentDays), isActive(true), rentalID(nextRentalID++), totalCost(rentDays * car->getPricePerDay()) {}
Rental::Rental(std::shared_ptr<Customer> customer, std::shared_ptr<Car> car, size_t rentDays, size_t rentalID)
    : customer(customer), car(car), rentalDays(rentDays), rentalID(rentalID)
{
    // Constructor implementation...
}
// Getters
std::shared_ptr<Car> Rental::getRentalCar() const { return car; }
std::shared_ptr<Customer> Rental::getRentalCustomer() const { return customer; }
float Rental::getTotalCost() const { return totalCost; }
bool Rental::getIsActive() const { return isActive; }
size_t Rental::getRentalID() const { return rentalID; }

void Rental::setRentalCar(std::shared_ptr<Car> newCar) { car = newCar; }
void Rental::setRentalCustomer(std::shared_ptr<Customer> newCustomer) { customer = newCustomer; }
void Rental::setIsActive(bool active) { isActive = active; }
void Rental::setRentalDays(size_t rentDays) { rentalDays = rentDays; }

void Rental::displayRental() const
{
    std::cout << "Rental ID: " << rentalID << "\n"
              << "Customer: " << customer->getFirstName() << " " << customer->getLastName() << "\n"
              << "Car: " << car->getMake() << " " << car->getModel() << "\n"
              << "Rental Days: " << rentalDays << "\n"
              << "Total Cost: $" << totalCost << "\n"
              << "Active: " << (isActive ? "Yes" : "No") << std::endl;
    std::cout << std::endl;
}
