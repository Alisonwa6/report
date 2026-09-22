/*#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

struct employee {
    std::string name;
    int employeeID;
    double hourly_rate;
    double weekly_hours;
    double gross_pay;
};

void printEmployees(const std::vector<employee>& employees);
bool readEmployeeData(std::vector<employee>& employees);

int main() {
    std::vector<employee> employees;

    // Read employee data from CSV
    if (!readEmployeeData(employees)) {
        return 1;
    }

    // Table 1 - Original Order
    std::cout << "\nTable 1 (Original Order)\n";
    printEmployees(employees);

    // Table 2 - Random Order
    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(employees.begin(), employees.end(), generator);

    std::cout << "\nTable 2 (Random Order)\n";
    printEmployees(employees);

    // Table 3 - Sort by Gross Pay, Descending
    std::sort(employees.begin(), employees.end(),
        [](const employee& a, const employee& b) {
            return a.gross_pay > b.gross_pay;
        });

    std::cout << "\nTable 3 (Sort By Gross Pay in Descending Order)\n";
    printEmployees(employees);

    return 0;
}

bool readEmployeeData(std::vector<employee>& employees) {
    std::ifstream file("../EmployeeData.csv");

    if (!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return false;
    }

    std::string line;

    // Skip the header row
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);

        employee emp;
        std::string employeeID;
        std::string hourlyRate;
        std::string weeklyHours;

        // Read each CSV field
        std::getline(ss, emp.name, ',');
        std::getline(ss, employeeID, ',');
        std::getline(ss, hourlyRate, ',');
        std::getline(ss, weeklyHours, ',');

        // Convert strings to numbers
        emp.employeeID = std::stoi(employeeID);
        emp.hourly_rate = std::stod(hourlyRate);
        emp.weekly_hours = std::stod(weeklyHours);

        // Calculate gross pay
        emp.gross_pay = emp.hourly_rate * emp.weekly_hours;

        // Add employee to vector
        employees.push_back(emp);
    }

    file.close();

    return true;
}

void printEmployees(const std::vector<employee>& employees) {
    std::cout << std::left
              << std::setw(17) << "NAME"
              << std::setw(15) << "EMPNUMBER"
              << std::setw(15) << "HOURLY RATE"
              << std::setw(15) << "HOURS WORKED"
              << std::setw(15) << "GROSS PAY"
              << std::endl;

    std::cout << "----------------------------------------------------------------------"
              << std::endl;

    for (const employee& emp : employees) {
        std::cout << std::left
                  << std::setw(17) << emp.name
                  << std::setw(15) << emp.employeeID
                  << "$" << std::setw(14) << std::fixed << std::setprecision(2)
                  << emp.hourly_rate
                  << std::setw(15) << emp.weekly_hours
                  << "$" << emp.gross_pay
                  << std::endl;
    }
}*/




#include <format>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

struct Employee {
    std::string name;
    int employeeID;
    double hourly_rate;
    double weekly_hours;
    double gross_pay;
};

double readEmployeeData(Employee &emp);
void parseString(std::string &line, std::string &field);
void printEmpTable(std::vector<Employee> &employees);

int main() {
    std::vector <Employee> employees;
    Employee employee;
    readEmployeeData(employee);
    printEmpTable(employees);
    return 0;
}

double readEmployeeData(Employee &emp) {
    std::ifstream file("../EmployeeData.csv");
    file.open(R"(../EmployeeData.csv)");
    if (!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }
    double grossPay;

    std::cout << "------------------------------------------------------------------\n";

    /*std::string empID = std::to_string(employeeID);
    std::string hr = std::to_string(hourly_rate);
    std::string wh = std::to_string(weekly_hours);*/

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        //std::string nametkn, empID, hr, wh;

        std::cout << std::fixed << std::setprecision(2);

        parseString(line, name);
        parseString(line, empID);
        parseString(line, hr);
        parseString(line, wh);

        gross_pay = stod(hr) * stod(wh);

        //employees.push_back({name, employeeID, hourly_rate, weekly_hours, gross_pay});

        std::cout << std::setw(15) << std::left << name;
        std::cout << std::setw(15) << std::left << empID;
        std::cout << std::setw(15) << std::left << hr;
        std::cout << std::setw(15) << std::left << wh;
        std::cout << std::setw(15) << std::left << gross_pay;
        std::cout << std::endl;
    }
    file.close();
}

void parseString(std::string &line, std::string &field) {
    int location;
    location = line.find(',');
    field = line.substr(0, location);
    line = line.substr(location + 1, line.length());
}