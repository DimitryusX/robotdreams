#include <iostream>
#include <vector>
#include <algorithm>

const int SIZE = 4;
const int ARRAY_SIZE = 3;

struct Student 
{
    std::string name;
    unsigned marks[SIZE];
};

double averageStudentMark(const Student* student)
{
    double sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += student->marks[i];
    }

    return sum / SIZE;
}

bool sortStudentsByAverageMark(const Student* student1, const Student* student2) 
{
    return averageStudentMark(student1) < averageStudentMark(student2);
}

Student* getBestStudent(Student** students, const size_t size)
{
    double bestAverage = 0;
    Student* bestStudent = nullptr;

    for (int i = 0; i < size; i++) {
        double averageMark = averageStudentMark(students[i]);

        if (averageMark > bestAverage) {
            bestAverage = averageMark;
            bestStudent = students[i];
        }
    }

    return bestStudent;
}

int getStudentsCountByMark(Student** students, const size_t size, const double max, const double threshold = 0.75) {

    int count = 0;
    const double border = threshold * max;
    for (int i = 0; i < size; i++) {
        double averageMark = averageStudentMark(students[i]);
        if (averageMark > border) {
            count++;
        }
    }

    return count;
}

int main()
{
    std::cout << "Welcome to homework 15!" << std::endl << std::endl;

    Student student{ "Mark", {9, 6, 8, 10}};
    double averageMarkOfStudent = averageStudentMark(&student);

    std::cout << "Average mark for student " << student.name << " is: " << averageMarkOfStudent << std::endl;
    std::cout << std::endl;

    std::vector<Student*> students = {
        new Student{"Ann", {7, 7, 7, 7}},
        new Student{"Mike", {10, 11, 10, 10}},
        new Student{"Antony", {6, 6, 4, 6}},
        new Student{"Nik", {5, 12, 9, 6}},
        new Student{"Emily", {9, 11, 4, 6}},
    }; 

    std::cout << "Vector before sort:" << std::endl;
    for (int i = 0; i < students.size(); i++) {
        std::cout << "Student name: " << students[i]->name << " has average mark: " << averageStudentMark(students[i]) << std::endl;
    }
    std::cout << std::endl;

    std::sort(students.begin(), students.end(), sortStudentsByAverageMark);

    std::cout << "Vector after sort:" << std::endl;
    for (int i = 0; i < students.size(); i++) {
        std::cout << "Student name: " << students[i]->name << " has average mark: " << averageStudentMark(students[i]) << std::endl;
    }
    std::cout << std::endl;

    Student* bestStudent = getBestStudent(students.data(), students.size());

    const double averageMarkOfBestStudent = averageStudentMark(bestStudent);
    std::cout << "Best student is " << bestStudent->name << " with average mark " << averageMarkOfBestStudent << std::endl;
    std::cout << std::endl;

    int count = getStudentsCountByMark(students.data(), students.size(), averageMarkOfBestStudent);

    std::cout << "We have " << count << " students where average mark more than 75% from " << averageMarkOfBestStudent << std::endl;

    std::cout << "Bye ..." << std::endl;
}