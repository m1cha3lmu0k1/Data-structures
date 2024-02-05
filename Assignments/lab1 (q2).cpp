#include <iostream>
#include <iomanip>

// Define the Course struct
struct Course {
    std::string course_code;
    std::string course_name;
};

// Define the Grade struct
struct Grade {
    int mark;
    char the_grade;
};

// Define the Student struct
struct Student {
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    Grade grades;
};

// Function to add a student
void addStudent(Student students[], int& studentCount) {
    if (studentCount < 40) {
        std::cout << "Enter Registration Number: ";
        std::cin >> students[studentCount].registration_number;

        std::cout << "Enter Name: ";
        std::cin.ignore();
        std::getline(std::cin, students[studentCount].name);

        std::cout << "Enter Age: ";
        std::cin >> students[studentCount].age;

        std::cout << "Enter Course Code: ";
        std::cin >> students[studentCount].course.course_code;

        std::cout << "Enter Course Name: ";
        std::cin.ignore();
        std::getline(std::cin, students[studentCount].course.course_name);

        // Initialize grades to invalid values
        students[studentCount].grades.mark = -1;
        students[studentCount].grades.the_grade = 'X';

        ++studentCount;
        std::cout << "Student added successfully." << std::endl;
    } else {
        std::cout << "Cannot add more students. Limit reached." << std::endl;
    }
}

// Function to edit a student's details
void editStudent(Student students[], int studentCount) {
    std::string regNumber;
    std::cout << "Enter Registration Number to edit: ";
    std::cin >> regNumber;

    for (int i = 0; i < studentCount; ++i) {
        if (students[i].registration_number == regNumber) {
            std::cout << "Enter New Age: ";
            std::cin >> students[i].age;

            std::cout << "Student details updated successfully." << std::endl;
            return;
        }
    }

    std::cout << "Student not found." << std::endl;
}

// Function to add marks and calculate grades
void addMarksAndCalculateGrades(Student students[], int studentCount) {
    std::string regNumber;
    std::cout << "Enter Registration Number to add marks: ";
    std::cin >> regNumber;

    for (int i = 0; i < studentCount; ++i) {
        if (students[i].registration_number == regNumber) {
            std::cout << "Enter Mark: ";
            std::cin >> students[i].grades.mark;

            // Calculate the grade based on the mark
            if (students[i].grades.mark > 69) {
                students[i].grades.the_grade = 'A';
            } else if (students[i].grades.mark > 59) {
                students[i].grades.the_grade = 'B';
            } else if (students[i].grades.mark > 49) {
                students[i].grades.the_grade = 'C';
            } else if (students[i].grades.mark > 39) {
                students[i].grades.the_grade = 'D';
            } else {
                students[i].grades.the_grade = 'E';
            }

            std::cout << "Marks and Grade added successfully." << std::endl;
            return;
        }
    }

    std::cout << "Student not found." << std::endl;
}

// Function to display student details
void displayStudentDetails(const Student& student) {
    std::cout << "Registration Number: " << student.registration_number << std::endl;
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Age: " << student.age << std::endl;
    std::cout << "Course Code: " << student.course.course_code << std::endl;
    std::cout << "Course Name: " << student.course.course_name << std::endl;
    std::cout << "Mark: " << student.grades.mark << std::endl;
    std::cout << "Grade: " << student.grades.the_grade << std::endl;
}

// Function to display all students' details
void displayAllStudents(const Student students[], int studentCount) {
    for (int i = 0; i < studentCount; ++i) {
        std::cout << "\nStudent " << i + 1 << ":\n";
        displayStudentDetails(students[i]);
    }
}

int main() {
    Student students[40];
    int studentCount = 0;
    int choice;

    do {
        std::cout << "\n1. Add Student\n2. Edit Student\n3. Add Marks and Calculate Grades\n4. Display All Students\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                editStudent(students, studentCount);
                break;
            case 3:
                addMarksAndCalculateGrades(students, studentCount);
                break;
            case 4:
                displayAllStudents(students, studentCount);
                break;
            case 5:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

