#include "CustomerManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

CustomerManager::CustomerManager() : nextID(1) {}

void CustomerManager::loadCustomersFromFile(const std::string &fileName)
{
    std::ifstream file(fileName);
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error Opening customer list file." << std::endl;
        return;
    }

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string firstName, lastName, isMemberStr;
        bool isMember;

        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        std::getline(ss, isMemberStr, ',');

        isMember = (isMemberStr == "true" || isMemberStr == "True");

        auto newCustomer = std::make_shared<Customer>(nextID++, firstName, lastName, isMember);

              customerList.push_back(newCustomer);
    }
}

void CustomerManager::createCustomer()
{
    std::string firstName, lastName, isMemberStr;
    bool isMember;

    std::cout << "Enter first name: ";
    std::cin >> std::ws; // Clear leading whitespace
    std::getline(std::cin, firstName);

    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);

    std::cout << "Is the customer a member (y/n)? ";
    std::cin >> isMemberStr;
    isMember = (isMemberStr == "y" || isMemberStr == "Y");

    auto newCustomer = std::make_shared<Customer>(nextID++, firstName, lastName, isMember);
    customerList.push_back(newCustomer);

    std::cout << GREEN << "Customer Created Successfully." << RESET << std::endl;
    newCustomer->printCustomer();
}

std::shared_ptr<Customer> CustomerManager::getCustomerByID(size_t id)
{
    for (const auto &customer : customerList)
    {
        if (customer->getCustomerID() == id)
        {
            return customer;
        }
    }
    return nullptr;
}

void CustomerManager::displayAllCustomers() const
{
    for (const auto &customer : customerList)
    {
        customer->printCustomer();
    }
}
