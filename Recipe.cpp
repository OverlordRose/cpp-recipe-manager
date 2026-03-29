#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/*   Kyla Huhn 5/1/2025		This program allows a user to add,delete,change and view recipes. It checks to make sure the input is valid and saves them
							to a file. It has a function for saving to a file and another function to override the saved data with new save data*/


// Recipe class definition	
class Recipe				
{							
private:					
    string title;
    string ingredients;
	string directions;
    int cookingTime;

public:
	// Default constructor
	Recipe()
	{
		title = "";
		ingredients = "";
		directions = "";
		cookingTime = 0;
	}
    //overloaded constructor
    Recipe(string t, string i, string d, int c)
    {
        title = t;
        ingredients = i;
		directions = d;
        cookingTime = c;
    }

	//getters
	string getTitle()const
	{
		return title;
	}

	string getIngredients() const
	{
		return ingredients;
	}

	string getDirections() const
	{
		return directions;
	}

	int getCookingTime() const
	{
		return cookingTime;
	}

	//setters
	void setTitle(string t)
	{
		title = t;
	}

	void setIngredients(string i)
	{
		ingredients = i;
	}

	void setDirections(string d)
	{
		directions = d;
	}

	void setCookingTime(int c)
	{
		cookingTime = c;
	}
	//friend function to overload << operator
	friend ostream& operator <<(ostream& strm, const Recipe& r);
};

//overload << operator
ostream& operator << (ostream& strm, const Recipe& r)
{
	strm << "Recipe: " << r.title << endl;
	strm << "Ingredients: " << r.ingredients << endl;
	strm << "Directions: " << r.directions << endl;
	strm << "Cooking Time: " << r.cookingTime << " minutes" << endl;
	return strm;
}

//function prototypes
void addRecipe(vector<Recipe>& recipes);
void showRecipes(const vector<Recipe>& recipes);
void changeRecipe(vector<Recipe>& recipes);
void deleteRecipe(vector<Recipe>& recipes);
void saveRecipe(const vector<Recipe>& recipes);
void updateRecipe(const vector<Recipe>& recipes);


int main()
{
	// Create a vector of Recipe objects
	vector<Recipe> recipes;

	//display the menu
	cout << endl;
	cout << "Welcome to my recipe app! Please select a choice from the menu below:" << endl;
	cout << "1. Add a recipe" << endl;
	cout << "2. View all recipes" << endl;
	cout << "3. Change a recipe" << endl;
	cout << "4. Delete a recipe" << endl;
	cout << "5. Exit" << endl;
	int choice;
	cin >> choice;
	cin.ignore();

	//if choice is not a number
	if (cin.fail())
	{
		cout << "Invalid choice! Please enter a number 1-5." << endl;
		cin.clear(); // clear the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
	}

	//make sure the input is a valid number
	else if (choice < 1 || choice > 5)
	{
		cout << "Invalid choice! Please enter a number 1-5." << endl;
	}

	// Loop until the user chooses to exit
	while (choice != 5)
	{
		switch (choice)
		{
			case 1:
				addRecipe(recipes);
				saveRecipe(recipes);
				break;
			case 2:
				showRecipes(recipes); 
				break;
			case 3:
				changeRecipe(recipes);
				updateRecipe(recipes);
				break;
			case 4:
				deleteRecipe(recipes);
				break;
		}
	
		//display menu again
		cout << endl; 
		cout << "Welcome to my recipe app! Please select a choice from the menu below:" << endl;
		cout << "1. Add a recipe" << endl;
		cout << "2. View all recipes" << endl;
		cout << "3. Change a recipe" << endl;
		cout << "4. Delete a recipe" << endl;
		cout << "5. Exit" << endl;
		cin >> choice;
		cin.ignore();


		//if choice is not a number
		if (cin.fail())
		{
			cout << "Invalid choice! Please enter a number 1-5." << endl;
			cin.clear(); // clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
		}

		//make sure the number is valid
		else if (choice < 1 || choice > 5)
		{
			cout << "Invalid choice! Please enter a number 1-5." << endl;
		}
	} 
	cout << "Goodbye!" << endl; 
	return 0;
}

//function to add a recipe
void addRecipe(vector<Recipe>& recipes)
{	
	cout << endl;
	string title, ingredients, directions;
	int cookingTime;
	cout << "Enter the recipe title: ";
	getline(cin, title);

	// Check if the title is empty
	while (title.empty())
	{
		cout << "Title cannot be empty!" << endl;
		cout << "Title: ";
		getline(cin,title);
	}
	cout << "Enter the ingredients: ";
	getline(cin, ingredients);

	// Check if the ingredients are empty
	while (ingredients.empty())
	{
		cout << "Ingredients cannot be empty!" << endl;
		cout << "Ingredients: ";
		getline(cin, ingredients);
	}
	cout << "Enter the directions: ";
	getline(cin, directions);

	// Check if the directions are empty
	while (directions.empty())
	{
		cout << "Directions cannot be empty!" << endl;
		cout << "Enter the directions: ";
		getline(cin, directions);
	}
	cout << "Enter the cooking time (in minutes): ";

	//check if cooking time is valid
	while (!(cin >> cookingTime) || cookingTime <= 0) {
		cout << "Invalid input! Please enter a number greater than 0." << endl;
		cin.clear(); // clears error state
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // removes bad input
		cout << "Enter the cooking time (in minutes): ";
	}
	cin.ignore();

	// Check if the recipe already exists
	if (recipes.size() > 0)
	{
		for (int i = 0; i < recipes.size(); i++)
		{
			if (recipes[i].getTitle() == title)
			{
				cout << "Recipe already exists!" << endl;
				return;
			}
		}
	}
	
	// Create a new Recipe object and add it to the vector
	recipes.emplace_back(title, ingredients, directions, cookingTime);
	cout << "Recipe added!" << endl;
}

//function to display all recipes
void showRecipes(const vector<Recipe>& recipes)
{	
	cout << endl;
	cout << "All Recipes:" << endl;
	for (int i = 0; i < recipes.size(); i++)
	{
		cout << recipes[i];
		cout << endl;
	}
}

//function to change a recipe
void changeRecipe(vector<Recipe>& recipes)
{
	cout << endl;
	int index;
	cout << "Enter the index of the recipe to change (1-" << recipes.size() << "): ";
	cin >> index;
	cin.ignore(); // Clear the newline character from the input buffer
	if (index < 1 || index > recipes.size())
	{
		cout << "Invalid index!" << endl;
		return;
	}
	string title, ingredients, directions;
	int cookingTime;
	cout << "Enter the new recipe title: ";
	getline(cin, title);

	// Check if the title is empty
	while (title.empty())
	{
		cout << "Title cannot be empty!" << endl;
		cout << "Title: ";
		getline(cin, title);
	}
	cout << "Enter the new ingredients: ";
	getline(cin, ingredients);

	// Check if the ingredients are empty
	while (ingredients.empty())
	{
		cout << "Ingredients cannot be empty!" << endl;
		cout << "Ingredients: ";
		getline(cin, ingredients);
	}
	cout << "Enter the new directions: ";
	getline(cin, directions);

	// Check if the directions are empty
	while (directions.empty())
	{
		cout << "Directions cannot be empty!" << endl;
		cout << "Enter the directions: ";
		getline(cin, directions);
	}
	cout << "Enter the cooking time (in minutes): ";

	//check if cooking time is valid
	while (!(cin >> cookingTime) || cookingTime <= 0) {
		cout << "Invalid input! Please enter a number greater than 0." << endl;
		cin.clear(); // clears error state
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // removes bad input
		cout << "Enter the cooking time (in minutes): ";
	}
	cin.ignore();

	// Update the recipe
	recipes[index - 1].setTitle(title);
	recipes[index - 1].setIngredients(ingredients);
	recipes[index - 1].setDirections(directions);
	recipes[index - 1].setCookingTime(cookingTime);
	cout << "Recipe updated!" << endl;

}

//function to delete a recipe
void deleteRecipe(vector<Recipe>& recipes)
{	
	cout << endl;
	int index;
	cout << "Enter the index of the recipe to delete (1-" << recipes.size() << "): ";
	cin >> index;
	cin.ignore(); 
	if (index < 1 || index > recipes.size())
	{
		cout << "Invalid index!" << endl;
		return;
	}
	// Delete the recipe
	recipes.erase(recipes.begin() + index - 1);
	cout << "Recipe deleted!" << endl;
}
//function to save recipe to file
void saveRecipe(const vector<Recipe>& recipes) 
{
	//open file
	ofstream outFile("Recipes.txt", ios::app);
	if (!outFile) {
		cerr << "Error opening file!" << endl;
		return;
	}

	for (const auto& recipe : recipes)
	{
		outFile << recipe << endl;
	}

	outFile.close();
	cout << "Recipe saved!" << endl;
}

//function to overwrite saved data with updated recipe info
void updateRecipe(const vector<Recipe>& recipes)
{
	ofstream outFile("Recipes.txt", ios::trunc); // overwrite the file
	if (!outFile) {
		cerr << "Error opening file!" << endl;
		return;
	}

	for (const auto& recipe : recipes)
	{
		outFile << recipe << endl;
	}

	outFile.close();
	cout << "Recipe saved!" << endl;


}
