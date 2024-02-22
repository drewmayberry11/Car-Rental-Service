#ifndef CARMANAGER_H
#define CARMANAGER_H

#pragma once

#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Car.h"
#include <limits>

class CarManager
{
public:
    CarManager() = default;

    void loadCarsFromFile(const std::string &fileName);
    std::shared_ptr<Car> getCarByID(size_t ID);
    void displayAllCars() const;
    void displayAvailableCars() const;
    void createNewCar();

private:
    std::vector<std::shared_ptr<Car>> carList;
};

#endif // CARMANAGER_H
