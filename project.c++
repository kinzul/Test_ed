#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Person {
protected:
    int id;
    string name;
    int age;
public:
    Person(int _id, const string& _name, int _age) : id(_id), name(_name), age(_age) {}
    int getID() const { return id; }
    const string& getName() const { return name; }
    int getAge() const { return age; }
};
class Student : public Person {
private:
    double previousClassMarks;
    double testMarks;
    string section;
public:
    Student(int _id, const string& _name, int _age, double _previousClassMarks, double _testMarks)
        : Person(_id, _name, _age), previousClassMarks(_previousClassMarks), testMarks(_testMarks) {
        section = (testMarks >= 80 && previousClassMarks >= 85) ? "Super" : "General";
    }
    double getPreviousClassMarks() const { return previousClassMarks; }
    double getTestMarks() const { return testMarks; }
    const string& getSection() const { return section; }
};
class Teacher : public Person {
private:
    string subject;
    string section;
    int experience;
public:
    Teacher(int _id, const string& _name, int _age, const string& _subject, int _experience)
        : Person(_id, _name, _age), subject(_subject), experience(_experience) {
        section = (experience >= 10) ? "Super" : "General";
    }
    const string& getSubject() const { return subject; }
    const string& getSection() const { return section; }
    int getExperience() const { return experience; }
};
class User {
private:
    string username;
    string password;
    string role;  
public:
    User(const string& _username, const string& _password, const string& _role)
        : username(_username), password(_password), role(_role) {}
    const string& getUsername() const {
        return username;
    }
    const string& getPassword() const {
        return password;
    }
    const string& getRole() const {
        return role;
    }
};
class College {
private:
    vector<Student> students;
    vector<Teacher> teachers;
    vector<User> users;
public:
    College() {}
    void signUp(const string& username, const string& password, const string& role) {
        users.emplace_back(username, password, role);
        cout << "User signed up successfully." << endl;
    }
    bool signIn(const string& username, const string& password, const string& role) const {
        for (const auto& user : users) {
            if (user.getUsername() == username && user.getPassword() == password && user.getRole() == role) {
                cout << "User signed in successfully." << endl;
                return true;
            }
        }
        cout << "Invalid username, password, or role. Sign in failed." << endl;
        return false;
    }
    void addStudent(const Student& newStudent) {
        if (students.size() < 100) {
            students.push_back(newStudent);
            cout << "Student record added successfully." << endl;
        } else {
            cout << "Maximum number of students reached (100). Cannot add more students." << endl;
        }
    }
    void addTeacher(const Teacher& newTeacher) {
        teachers.push_back(newTeacher);
        cout << "Teacher record added successfully." << endl;
    }
    void displayAllStudents() const {
        cout << "\nAll Students in the system:" << endl;
        for (const auto& student : students) {
            cout << "ID: " << student.getID() << ", Name: " << student.getName()
                 << ", Age: " << student.getAge() << ", Section: " << student.getSection()
                 << ", Previous Class Marks: " << student.getPreviousClassMarks()
                 << "%, Test Marks: " << student.getTestMarks() << endl;
        }
    }
    void displayAllTeachers() const {
        cout << "\nAll Teachers in the system:" << endl;
        for (const auto& teacher : teachers) {
            cout << "ID: " << teacher.getID() << ", Name: " << teacher.getName()
                 << ", Age: " << teacher.getAge() << ", Section: " << teacher.getSection()
                 << ", Subject Taught: " << teacher.getSubject()
                 << ", Experience: " << teacher.getExperience() << " years" << endl;
        }
    }
};
int main() {
    College college;
    int choice;
    do {
        cout << "\nOptions:" << endl;
        cout << "1. Enter student record" << endl;
        cout << "2. Enter teacher record" << endl;
        cout << "3. Check existing student and teacher records" << endl;
        cout << "4. Student Sign Up" << endl;
        cout << "5. Teacher Sign Up" << endl;
        cout << "6. Student Sign In" << endl;
        cout << "7. Teacher Sign In" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice (1-8): ";
        cin >> choice;
        switch (choice) {
           case 1: {
    int numStudents;
    cout << "Enter the number of students to add: ";
    cin >> numStudents;
    for (int i = 0; i < numStudents; ++i) {
        int id, age;
        string name;
        double previousClassMarks, testMarks;
        cout << "Enter details for student " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin.ignore(); 
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Previous Class Marks (%): ";
        cin >> previousClassMarks;
        cout << "Test Marks: ";
        cin >> testMarks;
        college.addStudent(Student(id, name, age, previousClassMarks, testMarks));
    }
    break;
}
case 2: {
    int numTeachers;
    cout << "Enter the number of teachers to add: ";
    cin >> numTeachers;
    for (int i = 0; i < numTeachers; ++i) {
        int id, age, experience;
        string name, subject;
        cout << "Enter details for teacher " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin.ignore();  
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Subject Taught: ";
        cin.ignore(); 
        getline(cin, subject);
        cout << "Experience (in years): ";
        cin >> experience;
        college.addTeacher(Teacher(id, name, age, subject, experience));
    break;
}
            }
            case 3:
                college.displayAllStudents();
                college.displayAllTeachers();
                break;
            case 4: {
                string username, password;
                cout << "Enter a new student username: ";
                cin >> username;
                cout << "Enter a password: ";
                cin >> password;
                college.signUp(username, password, "Student");
                break;
            }
            case 5: {
                string username, password;
                cout << "Enter a new teacher username: ";
                cin >> username;
                cout << "Enter a password: ";
                cin >> password;
                college.signUp(username, password, "Teacher");
                break;
            }
            case 6: {
                string username, password;
                cout << "Enter student username: ";
                cin >> username;
                cout << "Enter your password: ";
                cin >> password;
                college.signIn(username, password, "Student");
                break;
            }
            case 7: {
                string username, password;
                cout << "Enter teacher username: ";
                cin >> username;
                cout << "Enter your password: ";
                cin >> password;
                college.signIn(username, password, "Teacher");
                break;
            }
            case 8:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option (1-8)." << endl;
        }
    } while (choice != 8);

    return 0;
}