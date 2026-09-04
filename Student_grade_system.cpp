#include <iostream>
#include <string>
#include <vector>
class Student {
private:
    std::string name;
    int studentId;
    std::vector<double> grades;
    
public:
    // Constructor
    Student(std::string studentName, int id) : name(studentName), studentId(id) {
        std::cout << "Student " << name << " enrolled with ID: " << studentId << std::endl;
    }
    
    // Add a grade
    void addGrade(double grade) {
        if (grade >= 0.0 && grade <= 100.0) {
            grades.push_back(grade);
            std::cout << "Grade " << grade << " added for " << name << std::endl;
        } else {
            std::cout << "Invalid grade. Must be between 0 and 100." << std::endl;
        }
    }
    
    // Calculate average grade
    double calculateAverage() const {
        if (grades.empty()) return 0.0;
        
        double sum = 0.0;
        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }
    
    // Display student information
    void displayStudent() const {
        std::cout << "Student: " << name << " (ID: " << studentId << ")" << std::endl;
        std::cout << "Number of grades: " << grades.size() << std::endl;
        std::cout << "Average grade: " << calculateAverage() << std::endl;
    }
};
// Complete this implementation
int main() {
    // Your code here: Create student objects and demonstrate functionality
    Student student1("Mustafa Alasady",1234);
    student1.addGrade(97);
    student1.addGrade(98);
    student1.addGrade(96);
    student1.addGrade(97);

    //calculate the avrage of the grades
    double average = student1.calculateAverage();
    std::cout << "\nDirectly fetched average: " << average << std::endl;

    //Display student information
    student1.displayStudent();
    
    return 0;
}