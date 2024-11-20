#include <iostream>
#include <Windows.h>
using namespace std;

class Student {
    char* name;
    int age;

public:
    // ���������
    Student();
    Student(const char*, int);              // ����������� � 2 �����������
    Student(const Student&);                // ����������� �����������
    Student& operator=(const Student&);     // �������� ������������
    void Output();
    ~Student();
};

// ����������� �� ���������
Student::Student() {
    name = nullptr;
    age = 0;
}

// ����������� � �����������
Student::Student(const char* Name, int Age) {
    name = new char[strlen(Name) + 1];
    strcpy_s(name, strlen(Name) + 1, Name);
    age = Age;
}

// ����������� �����������
Student::Student(const Student& other) {
    name = new char[strlen(other.name) + 1]; // �������� ������ ��� ����� ������
    strcpy_s(name, strlen(other.name) + 1, other.name); // �������� ������
    age = other.age; // �������� �������
    cout << "Copy constructor called\n";
}

// �������� ������������
Student& Student::operator=(const Student& other) {
    if (this == &other) return *this; // ������ �� ����������������

    // ������� ������������ ������
    if (name != nullptr) {
        delete[] name;
    }

    // �������� �����������
    name = new char[strlen(other.name) + 1];
    strcpy_s(name, strlen(other.name) + 1, other.name);
    age = other.age;

    cout << "Assignment operator called\n";
    return *this;
}

// ����� ������ ������
void Student::Output() {
    cout << "Name: " << name << endl
        << "Age: " << age << endl << endl;
}

// ����������
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

    Student obj2 = obj1; // ����� ������������ �����������
    obj2.Output();

    Student mas[2]{ {"Alena", 20}, {"Maksim", 22} };
    for (int i = 0; i < 2; i++) {
        mas[i].Output();
    }

    // ������ ��������� ������������
    Student obj3;
    obj3 = mas[0]; // ����� ��������� ������������
    obj3.Output();

    system("pause");
    return 0;
}
