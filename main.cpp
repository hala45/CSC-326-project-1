#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
// Hala Basyouni CSC326 Lab #02 --- 01/29/2020
/*In this lab a program is designed and implemented using the structure below (Student), and allocates an ARRAY OF 10 ELEMENTS/ STRUCTURES to contain the information.*/
using namespace std;
//a struct named Student
struct Student {
 float arrayGrades[10];
 string name;
 char LG;
};
//function prototypes
char averageTOletterGrade(float);
void outputData(int, Student, int, int, int, int, float, int);
int main(){
 
 ifstream input;
 int studentsNumber;
 int gradesNumber;
 Student students[3]; //declaring array of students
 float grade;
 float sum = 0;
 int count = 0;
 float average = 0;
 int max = 0;
 int min = 100;
 int testNumbMax = 0;
 int testNumbMin = 0;

 //opening input file
 input.open("grades.txt");
 //checking for error
 if (input.fail()) {
  cerr << "Error opening the input file..." << endl;
 }
 //asking user for the # of students
 cout << "How many students are in your class?" << endl;
 cin >> studentsNumber;
 //asking how many grades they should have
 cout << "How many grades did each student should get?" << endl;
 cin >> gradesNumber;
 //looping for each student
 for (int i = 0; i < studentsNumber; i++) {
  sum = 0;
  count = 0;
  average = 0;
  input >> students[i].name; // inputting the name of the student from "grades.txt"
  //looping for the grades
  for (int j = 0; j < gradesNumber; j++) {
   //inputing the grades from grades.txt
   input >> grade;

   //inputting each grade into the struct array
   students[i].arrayGrades[j] = grade;
   //finding the sum of all the grades for each student
   //if grade is -1 it means the student didn't take the test
   if (grade != -1) {

       //finding the max/min grade and the number of the test
       if (grade > max) {
           max = grade;
           testNumbMax = count + 1;
       }
       if (grade < min) {
           min = grade;
           testNumbMin = count + 1;
       }

   sum = sum + grade;
   count++;
  }
  }
  
  
  //If the Student has less than 10 grades, then the Student should get a "W" grade.
  if (count >= 10) {
   average = sum / (count);
   students[i].LG = averageTOletterGrade(average);
  }
  
  else {
   students[i].LG = 'W';
  }
  //calling the outputData function
  outputData(studentsNumber, students[i], max, min, testNumbMax, testNumbMin, average, gradesNumber);
 }
 //pause the system
 system("pause");
 return 0;
}//end main
/*
This function takes a number grade and
translates it into a letter grade
*/
char averageTOletterGrade(float numberGrade)
{
 if (numberGrade >= 90) {
  return 'A';
 }
 else if (numberGrade >= 80 && numberGrade < 90) {
  return 'B';
 }
 else if (numberGrade >= 70 && numberGrade < 80) {
  return 'C';
 }
 else if (numberGrade >= 60 && numberGrade < 70) {
  return 'D';
 }
 else {
  return 'F';
 }
}


/*
This function takes the number of students and the struct
holding the data, and it outputs all the data
*/

void outputData(int studNum, Student studs, int mx, int mn, int mxNum, int mnNum, float avrg, int gradesNum){
 cout << "\n\nStudent: " << studs.name << "\nAverage: " << avrg;
 cout << "\nLetter Grade: " << studs.LG << "\nHighest Grade: " << mx << " on Test number: " << mxNum << "\nLowest Grade: " << mn << " on Test number: " << mnNum << "\n\nAllgrades: ";
 for (int k = 0; k < gradesNum; k++) {
  cout << studs.arrayGrades[k] << " ";
 }
 
 
}

/*
INPUT FILE:
 Hala
 90
 100
 87
 100
 100
 97
 94
 89
 97
 100
 Laila
 -1
 100
 88
 74
 65
 91
 35
 84
 -1
 100
 Kimi
 90
 100
 91
 76
 100
 53
 88
 35
 92
 100

 OUTPUT:
 How many students are in your class?
 3
 How many grades did each student should get?
 10


 Student: Hala
 Average: 95.4
 Letter Grade: A
 Highest Grade: 100 on Test number: 2
 Lowest Grade: 87 on Test number: 3

 Allgrades: 90 100 87 100 100 97 94 89 97 100

 Student: Laila
 Average: 0
 Letter Grade: W
 Highest Grade: 100 on Test number: 2
 Lowest Grade: 35 on Test number: 6

 Allgrades: -1 100 88 74 65 91 35 84 -1 100

 Student: Kimi
 Average: 82.5
 Letter Grade: B
 Highest Grade: 100 on Test number: 2
 Lowest Grade: 35 on Test number: 6

 Allgrades: 90 100 91 76 100 53 88 35 92 100 sh: pause: command not found
 Program ended with exit code: 0

*/
