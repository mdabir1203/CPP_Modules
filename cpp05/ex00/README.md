Step by Step Thinking :
1. `Bureaucrat` class: This class will represent a bureaucrat with a name and a grade. It will have the following methods:
   - `Bureaucrat(std::string, int)`: This constructor will initialize a `Bureaucrat` object with the given name and grade. It will throw an exception if the grade is not valid.
   - `getName() const`: This method will return the name of the bureaucrat.
   - `getGrade() const`: This method will return the grade of the bureaucrat.
   - `incrementGrade()`: This method will increment the grade of the bureaucrat by one. It will throw an exception if the new grade is not valid.
   - `decrementGrade()`: This method will decrement the grade of the bureaucrat by one. It will throw an exception if the new grade is not valid.
   - `operator<<`: This operator will print the name and grade of the bureaucrat in a specific format.

2. `GradeTooHighException` class: This class will represent an exception that is thrown when a grade is too high. It will inherit from `std::exception` and have a `what()` method that returns a descriptive message.

3. `GradeTooLowException` class: This class will represent an exception that is thrown when a grade is too low. It will inherit from `std::exception` and have a `what()` method that returns a descriptive message.

4. `main` function: This function will create some `Bureaucrat` objects with valid and invalid grades, try to increment and decrement their grades, catch any exceptions that occur, and print their information using the `operator<<`.

`operator<<`  -> this could be written in two ways remember that 


