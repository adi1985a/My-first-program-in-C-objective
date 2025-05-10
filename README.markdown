# Animal Management System

## Overview
This C++ console application manages a database of animals (Cat, Coyote, Cow) with names and ages. It uses `Animal` and `AnimalManager` classes to add animals, display ASCII art, and output species-specific sounds. The program features input validation, dynamic memory management with smart pointers, and a menu-driven interface.

## Features
- **Animal Class**:
  - Attributes: `species` (Cat, Coyote, Cow), `name`, `age` (0–30).
  - `addAnimal`: Prompts for species, name, and age with input validation.
  - `makeSound`: Displays ASCII art (via `animal_ascii.hpp`) and species-specific sounds (e.g., "Meow!" for Cat).
- **AnimalManager Class**:
  - Stores animals in a `std::vector` of `std::unique_ptr<Animal>` for safe memory management.
  - `addNewAnimal`: Adds a new animal to the database.
  - `showAllAnimals`: Displays all animals with their sounds and ASCII art.
- **Interface**:
  - Menu options: Add animal, show all animals, or exit.
  - Input validation for species (1–3) and age (0–30).
- **Main Program**:
  - Runs a loop for user interaction until exit is chosen.
  - Uses `animal_ascii.hpp` for ASCII art display.

## Requirements
- C++ compiler (e.g., g++, clang++) with C++11 or later
- Standard C++ libraries: `<iostream>`, `<vector>`, `<memory>`, `<limits>`, `<algorithm>`
- Custom header: `animal_ascii.hpp` (assumed to provide `displayAsciiArt`)
- Operating system: Any supporting a C++ compiler (e.g., Windows, Linux, macOS)

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Ensure `animal_ascii.hpp` is in the project directory with a valid `displayAsciiArt` function.
3. Save the provided code as `animal_manager.cpp`.
4. Compile the program:
   ```bash
   g++ animal_manager.cpp -o animal_manager
   ```
5. Run the program:
   ```bash
   ./animal_manager
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Displays a menu: Add new animal, Show all animals, Exit.
   - Select options by entering 1, 2, or 3.
3. **Actions**:
   - **Add Animal**: Choose species (1–3), enter name and age (0–30); validated inputs.
   - **Show Animals**: Displays each animal’s species, name, age, ASCII art, and sound.
   - **Exit**: Terminates the program.
4. **Output**:
   - Example: "Cat Fluffy (age 3) says: Meow!" with cat ASCII art.
   - Shows "No animals in the database!" if empty.

## File Structure
- `animal_manager.cpp`: Main C++ source file with program logic.
- `animal_ascii.hpp`: Header file for ASCII art (assumed, not provided).
- `README.md`: This file, providing project documentation.

## Notes
- Requires `animal_ascii.hpp` with `displayAsciiArt` for species ("welcome", "cat", "coyote", "cow").
- Input validation ensures robust handling of non-numeric or out-of-range inputs.
- Uses smart pointers (`std::unique_ptr`) for safe memory management.
- Extend by adding more species, persistent storage, or enhanced ASCII art.
- No locale settings; uses English text for output.
- No external dependencies beyond standard C++ libraries and `animal_ascii.hpp`.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.