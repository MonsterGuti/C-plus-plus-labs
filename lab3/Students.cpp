
#include <iostream>
#include <cstring>
using namespace std;

class Student {
public:
    char* name;
    int facultyNumber;
    double grade;

    Student() {
        name = new char[1];
        name[0] = '\0';
        facultyNumber = 0;
        grade = 0;
    }

    Student(const char* n, int fn, double g) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        facultyNumber = fn;
        grade = g;
    }

    Student(const Student& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        facultyNumber = other.facultyNumber;
        grade = other.grade;
    }

    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] name;

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);

            facultyNumber = other.facultyNumber;
            grade = other.grade;
        }

        return *this;
    }

    //
    ~Student() {
        delete[] name;
    }
};


class StudentList {
private:
    Student* students;
    int capacity;
    int count;

public:
    StudentList(int initialCapacity) {
        capacity = initialCapacity;
        count = 0;
        students = new Student[capacity];
    }

    ~StudentList() {
        delete[] students;
    }

    void add(const Student& s) {
        if (count == capacity) {
            cout << "List is full!" << endl;
            return;
        }

        students[count] = s;
        count++;
    }

    // Намиране на студента с най-висока оценка
    Student& getBest() {
        if (count == 0) {
            throw "List is empty!";
        }

        int best = 0;

        for (int i = 1; i < count; i++) {
            if (students[i].grade >= students[best].grade) {
                best = i;
            }
        }

        return students[best];
    }

    const Student& getByIndex(int i) const {
        if (i < 0 || i >= count) {
            throw "Invalid index!";
        }

        return students[i];
    }

    void swapStudents(int i, int j) {
        if (i < 0 || i >= count || j < 0 || j >= count) {
            throw "Invalid index!";
        }

        Student& s1 = students[i];
        Student& s2 = students[j];

        Student temp = s1;
        s1 = s2;
        s2 = temp;
    }

    void print() const {
        for (int i = 0; i < count; i++) {
            cout << students[i].name << " "
                 << students[i].facultyNumber << " "
                 << students[i].grade << endl;
        }
    }
};


int main() {

    StudentList list(5);

    Student s1("Ivan", 1001, 4.50);
    Student s2("Maria", 1002, 5.50);
    Student s3("Georgi", 1003, 4.00);
    Student s4("Elena", 1004, 5.00);
    Student s5("Petar", 1005, 5.80);

    list.add(s1);
    list.add(s2);
    list.add(s3);
    list.add(s4);
    list.add(s5);

    cout << "Students:" << endl;
    list.print();

    Student& best = list.getBest();

    cout << "\nBest student: " << best.name << endl;
    cout << "Grade: " << best.grade << endl;

    if (best.grade + 0.5 <= 6) {
        best.grade += 0.5;
    }

    cout << "\nAfter increasing the grade:" << endl;
    list.print();

    return 0;
}
