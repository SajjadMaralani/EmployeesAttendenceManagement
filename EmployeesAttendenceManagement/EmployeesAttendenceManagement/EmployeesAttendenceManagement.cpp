//  C++ Program on Attendance Management of Employees


// INCLUDE THE REQUIRED LIBRARY FILES
#include <iostream>
#include <string>
#include <vector>
// INCLUDE THE REQUIRED HEADER FILES
#include "Employee.h"

using namespace std;

// USER DEFINED FUNCTIONS
void date(); // TO GIVE THE DATE
void title(); // TO GIVE THE TITLE
int  delay(); // TO DELAY THE DISPLAY
void delay(unsigned int);
void adminLogin(vector<Employee>&); // LOGIN FUNCTION FOR MANAGERS
void adminView(vector<Employee>&); // DISPLAY FOR MANAGERS
int  adminMenu(); // DISPLAY THE MENU
void registerEmployee(vector<Employee>&); // TO REGISTER EMPLOYEES
string toUpperCase(string); // TO TRANSFOR FIRST ELEMENT OF STRING TO UPPER CASE
void listOfEmployeesRegistered(vector<Employee>); // TO DISPLAY LIST OF EMPLOYEES
void moreDetails(vector<Employee>); // DISPLAY MORE INFO OF AN SPECIFIC EMPLOYEE
void attendanceView(vector<Employee>&); // DISPLAY ATTENDANCE VIEW OF ADMINVIEW
void deleteView(vector<Employee>&); // DISPLAY DELETE VIEW OF ADMINVIEW
void deleteAllEmployees(vector<Employee>&); // DELETE ALL REGISTERED EMPLOYEES
int  employeeMenu(); // DISPLAY THE MENU
void salaryView(vector<Employee>); // DISPLAY SALARY VIEW OF ADMINVIEW

void date()
{
    time_t T = time(NULL);
    struct tm tm = *localtime(&T);
    cout << "\n\n\n";
    printf("\t\t\t\t\t\t\t      Date:%02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void title()
{
    cout << "\n";
    cout << "\t\t\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t\t    ------------------------------------\n";
    cout << "\t\t\t\t\t\t    |Attendance Management Of Employees|\n";
    cout << "\t\t\t\t\t\t    ------------------------------------\n";
    cout << "\n\n";
    cout << "\t\t\t\t\t\t";
}

int delay()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "\nSaving Records ...\n";
        for (int ii = 0; ii < 20000; ii++)
        {
            for (int iii = 0; iii < 20000; iii++)
            {
            }
        }
    }

    cout << "\nExiting Now ...";
    for (int i = 0; i < 3; i++)
    {
        for (int ii = 0; ii < 20000; ii++)
        {
            for (int iii = 0; iii < 20000; iii++)
            {
            }
        }
    }
    return 0;
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void adminLogin(vector<Employee>& list)
{
    system("cls");
    date();
    title();
    cout << "\n --------- Admin Login --------- \n\n";

    string username;
    string password;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "\nEnter password: ";
    cin >> password;

    if (username == "admin" && password == "admin1234")
    {
        adminView(list);
        getchar();
        delay();
    }
    else
    {
        cout << "\n\nError! Invalid Credentials.";
        cout << "\n\nPress enter for main menu. . . .";
        getchar();
        getchar();
    }
    return;
}

void adminView(vector<Employee>& list)
{
    while (1)
    {
        switch (adminMenu())
        {
        case 1:
            registerEmployee(list);
            break;
        case 2:
            listOfEmployeesRegistered(list);
            break;
        case 3:
            attendanceView(list);
            break;
        case 4:
            salaryView(list);
            break;
        case 5:
            deleteView(list);
            break;
        case 0:
            while (1)
            {
                system("cls");
                string back;
                cout << "Are you sure you want to go back ? (y/n) ";
                cin >> back;
                if (back == "y" || back == "Y")
                {
                    return;
                }
                else if (back == "n" || back == "N")
                {
                    break;
                }
                else
                {
                    cout << "\nInvalid choice!!! Please enter again...";
                    cin.ignore();
                    getchar();
                }
            }
            break;
        default:
            cout << "\nInvalid choice!!! Please enter again...";
            cin.ignore();
            getchar();
        }
    }
}

int adminMenu()
{
    int choice;
    system("cls");
    date();
    title();
    cout << "\nPlease choose an option ...";
    cout << "\n----------------------------\n";
    cout << "\n1. Register Employee";
    cout << "\n2. List Of Registered Employees";
    cout << "\n3. Check Employees Attendance";
    cout << "\n4. Salary Status";
    cout << "\n5. Delete Employee";
    cout << "\n0. Go Back <- \n\n\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void registerEmployee(vector<Employee>& list)
{
    system("cls");

    vector<Employee> list_temp;
    int n;
    cout << "How many employees you want to register (Digits only) ?  ";
    cin >> n;
    system("cls");
    list_temp.resize(n);
    cout << "\t\t\t\t\t\t    ------ New Employee Registration Form ------ \n";
    cout << "\t\t\t\t\t   Please fill out the form to complete your registration. Thank you!";

    for (int i = 0; i < n; i++)
    {
        cout << "\n\n\n\t\t\t\t\t\t\t   ***** Employee number " << i + 1 << " *****" << endl;
        list_temp[i].input();
    }

    for (int i = 0; i < n; i++)    // Append the elements of list_temp to list
    {
        list.insert(list.end(), list_temp[i]);
    }

    bubbleSort(list);  // TO SORT THE LIST OF EMPLOYEES ALPHABETICALLY

    cout << "\n\n\n\t\tSuccussfully registered.";
    cout << "\n\n\t\tPress enter for main menu. . . .";
    cin.ignore();
    getchar();
}

string toUpperCase(string word)
{
    word[0] = toupper(word[0]);
    return word;
}

void listOfEmployeesRegistered(vector<Employee> list)
{
    system("cls");
    if (list.empty())
    {
        cout << "The list is empty. No employees have been registered yet.\n";
        cout << "\n\nPress enter for main menu. . . .";
        cin.ignore();
        getchar();
    }

    else
    {
        while (1)
        {
            system("cls");
            cout << "\t\t\t\t\t ------------- List Of Registered Employees ------------- \n";

            for (int i = 0; i < list.size(); i++)
            {
                cout << "\n\n\t\t\t\t\t\t     " << i + 1 << ") ";
                list[i].output2();
            }

            int choice;
            cout << "\n\n\n\n\n\nPlease choose an option ...";
            cout << "\n----------------------------\n";
            cout << "\n";
            cout << "1. More Details On A Specific Employee\n";
            cout << "2. Search An Employee By Its Id Number\n";
            cout << "0. Go Back <- \n";
            cout << "\n\nEnter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                moreDetails(list);
                break;
            case 2:
                searchId(list);
                break;
            case 0:
                return;
            default:
                cout << "\nInvalid choice!!! Please enter again...";
                cin.ignore();
                getchar();
            }
        }
    }
}

void moreDetails(vector<Employee> list)
{
    system("cls");
    cout << "\t\t\t\t\t ------------- List Of Registered Employees ------------- \n";

    for (int i = 0; i < list.size(); i++)
    {
        cout << "\n\n\t\t\t\t\t\t     " << i + 1 << ") ";
        list[i].output2();
    }

    int index;
    cout << "\n\n\n\n\nChoose the employee you want by entering its positional number : ";
    cin >> index;
    if (index > list.size() || index <= 0)
    {
        cout << "\nInvalid positional number!!! Please enter again...";
        cin.ignore();
        getchar();
        return;
    }
    else
    {
        system("cls");
        list[index - 1].output();
        cout << "\n\n\n\n\n\t\tPress enter to go back...";
        cin.ignore();
        getchar();
        return;
    }
}

void attendanceView(vector<Employee>& list)
{
    system("cls");
    if (list.empty())
    {
        cout << "The list is empty. No employees have been registered yet.\n";
        cout << "\n\nPress enter for main menu. . . .";
        cin.ignore();
        getchar();
    }
    else
    {
        while (1)
        {
            system("cls");
            cout << "\t\t\t\t\t ------------- List Of Registered Employees ------------- \n";

            for (int i = 0; i < list.size(); i++)
            {
                cout << "\n\n\t\t\t\t\t\t     " << i + 1 << ") ";
                list[i].output2();
            }

            int choice;
            cout << "\n\n\n\n\n\nPlease choose an option ...";
            cout << "\n----------------------------\n";
            cout << "\n";
            cout << "1. Mark Attendance\n";
            cout << "2. Attendance Status\n";
            cout << "0. Go Back <- \n";
            cout << "\n\nEnter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                system("cls");
                cout << "\t\t\t\t\t ------------- List Of Registered Employees ------------- \n";

                for (int i = 0; i < list.size(); i++)
                {
                    cout << "\n\n\t\t\t\t\t\t     " << i + 1 << ") ";
                    list[i].output2();
                }

                int index;
                cout << "\n\n\n\n\nChoose the employee you want by entering its positional number : ";
                cin >> index;
                if (index > list.size() || index <= 0)
                {
                    cout << "\nInvalid positional number!!! Please enter again...";
                    cin.ignore();
                    getchar();
                }
                else
                {
                    if (list[index - 1].checkAttendanceOfEmployees())
                    {
                        string choice;
                        cout << "\n\n\nDo you want to mark a new attedance form (y/n) ? ";
                        cin >> choice;
                        if (choice == "y" || choice == "Y")
                        {
                            list[index - 1].markAttendance();
                            break;
                        }
                        else if (choice == "n" || choice == "N")
                        {
                            break;
                        }
                        else
                        {
                            cout << "\nInvalid Choice!!! Please enter again...";
                            cin.ignore();
                            getchar();
                        }
                    }
                    else
                    {
                        list[index - 1].markAttendance();
                    }
                    break;
                }
                break;
            case 2:
                system("cls");
                cout << "\t\t\t\t\t ------------- List Of Registered Employees ------------- \n";

                for (int i = 0; i < list.size(); i++)
                {
                    cout << "\n\n\t\t\t\t\t\t     " << i + 1 << ") ";
                    list[i].output2();
                }

                int index2;
                cout << "\n\n\n\n\nChoose the employee you want by entering its positional number : ";
                cin >> index2;
                if (index2 > list.size() || index2 <= 0)
                {
                    cout << "\nInvalid positional number!!! Please enter again...";
                    cin.ignore();
                    getchar();
                }
                else
                {
                    list[index2 - 1].showAttendance();
                    break;
                }
                break;
            case 0:
                return;
            default:
                cout << "\nInvalid choice!!! Please enter again...";
                cin.ignore();
                getchar();
            }
        }
    }
}

void deleteView(vector<Employee>& list)
{
    system("cls");
    if (list.empty())
    {
        cout << "The list is empty. No employees have been registered yet or you just deleted all employees.\n";
        cout << "\n\nPress enter for main menu. . . .";
        cin.ignore();
        getchar();
    }
    else
    {
        while (1)
        {
            system("cls");
            cout << "\t\t\t\t\t ------------- List Of Registered Employees ------------- \n";

            for (int i = 0; i < list.size(); i++)
            {
                cout << "\n\n\t\t\t\t\t\t     " << i + 1 << ") ";
                list[i].output2();
            }

            int choice;
            cout << "\n\n\n\n\n\nPlease choose an option ...";
            cout << "\n----------------------------\n";
            cout << "\n";
            cout << "1. Delete An Employee\n";
            cout << "2. Delete All Registered Employees\n";
            cout << "0. Go Back <- \n";
            cout << "\n\nEnter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                deleteAnEmployee(list);
                deleteView(list);
                return;
            }
            case 2:
            {
                deleteAllEmployees(list);
                deleteView(list);
                return;
            }
            case 0:
                return;
            default:
                cout << "\nInvalid choice!!! Please enter again...";
                cin.ignore();
                getchar();
            }
        }
    }
}

void deleteAllEmployees(vector<Employee>& list)
{
    system("cls");
    string choice;
    cout << "\nAre you sure you want to delete all registered employees (y/n) ? ";
    cin >> choice;
    if (choice == "y" || choice == "Y")
    {
        list.clear();
        cout << "\n\nDeleting all registered employees";
        for (int process = 0; process < 20; process++)
        {
            delay(150);
            cout << ".";
        }

        cout << "\n\n\nSuccussfully deleted.";
        cout << "\n\nPress enter to go back. . . .";
        cin.ignore();
        getchar();
        return;
    }
    else if (choice == "n" || choice == "N")
    {
        return;
    }
    else
    {
        cout << "\nInvalid Choice!!! Please enter again...";
        cin.ignore();
        getchar();
    }
}

void employeeLogin(vector<Employee>& list)
{
    system("cls");
    date();
    title();
    cout << "\n --------- Employee Login --------- \n\n";

    string username;
    string password;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "\nEnter password: ";
    cin >> password;

    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].user_name == username && list[i].password == password)
        {
            employeeView(list[i]);
            getchar();
            delay();
            return;
        }
    }

    cout << "\n\nError! Invalid Credentials.";
    cout << "\n\nPress enter for main menu. . . .";
    getchar();
    getchar();

    return;
}

void employeeView(Employee& person)
{
    while (1)
    {
        switch (employeeMenu())
        {
        case 1:
            system("cls");
            person.output();
            cout << "\n\n\n\t\tPress enter for menu. . . .";
            cin.ignore();
            getchar();
            break;
        case 2:
            person.showAttendance();
            break;
        case 0:
            while (1)
            {
                system("cls");
                string back;
                cout << "Are you sure you want to go back ? (y/n) ";
                cin >> back;
                if (back == "y" || back == "Y")
                {
                    return;
                }
                else if (back == "n" || back == "N")
                {
                    break;
                }
                else
                {
                    cout << "\nInvalid choice!!! Please enter again...";
                    cin.ignore();
                    getchar();
                }
            }
            break;
        default:
            cout << "\nInvalid choice!!! Please enter again...";
            cin.ignore();
            getchar();
        }
    }
}

int employeeMenu()
{
    int choice;
    system("cls");
    cout << "\nPlease choose an option ...";
    cout << "\n----------------------------\n";
    cout << "\n1. Check Your Info";
    cout << "\n2. Check Your Attendance Status";
    cout << "\n0. Go Back <- ";
    cout << "\n\n\nEnter your choice: ";
    cin >> choice;
    return choice;
}

void salaryView(vector<Employee> list)
{
    system("cls");
    if (list.empty())
    {
        cout << "The list is empty. No employees have been registered yet.\n";
        cout << "\n\nPress enter for main menu. . . .";
        cin.ignore();
        getchar();
    }
    else
    {
        while (1)
        {
            system("cls");
            cout << "\t\t\t\t\t ------------- List Of Registered Employees ------------- \n";

            for (int i = 0; i < list.size(); i++)
            {
                cout << "\n\n\t\t\t\t\t\t     " << i + 1 << ") ";
                list[i].output2();
            }

            int choice;
            cout << "\n\n\n\n\n\nPlease choose an option ...";
            cout << "\n----------------------------\n";
            cout << "\n";
            cout << "1. Salary Status\n";
            cout << "0. Go Back <- \n";
            cout << "\n\nEnter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                system("cls");
                cout << "\t\t\t\t\t ------------- List Of Registered Employees ------------- \n";

                for (int i = 0; i < list.size(); i++)
                {
                    cout << "\n\n\t\t\t\t\t\t     " << i + 1 << ") ";
                    list[i].output2();
                }

                int index;
                cout << "\n\n\n\n\nChoose the employee you want by entering its positional number : ";
                cin >> index;
                if (index > list.size() || index <= 0)
                {
                    cout << "\nInvalid positional number!!! Please enter again...";
                    cin.ignore();
                    getchar();
                }
                else
                {
                    if (list[index - 1].checkAttendanceOfEmployees())
                    {
                        list[index - 1].showSalary();
                    }
                    else
                    {
                        system("cls");
                        cout << "The desired Employee has not marked attendance yet. Press enter to go back. . . .";
                        cin.ignore();
                        getchar();
                    }
                    break;
                }
                break;
            case 0:
                return;
            default:
                cout << "\nInvalid choice!!! Please enter again...";
                cin.ignore();
                getchar();
            }
        }
    }
}

// Main part of the program
int main()
{
    system("cls");
    date();
    title();
    cout << "Prepared By    :    Sajjad Maralani";
    cout << "\n\n\t\t\t\t\t\tUniversity Project :   Employees Attendence Management System";
    cout << "\n\n\t\t\t\t\t\tPress Enter to continue......";
    getchar();
    cout << "\n\n\t\t\t\t\t\tLoading";
    
    for (int process = 0; process < 25; process++)
    {
        delay(150);
        cout << ".";
    }
    
    vector<Employee> list; // create an empty vector of type Employee

    while (1)
    {
        system("cls");
        date();
        title();
        cout << "\n";
        cout << "1. Employee Login\n";
        cout << "2. Admin Login\n";
        cout << "0. Exit\n";

        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            employeeLogin(list);
            break;
        }
        case 2:
            adminLogin(list);
            break;
        case 0:
            while (1)
            {
                system("cls");
                cout << "\nAre you sure you want to exit? (y/n) ";
                string ex;
                cin >> ex;

                if (ex == "y" || ex == "Y")
                {
                    cout << "\n\nExiting program";
                    for (int process = 0; process < 20; process++)
                    {
                        delay(150);
                        cout << ".";
                    }
                    system("cls");
                    exit(0);
                }
                else if (ex == "n" || ex == "N")
                {
                    break;
                }
                else
                {
                    cout << "\nInvalid Choice!!! Please enter again...";
                    cin.ignore();
                    getchar();
                }
            }
            break;
        default:
            cout << "\nInvalid Choice!!! Please enter again...";
            cin.ignore();
            getchar();
        }
    }
}