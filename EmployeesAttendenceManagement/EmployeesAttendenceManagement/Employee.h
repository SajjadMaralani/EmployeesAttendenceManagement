#pragma once

// INCLUDE THE REQUIRED LIBRARY FILES
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Employee
{
    // FRIEND FUNCTIONS
    friend void bubbleSort(vector<Employee>&); // TO SORT THE LIST OF EMPLOYEES ALPHABETICALLY
    friend void searchId(vector<Employee>); // TO SEARCH AN EMPLOYEE BY ITS ID NUMBER
    friend void deleteAnEmployee(vector<Employee>&); // TO DELETE AN EMPLOYEE BY ITS ID NUMBER
    friend void employeeLogin(vector<Employee>&); // TO LOGIN EMPLOYEE
    friend void employeeView(Employee&); // DISPLAY FOR EMPLOYEES

private:

    // DATA MEMBERS

    // Personal info
    string first_name;
    string last_name;
    string gender;
    string age;

    // Contact info
    string email;
    string phone;

    // Employemnt info
    string id;
    string department;
    string user_name;
    string password;

    // Attendance info
    bool presence[15];
    int hourWorked[15];
    int enterHours[15];
    int enterMinutes[15];
    int exitHours[15];
    int exitMinutes[15];
    int salary[15];
    int requiredHourWork;

public:

    // MEBMER FUNCTIONS
    void input(); // TO RECEIVE INFORMATION
    void output(); // TO DISPLAY INFORMATION
    void output2();
    void markAttendance(); // TO INDICATE THE PRESENCE OF AN EMPLOYEE
    void showAttendance(); // TO DISPLAY THE ATTENDANCE STATUS OF AN EMPLOYEE
    bool checkAttendanceOfEmployees(); // TO CHECK EMPLOYEE HAS MARKED ATTENDANCE OR NOT
    void showSalary(); // TO SHOW THE SALARY OF AN EMPLOYEE
};

