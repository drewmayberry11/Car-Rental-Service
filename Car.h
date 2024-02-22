#ifndef CAR_H
#define CAR_H

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "ANSIColors.h"
class Car
{
public:
    Car();
    Car(size_t carID, const std::string &make, const std::string &model, size_t year);

    // Parameterized constructor
    Car(size_t carID, const std::string &make, const std::string &model, size_t year,
        const std::string &licensePlate, float pricePerDay, long mileage,
        const std::string &category, bool isAvailable);

    void setCarID(size_t id);
    void setMake(const std::string &m);
    void setModel(const std::string &m);
    void setYear(size_t y);
    void setLicensePlate(const std::string &licenseP);
    void setPricePerDay(float ppd);
    void setMileage(long int m);
    void setCategory(const std::string &c);
    void setIsAvailable(bool available);

    size_t getCarID() const;
    std::string getMake() const;
    std::string getModel() const;
    size_t getYear() const;
    std::string getLicensePlate() const;
    long int getMileage() const;
    std::string getCategory() const;
    bool getIsAvailable() const;
    float getPricePerDay() const;

    void displayCar() const;
    void displayCarRental() const;

private:
    size_t carID;
    std::string make;
    std::string model;
    size_t year;
    std::string licensePlate;
    float pricePerDay;
    int mileage;
    std::string category;
    bool isAvailable;
};

#endif