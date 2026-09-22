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