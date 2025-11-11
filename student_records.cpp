#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

// ---- Enum for grade levels
enum GradeLevel { FRESHMAN = 1, SOPHOMORE, JUNIOR, SENIOR };

// ---- using/typedef to simplify a type
using GPA = double;

// ---- Custom namespace for helpers
namespace StudentUtils {

    // Convert name to uppercase (in-place)
    void formatName(string &name) {
        for (char &c : name) {
            c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
        }
    }

    // Map enum -> readable label
    string gradeToString(GradeLevel g) {
        switch (g) {
            case FRESHMAN:  return "Freshman";
            case SOPHOMORE: return "Sophomore";
            case JUNIOR:    return "Junior";
            case SENIOR:    return "Senior";
            default:        return "Unknown";
        }
    }

    // Format GPA to two decimals and return as string (string manipulation)
    string formatGPA(GPA gpa) {
        ostringstream oss;
        oss << fixed << setprecision(2) << gpa;
        return oss.str();
    }

    // Display nicely
    void displayStudentInfo(const string &nameUpper, GradeLevel grade, const string &gpaStr) {
        cout << "\nStudent Record:\n";
        cout << "Name: "        << nameUpper << "\n";
        cout << "Grade Level: " << gradeToString(grade) << "\n";
        cout << "GPA: "         << gpaStr << "\n";
    }
}

int main() {
    string name;
    int gradeChoice;
    GPA gpa;

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter grade level (1=Freshman, 2=Sophomore, 3=Junior, 4=Senior): ";
    while (!(cin >> gradeChoice) || gradeChoice < 1 || gradeChoice > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid number 1-4: ";
    }

    cout << "Enter GPA: ";
    while (!(cin >> gpa) || gpa < 0.0 || gpa > 4.0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a GPA between 0.00 and 4.00: ";
    }

    // Processing
    StudentUtils::formatName(name);
    GradeLevel grade = static_cast<GradeLevel>(gradeChoice);
    string gpaStr = StudentUtils::formatGPA(gpa);

    // Output
    StudentUtils::displayStudentInfo(name, grade, gpaStr);
    return 0;
}
