#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;
    int grade;

public:

    Student() : name(""), age(0), grade(0) {}


    Student(const std::string& name, int age, int grade)
        : name(name), age(age), grade(grade) {}


    Student(const Student& other)
        : name(other.name), age(other.age), grade(other.grade) {}


    Student& operator=(const Student& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
            grade = other.grade;
        }
        return *this;
    }


    ~Student() {}


    std::string getName() const { return name; }
    void setName(const std::string& name) { this->name = name; }

    int getAge() const { return age; }
    void setAge(int age) { this->age = age; }

    int getGrade() const { return grade; }
    void setGrade(int grade) { this->grade = grade; }


    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << "Name: " << student.name << "\n"
           << "Age: " << student.age << "\n"
           << "Grade: " << student.grade << "\n";
        return os;
    }


    friend std::istream& operator>>(std::istream& is, Student& student) {
        std::cout << "Enter name: ";
        is >> student.name;
        std::cout << "Enter age: ";
        is >> student.age;
        std::cout << "Enter grade: ";
        is >> student.grade;
        return is;
    }
};

int main() {
    Student student1("John Doe", 20, 90);
    Student student2;

    std::cout << "Enter details for student 2:\n";
    std::cin >> student2;

    std::cout << "\nStudent 1 Details:\n" << student1;
    std::cout << "\nStudent 2 Details:\n" << student2;

    return 0;
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.