#include <iostream>
#include <limits>

class Course {
public:
    std::string course_code;
    std::string course_name;
};

class Grade {
public:
    int mark;
    char the_grade;

    void calculateGrade() {
        if (mark > 69) {
            the_grade = 'A';
        } else if (mark > 59) {
            the_grade = 'B';
        } else if (mark > 49) {
            the_grade = 'C';
        } else if (mark > 39) {
            the_grade = 'D';
        } else {
            the_grade = 'E';
        }
    }
};

class Student {
public:
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    Grade grades;

    // Function to add a student
    void addStudent() {
        std::cout << "Enter Registration Number: ";
        std::cin >> registration_number;

        std::cout << "Enter Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Enter Age: ";
        std::cin >> age;

        std::cout << "Enter Course Code: ";
        std::cin >> course.course_code;

        std::cout << "Enter Course Name: ";
        std::cin.ignore();
        std::getline(std::cin, course.course_name);

        // Initialize grades to invalid values
        grades.mark = -1;
        grades.the_grade = 'X';
    }

    // Function to edit a student's details
    void editStudent() {
        std::cout << "Enter New Age: ";
        std::cin >> age;

        std::cout << "Student details updated successfully." << std::endl;
    }

    // Function to add marks and calculate grades
    void addMarksAndCalculateGrades() {
        std::cout << "Enter Mark: ";
        std::cin >> grades.mark;

        grades.calculateGrade();

        std::cout << "Marks and Grade added successfully." << std::endl;
    }

    // Function to display student details
    void displayStudentDetails() const {
        std::cout << "Registration Number: " << registration_number << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Course Code: " << course.course_code << std::endl;
        std::cout << "Course Name: " << course.course_name << std::endl;
        std::cout << "Mark: " << grades.mark << std::endl;
        std::cout << "Grade: " << grades.the_grade << std::endl;
    }
};

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
                if (studentCount < 40) {
                    students[studentCount].addStudent();
                    ++studentCount;
                    std::cout << "Student added successfully." << std::endl;
                } else {
                    std::cout << "Cannot add more students. Limit reached." << std::endl;
                }
                break;
            case 2:
                std::cout << "Enter Registration Number to edit: ";
                std::cin >> students[studentCount].registration_number;
                students[studentCount].editStudent();
                break;
            case 3:
                std::cout << "Enter Registration Number to add marks: ";
                std::cin >> students[studentCount].registration_number;
                students[studentCount].addMarksAndCalculateGrades();
                break;
            case 4:
                for (int i = 0; i < studentCount; ++i) {
                    std::cout << "\nStudent " << i + 1 << ":\n";
                    students[i].displayStudentDetails();
                }
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
