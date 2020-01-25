#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

class Student
{
public:
	std::string name;
	double averageScore = 0.0;
	std::vector<double> scores;

	double getAverageScore()
	{
		averageScore = 0.0;
		for (size_t i = 0; i < scores.size(); i++)
		{
			averageScore += scores[i];
		}
		if (scores.size() > 0)
		{
			return averageScore = averageScore / (double)scores.size();
		}
		else
		{
			return averageScore;
		}

	}

	Student(std::string name, double score) :
		name(name)
	{
		scores.push_back(score);
	}

};

bool compareStudentsByName(Student const &one, Student const &two)
{
	return (one.name < two.name);
}

bool compareStudemtsByScore(Student const &one, Student const &two)
{
	return (one.averageScore > two.averageScore);
}

int main()
{
	/*size_t numberStudents = 0;
	std::cin >> numberStudents;

	std::map<std::string, std::vector<double>> students;
	//Student student;

	for (size_t i = 0; i < numberStudents; i++)
	{
	std::string firstName;
	std::string lastName;
	std::string name;
	double score = 0;

	std::cin >> firstName >> lastName >> score;
	name = firstName + " " + lastName;
	students[name].push_back(score);
	}

	for (auto &i : students)
	{
	double averageScore = 0.0;
	//std::cout << i.first << " ";
	for (auto &a : i.second)
	{
	averageScore += a;
	}
	averageScore = averageScore / i.second.size();
	i.second.clear();
	i.second.push_back(averageScore);
	}


	for (auto i : students)
	{
	std::cout << i.first << " ";
	for (auto a : i.second)
	{
	std::cout << a;
	}
	std::cout << std::endl;
	}*/

	size_t numberStudents = 0;
	std::cin >> numberStudents;

	std::vector<Student> students;

	for (size_t i = 0; i < numberStudents; i++)
	{
		std::string firstName;
		std::string lastName;
		std::string name;
		double score = 0.0;
		bool findName = false;
		size_t studentIndex = 0;

		std::cin >> firstName >> lastName >> score;
		name = firstName + " " + lastName;

		for (size_t i = 0; i < students.size(); i++)
		{
			if (students[i].name == name)
			{
				findName = true;
				studentIndex = i;
			}
		}
		if (findName == false)
		{
			students.push_back(Student(name, score));
		}
		else
		{
			students[studentIndex].scores.push_back(score);
		}

	}

	for (size_t i = 0; i < students.size(); i++)
	{
		students[i].getAverageScore();
	}

	std::sort(students.begin(), students.end(), compareStudemtsByScore);
	for (size_t i = 0; i < students.size(); i++)
	{
		std::cout << students[i].name << " " << students[i].averageScore << std::endl;
	}

	std::cout << std::endl;

	std::sort(students.begin(), students.end(), compareStudentsByName);
	for (size_t i = 0; i < students.size(); i++)
	{
		std::cout << students[i].name << " " << students[i].averageScore << std::endl;
	}

	int a;
	std::cin >> a;
	return 0;
}
