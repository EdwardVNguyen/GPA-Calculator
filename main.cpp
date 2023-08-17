#include <iostream>
#include <iomanip>

//Program will ask number instead of letter grade and will calculate like so -->
// A:100-90, B:89-80, C:79-70, D:69-60, F: 59-0 

int getQualityPoints(int& grade, int& creditHours);
int getGrade();
int getCreditHours();

int main()
{
	int numCourses;
	int totalQualityPts = 0;
	int totalCreditHours = 0;
	float gpa;

	// Gets number of courses
	while (true)
	{
		std::cout << "Input number of courses: ";
		std::cin >> numCourses;
		std::cout << "\n";

		// checks if numCourses in an integer and not anything else
		if (!std::cin)
		{
			std::cout << "Input has to be a number!\n";
			// clears previous input
			std::cin.clear();
			// skips to newline, cin.ignore discards characters in the input stream. 
			// Ex: cin.ignore(120,'/n') will skip the next 120 input character or until a newline character is read.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else if (numCourses <= 0)
		{
			std::cout << "Input has to be greater than zero!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else break;
	}


	// Gets GPA and credit value for each course
	for (int i = 0; i < numCourses; ++i)
	{
		int grade, creditHours, qualityPoints;

		grade = getGrade();
		creditHours = getCreditHours();
		qualityPoints = getQualityPoints(grade, creditHours);

		totalQualityPts += qualityPoints;
		totalCreditHours += creditHours;
	}
	gpa = (totalQualityPts + 0.0) / totalCreditHours; // the 0.0 is to convert the int into a float
	
	std::cout << std::setprecision(3);
	std::cout << "\nYour GPA is " << gpa << "!\n";
}

// Quality points is grade multiplied by credit hours
int getQualityPoints(int &grade, int &creditHours)
{
	return grade * creditHours;
}

int getGrade()
{
	int grade, convertedGrade;

	while (true)
	{
		std::cout << "Input Grade: ";
		std::cin >> grade;
		std::cout << "\n";

		if (!std::cin)
		{
			std::cout << "Input has to be a number!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else break;
	}

	// Anything above a 100 will be converted to 100, anything below 0 will be converted to 0
	if (grade > 100)
	{
		grade = 100;
	}
	if (grade < 0)
	{
		grade = 0;
	}

	// Converts grades to grade point per credit hour earned
	if ((grade <= 100) && (grade >= 90))
	{
		convertedGrade = 4;
	}
	else if ((grade <= 89) && (grade >= 80))
	{
		convertedGrade = 3;
	}
	else if ((grade <= 79) && (grade >= 70))
	{
		convertedGrade = 2;
	}
	else if ((grade <= 69) && (grade >= 60))
	{
		convertedGrade = 1;
	}
	else
	{
		convertedGrade = 0;
	}
	return convertedGrade;
}

int getCreditHours()
{
	int creditHours;

	while (true)
	{
		std::cout << "Input credit hours: ";
		std::cin >> creditHours;
		std::cout << "\n";

		if (!std::cin)
		{
			std::cout << "Input has to be a number!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else break;
	}

	return creditHours;
}
