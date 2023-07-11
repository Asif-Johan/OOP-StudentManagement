// Student management system
//?? refers to question or further development region

// Add new student
// Display All student
// Search Student
// Update student
//  Delete Student
//  Exit

// Header Files
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

// Creating Student Class

class Student
{
private:
    int RollNo, Age; //
    string name;

public:
    // member function with the same name as its class must be a constructor

    // constructor

    //?? Understand Constructor Well
    Student(int stdRollno, string stdName, int stdAge)
    {
        RollNo = stdRollno;
        name = stdName;
        Age = stdAge;
    }

    // All Setter and Getter Methods

    // Setter Method RollNo
    void setRollNo(int stdRollNo)
    {
        RollNo = stdRollNo; //??
    }
    // getter method RollNo
    int getRollNo()
    {
        return RollNo;
    }

    // Setter method Name
    void setName(string stdName)
    {
        name = stdName;
    }

    // getter method Name
    string getName()
    {
        return name;
    }

    // setter method Age
    void setAge(int stdAge)
    {
        Age = stdAge;
    }
    // Getter method Age
    int getAge()
    {
        return Age;
    }

    // End of all setter and getter methods

    // Function to display all student
};


//?? why these functions are put outside the class?
//?? mUst learn all about Vector





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1. Create Function to add new student
void addNewStudent(vector<Student> &students)
{

    int roll, age; // declare variables of New student
    string name;

    cout << "Enter Roll No: "; // get info of new student
    cin >> roll;
    // check if student already exists
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getRollNo() == roll )
        {
            system("cls");
            cout << "Student Already Exists....." << endl;

            _getch();
            return;
        }
    }
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;

    Student newStudent(roll, name, age);

    students.push_back(newStudent); //?? Must understand push_back

    cout << "Student Added Successfully..." << endl;
    _getch();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2. Create Function to Display all studetns
void displayStudent(vector<Student> &students)////
{
    for(int i=0; i<students.size();i++)
    {
    cout << "Roll No: " << students[i].getRollNo() << endl;
    cout<< "Name: "<<students[i].getName()<<endl;
    cout<< "Age: "<<students[i].getAge()<<endl;
    cout<<endl;
    
    }
    _getch();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//3. Create Function to search Students

void searchStudents(vector<Student> &students){
int searchRoll;
cout<<"Give Student Roll...."<<endl;
cin>>searchRoll;

cout << "Roll No: " << students[searchRoll-1].getRollNo() << endl;
    cout<< "Name: "<<students[searchRoll-1].getName()<<endl;
    cout<< "Age: "<<students[searchRoll-1].getAge()<<endl;
    cout<<endl;

_getch();

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//4. Create Function to Update Student

void updateStudent(vector<Student> &students){
    system("cls");

int Roll, choice;


cout<<"Enter Roll to update record:";
cin.ignore();//?? what is this code
cin>> Roll;//?? what is this code

cout<<"Update info of.....";
cout<<"1. Update Roll"<<endl;
cout<<"2. Update Name"<<endl;
cout<<"3. Update Age"<<endl;


cin>>choice;

switch (choice)
{
case 1:{
    int NewRoll;
    cout<<"Enter New Roll :";
    cin>>NewRoll;
    students[Roll-1].setRollNo(NewRoll);
}
    break;
case 2:{
    string NewName;
    cout<<"Enter New Name :";
    cin.ignore();
    getline(cin,NewName);
    students[Roll-1].setName(NewName);
}
    break;
case 3:{
    int NewAge;
    cout<<"Enter New Age :";
    cin>>NewAge;
    students[Roll-1].setAge(NewAge);
}
    break;



default:
cout<<"number Not valid"<<endl;
    break;
}
_getch();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//5. Create Function  to delete student

void deleteStudent(vector<Student> &students){
system("cls");
int Roll, choice;
cout<<"Enter Roll to delete record:";
cin.ignore();//?? what is this code
cin>> Roll;//?? what is this code

students.erase((students.begin()+(Roll-1)));
cout<<"Student successfully Deleted"<<endl;
_getch();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

main()
{
    vector<Student> students;
    students.push_back(Student(1, "Ali", 20));

    // Create menue

    do
    {
        system("cls");
        int option;
        cout << "****Menu****" << endl;
        cout << "1. Add New Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Exit" << endl;
        cout << ".......Enter Choice number......." << endl;

        cin >> option;

        switch (option)
        {

        case 1:
            addNewStudent(students);

            break;

            case 2: 
            displayStudent(students); ////
            break;
            case 3: 
            searchStudents(students); ////
            break;
            case 4: 
            updateStudent(students); ////
            break;
            case 5: 
            deleteStudent(students); ////
            break;

        case 6:
            exit(1);

        default:
            cout << "Invalid Number...." << endl;
        }

    } while (1);
}
