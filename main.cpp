// g++ main.cpp Car.cpp CarManager.cpp Customer.cpp CustomerManager.cpp Rental.cpp RentalManager.cpp -o carRentalSystem

#include "RentalManager.h"

void displayMenu();
void displayExitArt();
void displayIntroArt();

int main()
{
    size_t selection;
    CarManager carList;
    CustomerManager customerList;
    RentalManager rentalList;

    carList.loadCarsFromFile("carList2.txt");
    customerList.loadCustomersFromFile("customers.txt");

    displayIntroArt();
    do
    {
        displayMenu();

        std::cin >> selection;

        switch (selection)
        {
        case 1:
        {

            rentalList.rentACar(customerList, carList);
            std::cout << std::endl;

            break;
        }
        break;
        case 2:

            size_t rentID;
            std::cout << "Enter Rental Return ID:";
            std::cin >> rentID;
            rentalList.returnRental(rentID);
            std::cout << std::endl;

            break;
        case 3:
            std::cout << "Create A Customer" << std::endl;
            customerList.createCustomer();
            std::cout << std::endl;

            break;
        case 4:
            std::cout << "Add Car to Inventory" << std::endl;
            carList.createNewCar();
            std::cout << std::endl;

            break;
        case 5:
            std::cout << "Display Available Cars" << std::endl;
            carList.displayAllCars();
            std::cout << std::endl;
            break;
        case 6:
            std::cout << YELLOW << "Display All Cars" << std::endl;
            carList.displayAllCars();
            std::cout << std::endl;
            break;
        case 7:
            std::cout << "Display Current Rentals" << std::endl;
            rentalList.displayRentals();
            std::cout << std::endl;
            break;
        case 8:
            std::cout << "Rental History" << std::endl;
            rentalList.displayRentalHistory();
            std::cout << std::endl;
            break;
        case 9:
            std::cout << "Customer List" << std::endl;
            customerList.displayAllCustomers();
            std::cout << std::endl;
            break;

        case 0:
            // Exit Program
            break;

        default:
            std::cout << RED << "Invalid selection. Please try again.\n"
                      << RESET;
            break;
        }
    } while (selection != 0);

    displayExitArt();

    return 0;
}

void displayIntroArt()
{
    std::cout << YELLOW << R"(

        ************************************************
        **                                            **
        ***      Mayberry's Car Rental Service       ***
        ****                                        ****
        ************************************************
        )" << RESET;
}
void displayMenu()
{

    std::cout << GREEN << "Please Make A Selection from the Below Options:\n"
              << RESET;
    std::cout << CYAN << "1. " << MAGENTA << "Rent A Car\n";
    std::cout << CYAN << "2. " << MAGENTA << "Return A Car\n";
    std::cout << CYAN << "3. " << MAGENTA << "Create New Customer\n";
    std::cout << CYAN << "4. " << MAGENTA << "Create New Car Rental\n";
    std::cout << CYAN << "5. " << MAGENTA << "Display Available Cars\n";
    std::cout << CYAN << "6. " << MAGENTA << "Display All Cars\n";
    std::cout << CYAN << "7. " << MAGENTA << "Display Current Rentals\n";
    std::cout << CYAN << "8. " << MAGENTA << "Rental History\n";
    std::cout << CYAN << "9. " << MAGENTA << "Display all customers\n";
    std::cout << CYAN << "0. " << MAGENTA << "Exit Program\n";
    std::cout << YELLOW << "Enter Selection Here: " << RESET << std::endl;
}

void displayExitArt()
{
    std::cout << YELLOW << "Thank you for Choosing Mayberry's \n"
              << RESET;
    std::cout << GREEN << "       Car Rental Service         \n"
              << RESET;
    std::cout << CYAN << "             GoodBye!              \n"
              << RESET;
    std::cout << RED << "                 ______\n"
                        "                //  ||\\ \\ \n"
                        "          _____//___||_\\ \\___\n"
                        "          )  _          _    \\\n"
                        "          |_/ \\________/ \\___|\n"
                        "_____\\___/___/________\\___/______\n"
              << RESET;
    std::cout << "        " << RED << "Thank you for your visit!" << RESET << "\n";
}