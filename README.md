# C++ Recipe Manager  
A console-based recipe management application written in C++.  
This program allows users to add, view, update, delete, and save recipes using object‑oriented design and file handling.

## 📌 Features
- Add new recipes with:
  - Title  
  - Ingredients  
  - Directions  
  - Cooking time  
- View all saved recipes  
- Update an existing recipe  
- Delete a recipe  
- Save recipes to a text file  
- Overwrite saved data when changes are made  
- Input validation for:
  - Empty fields  
  - Invalid numbers  
  - Invalid menu choices  

## 🧱 Technologies Used
- **C++**
- **Object-Oriented Programming (OOP)**
- **Vectors**
- **File I/O (`fstream`)**
- **Operator Overloading**
- **Input Validation**

## 🧩 How It Works
Recipes are stored in a `vector<Recipe>` and written to a file (`Recipes.txt`) using two save modes:
- **Append mode** when adding new recipes  
- **Truncate mode** when updating existing recipes  

The `Recipe` class includes:
- Constructors  
- Getters and setters  
- A friend function to overload the `<<` operator for clean output  

## ▶️ Running the Program
Compile using any C++ compiler. Example with g++:

```bash
g++ main.cpp -o recipe_app
./recipe_app
