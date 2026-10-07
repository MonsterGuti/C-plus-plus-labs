#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Worker {
private:
    string socialSecurityNumber;
    string name;
    int yearsOfExperience;
    string currentPosition;
    vector<double> salaries;

public:
    Worker() {
        socialSecurityNumber = "000-00-0000";
        name = "Unknown";
        yearsOfExperience = 0;
        currentPosition = "Unemployed";
    }
    Worker(bool promptPosition) : Worker() {
        if (promptPosition) {
            cout << "Enter current position: ";
            getline(cin >> ws , currentPosition);
        }
    }

    string getSocialSecurityNumber() const { return socialSecurityNumber; }
    string getName() const { return name; }
    int getYearsOfExperience() const { return yearsOfExperience; }
    string getCurrentPosition() const { return currentPosition; }
    vector<double> getSalaries() const { return salaries; }

    void setSocialSecurityNumber(const string &ssn) { socialSecurityNumber = ssn; }
    void setName(const string &n) { name = n; }
    void setYearsOfExperience(int years) {
        if (years >= 0) {
            yearsOfExperience = years;
        } else {
            cout << "Error: Invalid years of experience!\n";
        }
    }
    void setCurrentPosition(const string &pos) { currentPosition = pos; }

    void addSalary(double salary) {
        if (salary > 0) {
            salaries.push_back(salary);
        } else {
            cout << "Error: Invalid salary value!\n";
        }
    }

    double calculateSalary() const {
        if (!salaries.empty()) {
            double sum = accumulate(salaries.begin(), salaries.end(), 0.0);
            return sum / salaries.size();
        }
        return 0.0;
    }

    double findMinimumSalary() const {
        if (salaries.empty()) {
            cout << "Warning: No salaries recorded.\n";
            return 0.0;
        }
        return *min_element(salaries.begin(), salaries.end());
    }
};

int main() {
    cout << " Creating Worker (using 2nd Constructor) \n";
    Worker w1(true);

    w1.setName("Martin Gogulanov");
    w1.setSocialSecurityNumber("0345126789");
    w1.setYearsOfExperience(3);

    w1.addSalary(1200.50);
    w1.addSalary(1350.00);
    w1.addSalary(1100.25);
    w1.addSalary(1500.00);

    cout << "\n--- Worker Details ---\n";
    cout << "Name: " << w1.getName() << endl;
    cout << "Social Security Number: " << w1.getSocialSecurityNumber() << endl;
    cout << "Position: " << w1.getCurrentPosition() << endl;
    cout << "Years of Experience: " << w1.getYearsOfExperience() << endl;

    cout << "\n--- Salary Calculations ---\n";
    cout << "Average Salary: " << w1.calculateSalary() << " BGN" << endl;
    cout << "Minimum Salary: " << w1.findMinimumSalary() << " BGN" << endl;

    return 0;
}

