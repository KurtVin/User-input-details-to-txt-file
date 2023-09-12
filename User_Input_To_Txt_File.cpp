#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main ()
{
    ofstream out;
    string file = "User_Details.txt";

    out.open (file, ios::app);

    if (!out.is_open())
    {
        cerr << "Error opening the file " << file << endl;
        return 1;
    }

    string name, sex, address, course, school;
    int age;

    time_t currentTime = time(nullptr);

    // Convert the current time to a local time struct
    tm* localTime = localtime(&currentTime);

    // Define an array to store the complete month names
    const char* mnths[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Format and display the date and time in 12-hour format with complete month name
    string t = to_string (localTime -> tm_hour % 12) + ":" +
                                to_string (localTime -> tm_min) + ":" +
                                to_string (localTime -> tm_sec) + " " +
                                (localTime -> tm_hour >= 12 ? "PM" : "AM") + ", " +
                                mnths [localTime -> tm_mon] + " " +
                                to_string (localTime -> tm_mday) + ", " +
                                to_string (localTime -> tm_year + 1900);

    cout << "Enter your full name: ";
    getline (cin, name);
    cout << endl;

    cout << "Enter your gender: ";
    getline (cin, sex);
    cout << endl;

    cout << "Name of school: ";
    getline (cin, school);
    cout << endl;

    cout << "Enter your course: ";
    getline (cin, course);
    cout << endl;

    cout << "Enter your complete address: ";
    getline (cin, address);
    cout << endl;

    cout << "Enter your age: ";
    cin >> age;
    cout << endl;

    cout << endl << endl;

    cout << "Student Information" << endl;
    cout << "-----------------------------------" << endl << endl;
    cout << "Name of student: " << name << endl;
    cout << "Age of student: " << age << endl;
    cout << "Gender of student: " << sex << endl;
    cout << "Name of school: " << school << endl;
    cout << "Course of student: " << course << endl;
    cout << "Address of student: " << address << endl << endl;

    cout << "Current date and time when printed: " << t << endl;

    out << "Name of student: " << name << endl;
    out << "Age of student: " << age << endl;
    out << "Gender of student: " << sex << endl;
    out << "Name of school: " << school << endl;
    out << "Course of student: " << course << endl;
    out << "Address of student: " << address << endl << endl;

    out << "Current date and time when printed: " << t << endl;
    out << "===================================================" << endl << endl;

    out.close ();

    // copy the path where the project folder located and.
    // change the |C:Users\cacao\Desktop\C++| with your own path!
    cout << "Data has been stored in: C:Users|cacao|Desktop|C++ " << file << endl << endl << endl;
    
    return 0;

}