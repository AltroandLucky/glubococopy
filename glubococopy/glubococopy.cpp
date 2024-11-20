#include <iostream>
#include <Windows.h>
using namespace std;

class Student {
    char* name;
    int age;

public:
    // Прототипы
    Student();
    Student(const char*, int);              // Конструктор с 2 параметрами
    Student(const Student&);                // Конструктор копирования
    Student& operator=(const Student&);     // Оператор присваивания
    void Output();
    ~Student();
};

// Конструктор по умолчанию
Student::Student() {
    name = nullptr;
    age = 0;
}

// Конструктор с параметрами
Student::Student(const char* Name, int Age) {
    name = new char[strlen(Name) + 1];
    strcpy_s(name, strlen(Name) + 1, Name);
    age = Age;
}

// Конструктор копирования
Student::Student(const Student& other) {
    name = new char[strlen(other.name) + 1]; // Выделяем память для новой строки
    strcpy_s(name, strlen(other.name) + 1, other.name); // Копируем строку
    age = other.age; // Копируем возраст
    cout << "Copy constructor called\n";
}

// Оператор присваивания
Student& Student::operator=(const Student& other) {
    if (this == &other) return *this; // Защита от самоприсваивания

    // Удаляем существующие данные
    if (name != nullptr) {
        delete[] name;
    }

    // Глубокое копирование
    name = new char[strlen(other.name) + 1];
    strcpy_s(name, strlen(other.name) + 1, other.name);
    age = other.age;

    cout << "Assignment operator called\n";
    return *this;
}

// Метод вывода данных
void Student::Output() {
    cout << "Name: " << name << endl
        << "Age: " << age << endl << endl;
}

// Деструктор
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

    Student obj2 = obj1; // Вызов конструктора копирования
    obj2.Output();

    Student mas[2]{ {"Alena", 20}, {"Maksim", 22} };
    for (int i = 0; i < 2; i++) {
        mas[i].Output();
    }

    // Пример оператора присваивания
    Student obj3;
    obj3 = mas[0]; // Вызов оператора присваивания
    obj3.Output();

    system("pause");
    return 0;
}
