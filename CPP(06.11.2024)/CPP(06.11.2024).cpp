#include <iostream>
#include <Windows.h>
using namespace std;

class Student
{
    char* name;
    int age;

public:
    Student();                              
    Student(const char* Name, int Age);     
    Student(const Student& other);         
    Student& operator=(const Student& other); 
    void Output();
    ~Student();                            
};
Student::Student() : name(nullptr), age(0) {}
Student::Student(const char* Name, int Age) {
    name = new char[strlen(Name) + 1];
    strcpy_s(name, strlen(Name) + 1, Name);
    age = Age;
}

Student::Student(const Student& other) {
    age = other.age;
    if (other.name != nullptr) {
        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name) + 1, other.name);
    }
    else {
        name = nullptr;
    }
}

Student& Student::operator=(const Student& other) {
    if (this == &other) {
        return *this; 
    }
    delete[] name; 

    age = other.age;
    if (other.name != nullptr) {
        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name) + 1, other.name);
    }
    else {
        name = nullptr;
    }
    return *this;
}

void Student::Output() {
    cout << "Name: " << (name ? name : "N/A") << endl
        << "Age: " << age << endl << endl;
}

Student::~Student() {
    if (name != nullptr) {
        delete[] name;
    }
    cout << "Destruct\n";
    Sleep(1000);
}

int main() {
    Student obj1("Oleg", 21);
    obj1.Output();

    Student mas[2]{ {"Alena", 20}, {"Maksim", 22} };
    for (int i = 0; i < 2; i++) {
        mas[i].Output();
    }

    Student obj2 = obj1;
    obj2.Output();

    Student obj3("Ivan", 23);
    obj3 = obj1; 
    obj3.Output();
}
