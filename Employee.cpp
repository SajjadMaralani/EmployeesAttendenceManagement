// INCLUDE THE REQUIRED HEADER FILE
#include "Employee.h"

string toUpperCase(string); // TO TRANSFOR FIRST ELEMENT OF STRING TO UPPER CASE

// MEMBER FUNCTIONS OF CLASS EMPLOYEE

void Employee::input()
{
    cout << "\n\n\n\t\t\t\t\t\t\t\tPersonal Information";
    cout << "\n\t\t______________________________________________________________________________________________________________________\n\n";
    cout << "\t\tFirst Name : ";
    cin >> first_name;
    cout << "\n\n\t\tLast Name: ";
    cin >> last_name;
    cout << "\n\n\t\tGender (Male/Female) : ";
    cin >> gender;
    cout << "\n\n\t\tAge : ";
    cin >> age;
    cout << "\n";
    cout << "\t\t\t\t\t\t\t\tContact Information";
    cout << "\n\t\t______________________________________________________________________________________________________________________\n\n";
    cout << "\t\tE-mail Adress : ";
    cin >> email;
    cout << "\n\n\t\tPhone Number : ";
    cin >> phone;
    cout << "\n";
    cout << "\t\t\t\t\t\t\t\tEmployment Information";
    cout << "\n\t\t______________________________________________________________________________________________________________________\n\n";
    cout << "\t\tEmployee Id : ";
    cin >> id;
    cout << "\n\n\t\tDepartment : ";
    cin >> department;
    cout << "\n\n\t\tUsername : ";
    cin >> user_name;
    cout << "\n\n\t\tPassword : ";
    cin >> password;
}

void Employee::output()
{
    cout << "\n\n\n\t\t\t\t\t\t\t\tPersonal Information";
    cout << "\n\t\t_______________________________________________________________________________________________________________________\n\n";
    cout << "\t\tFirst Name : ";
    cout << toUpperCase(first_name);
    cout << "\n\n\t\tLast Name: ";
    cout << toUpperCase(last_name);
    cout << "\n\n\t\tGender : ";
    cout << toUpperCase(gender);
    cout << "\n\n\t\tAge : ";
    cout << age;
    cout << "\n";
    cout << "\t\t\t\t\t\t\t\tContact Information";
    cout << "\n\t\t_______________________________________________________________________________________________________________________\n\n";
    cout << "\t\tE-mail Adress : ";
    cout << email;
    cout << "\n\n\t\tPhone Number : ";
    cout << phone;
    cout << "\n";
    cout << "\t\t\t\t\t\t\t\tEmployment Information";
    cout << "\n\t\t_______________________________________________________________________________________________________________________\n\n";
    cout << "\t\tEmployee Id : ";
    cout << id;
    cout << "\n\n\t\tDepartment : ";
    cout << toUpperCase(department);
    cout << "\n\n\t\tUsername : ";
    cout << user_name;
}

void Employee::output2()
{
    string temp;
    temp = toUpperCase(first_name) + " " + toUpperCase(last_name) + " " + id;
    cout << temp;
}

void Employee::markAttendance()
{
    system("cls");
    cout << "\t\t\t\t\t ------------- Employee Marking Attendance Form ------------- \n\n\n";
    cout << "\nHow many hours are you required to work in the organization you are in ? ";
    cin >> requiredHourWork;
    cout << "\nEnter attendance for each day (1 for present, 0 for absent): \n" << endl;
    for (int i = 0; i < 15; i++)
    {
        cout << "Day " << i + 1 << ": ";
        cin >> presence[i];
        if (presence[i] == false)
        {
            hourWorked[i] = 0;
            enterHours[i] = 0;
            enterMinutes[i] = 0;
            exitHours[i] = 0;
            exitMinutes[i] = 0;
            cout << "Hours worked on day " << i + 1 << " : " << 0 << "\n\n";
        }
        else
        {
            cout << "\nEnter Arrival Time (hours minutes) : ";
            cin >> enterHours[i] >> enterMinutes[i];
            cout << "\nEnter Exit Time (hours minutes) : ";
            cin >> exitHours[i] >> exitMinutes[i];
            cout << "\n";
            int startMinutes = enterHours[i] * 60 + enterMinutes[i];
            int endMinutes = exitHours[i] * 60 + exitMinutes[i];

            int diffMinutes = endMinutes - startMinutes;
            if (diffMinutes < 0) {
                // Handle negative difference by adding 24 hours (1440 minutes)
                diffMinutes += 24 * 60;
            }

            hourWorked[i] = ((diffMinutes / 60) * 60) + (diffMinutes % 60);
        }

    }
    cout << "\n\n\nSuccussfully Marked.";
    cout << "\n\nPress enter for submenu. . . .";
    cin.ignore();
    getchar();
}

void Employee::showAttendance()
{   
    
    if (checkAttendanceOfEmployees())
    {
        system("cls");
        cout << "\nAttendance for " << toUpperCase(first_name) << " " << toUpperCase(last_name) << " : " << endl;
        cout << "\n\n\n\t\t\t\t     Day\tPresence\tEntered Time\tExited Time\t   Hours worked\n\n";
        for (int i = 0; i < 15; i++)
        {
            if (i + 1 < 10)
            {
                if (enterHours[i] == 0)
                {
                    cout << "\t\t\t\t     " << i + 1 << ")\t " << (presence[i] ? "\tPresent" : "\t Absent") << "\t\t   " << enterHours[i] << " : " << enterMinutes[i] << "\t  " << exitHours[i] << " : " << exitMinutes[i] << "\t\t  " << hourWorked[i] / 60 << " Hours " << hourWorked[i] % 60 << " Minuts\n\n";

                }
                else
                {
                    cout << "\t\t\t\t     " << i + 1 << ")\t " << (presence[i] ? "\tPresent" : "\t Absent") << "\t\t   " << enterHours[i] << " : " << enterMinutes[i] << "\t  " << exitHours[i] << " : " << exitMinutes[i] << "\t  " << hourWorked[i] / 60 << " Hours " << hourWorked[i] % 60 << " Minuts\n\n";

                }
            }
            else
            {
                if (enterHours[i] == 0)
                {
                    cout << "\t\t\t\t     " << i + 1 << ")\t " << (presence[i] ? "Present" : "Absent") << "\t\t   " << enterHours[i] << " : " << enterMinutes[i] << "\t  " << exitHours[i] << " : " << exitMinutes[i] << "\t\t  " << hourWorked[i] / 60 << " Hours " << hourWorked[i] % 60 << " Minuts\n\n";

                }
                else
                {
                    cout << "\t\t\t\t     " << i + 1 << ")\t " << (presence[i] ? "Present" : "Absent") << "\t   " << enterHours[i] << " : " << enterMinutes[i] << "\t  " << exitHours[i] << " : " << exitMinutes[i] << "\t  " << hourWorked[i] / 60 << " Hours " << hourWorked[i] % 60 << " Minuts\n\n";

                }
            }
        }
        int totalPresense = 0;
        for (int i = 0; i < 15; i++)
        {
            if (presence[i] == true)
            {
                totalPresense += 1;
            }
        }
        cout << "\n\n\t\t\t\t     " << "You were present for " << totalPresense << " Days .";

        int totalHour = 0;
        for (int i = 0; i < 15; i++)
        {
            totalHour += hourWorked[i];
        }
        
        cout << "\n\n\t\t\t\t     " << "You were apsent for " << 15 - totalPresense << " Days .";

        cout << "\n\n\t\t\t\t     " << "You have worked " << totalHour / 60 << " Hours and " << totalHour % 60 << " Minuts .";
        cout << "\n\n\t\t\t\t     Press enter for submenu. . . .";
        cin.ignore();
        getchar();
    }
    else
    {
        system("cls");
        cout << "The desired Employee has not marked attendance yet. Press enter to go back. . . .";
        cin.ignore();
        getchar();
    }
}

bool Employee::checkAttendanceOfEmployees()
{
    for (int i = 0; i < 15; i++)
    {
        if(presence[i] != 0)
        {
            return true;
        }
    }
    return false;
}

void Employee::showSalary()
{
    system("cls");
    cout << "\nAttendance for " << toUpperCase(first_name) << " " << toUpperCase(last_name) << " : " << endl;
    cout << "\n\n\n\t\t\t\t     Day\tPresence\tEntered Time\tExited Time\t   Hours worked\n\n";
    for (int i = 0; i < 15; i++)
    {
        if (i + 1 < 10)
        {
            if (enterHours[i] == 0)
            {
                cout << "\t\t\t\t     " << i + 1 << ")\t " << (presence[i] ? "\tPresent" : "\t Absent") << "\t\t   " << enterHours[i] << " : " << enterMinutes[i] << "\t  " << exitHours[i] << " : " << exitMinutes[i] << "\t\t  " << hourWorked[i] / 60 << " Hours " << hourWorked[i] % 60 << " Minuts\n\n";

            }
            else
            {
                cout << "\t\t\t\t     " << i + 1 << ")\t " << (presence[i] ? "\tPresent" : "\t Absent") << "\t\t   " << enterHours[i] << " : " << enterMinutes[i] << "\t  " << exitHours[i] << " : " << exitMinutes[i] << "\t  " << hourWorked[i] / 60 << " Hours " << hourWorked[i] % 60 << " Minuts\n\n";

            }
        }
        else
        {
            if (enterHours[i] == 0)
            {
                cout << "\t\t\t\t     " << i + 1 << ")\t " << (presence[i] ? "Present" : "Absent") << "\t\t   " << enterHours[i] << " : " << enterMinutes[i] << "\t  " << exitHours[i] << " : " << exitMinutes[i] << "\t\t  " << hourWorked[i] / 60 << " Hours " << hourWorked[i] % 60 << " Minuts\n\n";

            }
            else
            {
                cout << "\t\t\t\t     " << i + 1 << ")\t " << (presence[i] ? "Present" : "Absent") << "\t   " << enterHours[i] << " : " << enterMinutes[i] << "\t  " << exitHours[i] << " : " << exitMinutes[i] << "\t  " << hourWorked[i] / 60 << " Hours " << hourWorked[i] % 60 << " Minuts\n\n";

            }
        }
    }

    for (int i = 0; i < 15; i++)  // Calculate salary
    {
        if (hourWorked[i] == 0)
        {
            salary[i] = 0;
        }
        else if ((hourWorked[i]/60) == requiredHourWork)
        {
            salary[i] = (hourWorked[i]/60) * 100;  // Assuming hourly rate is 100$
        }
        else if (hourWorked[i] < requiredHourWork)
        {
            salary[i] = ((requiredHourWork - (hourWorked[i] / 60)) *  (- 50)) + ((hourWorked[i] / 60) * 100);  // Assuming hourly rate is -50$
        }
        else
        {
            salary[i] = (((hourWorked[i]/60) - requiredHourWork) * 50) + ( (((hourWorked[i]/60) - ((hourWorked[i]/60) - requiredHourWork))) * 100);
        }
    }

    cout << "\n\nSalary Status of " << toUpperCase(first_name) << " " << toUpperCase(last_name) << " : \n\n\n";
    int total = 0;
    for (int i = 0; i < 15; i++)
    {
        if (i + 1 < 10)
        {
            cout << "\t\t\t\t     " << i + 1 << ")\t " << salary[i] << "$\n\n";
            total += salary[i];
        }
        else
        {
            cout << "\t\t\t\t     " << i + 1 << ") " << salary[i] << "$\n\n";
            total += salary[i];
        }

    }
    cout << "\n\t\t\t\t Total Salary of 15 days of month : " << total << "$";
    cout << "\n\n\t\t\t You were supposed to worked " << requiredHourWork << " hours a day .";
    

    cout << "\n\n\nPress enter to continue. . . .";
    cin.ignore();
    getchar();
}

// FRIEND FUNCTIONS OF CLASS EMPLOYEE

void bubbleSort(vector<Employee>& list)
{
    bool swapped;
    for (int i = 0; i < list.size() - 1; ++i) {
        swapped = false;
        for (int j = 0; j < list.size() - i - 1; ++j)
        {
            if (list[j].first_name > list[j + 1].first_name)
            {
                swap(list[j], list[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void searchId(vector<Employee> list)
{
    system("cls");
    cout << "\t\t\t\t\t ------------- List Of Registered Employees ------------- \n";

    for (int i = 0; i < list.size(); i++)
    {
        cout << "\n\n\t\t\t\t\t\t     " << i + 1 << ") ";
        list[i].output2();
    }

    string tempId;
    cout << "\n\n\n\n\nEnter the id number of the employee : ";
    cin >> tempId;
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].id == tempId)
        {
            system("cls");
            list[i].output();
            cout << "\n\n\n\n\n\t\tPress enter to go back...";
            cin.ignore();
            getchar();
            return;
        }
    }

    cout << "\nAn employee with such id number was not found!!!";
    cout << "\n\nPlease enter again...";
    cin.ignore();
    getchar();
}

void deleteAnEmployee(vector<Employee>& list)
{
    system("cls");
    string ans;
    cout << "\nAre you sure you want to delete an employee (y/n) ? ";
    cin >> ans;

    if (ans == "y" || ans == "Y")
    {
        system("cls");
        cout << "\t\t\t\t\t ------------- List Of Registered Employees ------------- \n";

        for (int i = 0; i < list.size(); i++)
        {
            cout << "\n\n\t\t\t\t\t\t     " << i + 1 << ") ";
            list[i].output2();
        }
        string tempId;
        cout << "\n\n\nEnter the id number of the employee you want to delete : ";
        cin >> tempId;
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].id == tempId)
            {
                list.erase(list.begin() + i);
                cout << "\n\n\nSuccussfully deleted...";
                cout << "\n\n\nPress enter to go back...";
                cin.ignore();
                getchar();
                return;
            }
        }
            cout << "\nAn employee with such id number was not found!!!";
            cout << "\n\nPlease enter again...";
            cin.ignore();
            getchar();
    }
    else if (ans == "n" || ans == "N")
    {
        return;
    }
    else
    {
        cout << "\n\nInvalid answer!!! Please enter again...";
        cin.ignore();
        getchar();
    }
}
