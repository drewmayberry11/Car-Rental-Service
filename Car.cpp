#include "Car.h"

Car::Car() : carID(0), make(""), model(""), year(0), licensePlate(""), pricePerDay(0.0f), mileage(0), category("Standard"), isAvailable(true) {}

Car::Car(size_t carID, const std::string &make, const std::string &model, size_t year)
    : carID(carID), make(make), model(model), year(year), licensePlate(""), pricePerDay(0.0f), mileage(0), category("Standard"), isAvailable(true) {}

// Parameterized constructor implementation
Car::Car(size_t carID, const std::string &make, const std::string &model, size_t year,
         const std::string &licensePlate, float pricePerDay, long mileage,
         const std::string &category, bool isAvailable)
    : carID(carID), make(make), model(model), year(year), licensePlate(licensePlate),
      pricePerDay(pricePerDay), mileage(mileage), category(category), isAvailable(isAvailable) {}

void Car::setCarID(size_t id) { carID = id; }
void Car::setMake(const std::string &m) { make = m; }
void Car::setModel(const std::string &m) { model = m; }
void Car::setYear(size_t y) { year = y; }
void Car::setLicensePlate(const std::string &licenseP) { licensePlate = licenseP; }
void Car::setPricePerDay(float ppd) { pricePerDay = ppd; }
void Car::setMileage(long int m) { mileage = m; }
void Car::setCategory(const std::string &c) { category = c; }
void Car::setIsAvailable(bool available) { isAvailable = available; }

size_t Car::getCarID() const { return carID; }
std::string Car::getMake() const { return make; }
std::string Car::getModel() const { return model; }
size_t Car::getYear() const { return year; }
std::string Car::getLicensePlate() const { return licensePlate; }
long int Car::getMileage() const { return mileage; }
std::string Car::getCategory() const { return category; }
bool Car::getIsAvailable() const { return isAvailable; }
float Car::getPricePerDay() const { return pricePerDay; }

void Car::displayCar() const
{
    std::string availabilityColor = isAvailable ? GREEN : RED;

    // Indentation and alignment
    int labelWidth = 15; // Adjust as needed for alignment

    std::cout << LIGHT_BLUE << year << " " << make << " " << model << RESET << "\n";
    std::cout << std::left << std::setw(labelWidth) << "ID:" << carID << "\n";
    std::cout << std::left << std::setw(labelWidth) << "License:" << licensePlate << "\n";
    std::cout << std::left << std::setw(labelWidth) << "Mileage:" << mileage << " miles\n";
    std::cout << std::left << std::setw(labelWidth) << "Category:" << category << "\n";
    std::cout << std::left << std::setw(labelWidth) << "Price/Day:"
              << "$" << pricePerDay << "\n";
    std::cout << std::left << std::setw(labelWidth) << "Availability:" << availabilityColor << (isAvailable ? "Available" : "Not Available") << RESET << "\n";
}
