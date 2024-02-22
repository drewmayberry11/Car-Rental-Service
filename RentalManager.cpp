#include "RentalManager.h"

std::vector<std::shared_ptr<Rental>> RentalManager::getRentals() const
{
    return rentalList;
}

std::vector<std::shared_ptr<Rental>> RentalManager::getRentalHistory() const
{
    return rentalHistory;
}

void RentalManager::addRental(std::shared_ptr<Rental> addRental) { rentalList.push_back(addRental); }

void RentalManager::addRentalHistory(std::shared_ptr<Rental> addRental) { rentalHistory.push_back(addRental); }

float RentalManager::calculateTotalCost() const
{
    float total = 0.0f;
    for (const auto &rental : rentalList)
    {
        total += rental->getTotalCost();
    }
    return total;
}

void RentalManager::displayRentals()
{
    for (auto rental : rentalList)
    {
        rental->displayRental();
    }
}

void RentalManager::returnRental(size_t rentID)
{
    auto rental = getRentalByID(rentID);
    if (rental)
    {
        rental->setIsActive(false);
        rentalHistory.push_back(rental);

        auto car = rental->getRentalCar();
        if (car)
        {
            car->setIsAvailable(true);
        }

        auto customer = rental->getRentalCustomer();
        if (customer)
        {
            customer->clearCarRental();
        }

        rentalList.erase(std::remove_if(rentalList.begin(), rentalList.end(),
                                        [rentID](const std::shared_ptr<Rental> &rental)
                                        { return rental->getRentalID() == rentID; }),
                         rentalList.end());

        std::cout << "Rental ID " << rentID << " returned successfully.\n";
    }
    else
    {
        std::cout << "Rental ID " << rentID << " not found.\n";
    }
}

std::shared_ptr<Rental> RentalManager::getRentalByID(size_t rentID)
{
    for (const auto &rental : rentalList)
    {
        if (rental->getRentalID() == rentID)
        {
            return rental;
        }
    }
    return nullptr; // Return nullptr if no matching car is found
}

void RentalManager::displayRentalHistory()
{
    for (auto rental : rentalHistory)
    {
        rental->displayRental();
    }
}

void RentalManager::rentACar(CustomerManager &customerList, CarManager &carList)
{
    // Example input gathering process
    size_t customerId, carId, rentDays;
    std::cout << "Enter customer ID: ";
    std::cin >> customerId;
    std::cout << "Enter car ID: ";
    std::cin >> carId;
    std::cout << "Enter number of rental days: ";
    std::cin >> rentDays;

    // Assuming CustomerManager and CarManager have methods to get a customer and a car by ID
    auto selectedCustomer = customerList.getCustomerByID(customerId);
    auto selectedCar = carList.getCarByID(carId);

    if (selectedCustomer != nullptr && selectedCar != nullptr && selectedCar->getIsAvailable())
    {
        // Mark the car as not available
        selectedCar->setIsAvailable(false);

        // Create a new Rental instance with the correct argument order
        auto newRental = std::make_shared<Rental>(selectedCustomer, selectedCar, rentDays, nextRentalID++);
        addRental(newRental); // Add the new rental to the list of current rentals

        std::cout << "Successful Rental Creation\n";
        // Assuming Rental class has a method to display rental details
        newRental->displayRental();
    }
    else
    {
        std::cout << "Error: Customer or Car not found, or Car is not available.\n";
    }
}