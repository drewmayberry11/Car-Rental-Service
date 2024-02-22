#include "CarManager.h"

size_t nextCarID = 1; // Start IDs from 1

void CarManager::loadCarsFromFile(const std::string &fileName)
{
    std::ifstream file(fileName);
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error Opening File" << std::endl;
        return; // Early return if file can't be opened
    }

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        // Adjust the size check according to your new format (without the ID)
        if (tokens.size() == 8)
        { // Assuming one less token since ID is removed
            try
            {
                // Removed the carID from being read from tokens

                const std::string &make = tokens[0];
                const std::string &model = tokens[1];
                size_t year = std::stoull(tokens[2]);
                std::string licensePlate = tokens[3];
                float pricePerDay = std::stof(tokens[4]);
                long mileage = std::stol(tokens[5]);
                std::string category = tokens[6];
                bool isAvailable = tokens[7] == "true";

                auto car = std::make_shared<Car>(nextCarID++, make, model, year, licensePlate, pricePerDay, mileage, category, isAvailable);
                carList.push_back(car);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error Processing Line " << line << "\n"
                          << e.what() << std::endl;
            }
        }
        else
        {
            std::cerr << "Incorrect number of arguments on line " << line << std::endl;
        }
    }
}

void CarManager::createNewCar()
{
    std::string make, model, licensePlate, category, isAvailableInput;
    size_t year;
    float pricePerDay;
    long mileage;
    bool isAvailable;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any leftover newline character

    std::cout << "Enter car make: ";
    std::getline(std::cin, make);

    std::cout << "Enter car model: ";
    std::getline(std::cin, model);

    std::cout << "Enter car year: ";
    std::cin >> year;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer

    std::cout << "Enter license plate: ";
    std::getline(std::cin, licensePlate);

    std::cout << "Enter price per day: ";
    std::cin >> pricePerDay;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer

    std::cout << "Enter mileage: ";
    std::cin >> mileage;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer

    std::cout << "Enter car category: ";
    std::getline(std::cin, category);

    std::cout << "Is the car available? y(yes) n(no): ";
    std::getline(std::cin, isAvailableInput);
    isAvailable = (isAvailableInput == "y" || isAvailableInput == "Y");

    auto newCar = std::make_shared<Car>(nextCarID++, make, model, year, licensePlate, pricePerDay, mileage, category, isAvailable);
    carList.push_back(newCar);

    std::cout << "New car added successfully!\n";

    newCar->displayCar();
}

std::shared_ptr<Car> CarManager::getCarByID(size_t ID)
{
    for (const auto &car : carList)
    {
        if (car->getCarID() == ID)
        {
            return car;
        }
    }
    return nullptr; // Return nullptr if no matching car is found
}

void CarManager::displayAllCars() const
{
    for (const auto &car : carList)
    {
        car->displayCar();
        std::cout << "\n";
    }
}

void CarManager::displayAvailableCars() const
{
    for (const auto &car : carList)
    {
        if (car->getIsAvailable())
        {
            std::cout << "Display cars"
                      << std::endl;
        }
    }
}
