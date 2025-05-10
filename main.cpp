#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include <algorithm>
#include "animal_ascii.hpp"

class Animal {
private:
    std::string species;
    std::string name;
    int age;

public:
    Animal() : age(0) {}
    
    void addAnimal() {
        bool validInput = false;
        
        displayAsciiArt("welcome");
        
        do {
            std::cout << "\n=== ADDING A NEW PET TO THE DATABASE ===\n";
            std::cout << "Available species (starting with C):\n";
            std::cout << "1. Cat\n2. Coyote\n3. Cow\n";
            std::cout << "Choose animal type (1-3): ";
            
            int choice;
            if (std::cin >> choice) {
                switch (choice) {
                    case 1: species = "Cat"; validInput = true; break;
                    case 2: species = "Coyote"; validInput = true; break;
                    case 3: species = "Cow"; validInput = true; break;
                    default: std::cout << "Invalid choice! Please try again.\n";
                }
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input! Please enter a number.\n";
            }
        } while (!validInput);

        std::cout << "Enter the name: ";
        std::cin >> name;

        do {
            std::cout << "Enter the age (0-30): ";
            if (std::cin >> age && age >= 0 && age <= 30) {
                validInput = true;
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid age! Please enter a number between 0 and 30.\n";
                validInput = false;
            }
        } while (!validInput);
    }

    void makeSound() const {
        std::cout << "\n=== ANIMAL SOUND ===\n";
        if (species == "Cat") {
            displayAsciiArt("cat");
            std::cout << species << " " << name << " (age " << age << ") says: Meow!\n";
        } else if (species == "Coyote") {
            displayAsciiArt("coyote");
            std::cout << species << " " << name << " (age " << age << ") says: Wow-Wooo!\n";
        } else if (species == "Cow") {
            displayAsciiArt("cow");
            std::cout << species << " " << name << " (age " << age << ") says: Mooo!\n";
        }
    }

    std::string getSpecies() const { return species; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
};

class AnimalManager {
private:
    std::vector<std::unique_ptr<Animal>> animals;

public:
    void addNewAnimal() {
        auto animal = std::make_unique<Animal>();
        animal->addAnimal();
        animals.push_back(std::move(animal));
    }

    void showAllAnimals() const {
        if (animals.empty()) {
            std::cout << "\nNo animals in the database!\n";
            return;
        }

        std::cout << "\n=== ALL ANIMALS ===\n";
        for (const auto& animal : animals) {
            animal->makeSound();
        }
    }
};

int main() {
    AnimalManager manager;
    char choice;

    do {
        std::cout << "\n=== ANIMAL MANAGEMENT SYSTEM ===\n";
        std::cout << "1. Add new animal\n";
        std::cout << "2. Show all animals\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice (1-3): ";

        std::cin >> choice;

        switch (choice) {
            case '1':
                manager.addNewAnimal();
                break;
            case '2':
                manager.showAllAnimals();
                break;
            case '3':
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (true);

    return 0;
}
