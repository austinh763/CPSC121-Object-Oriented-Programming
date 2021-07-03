#include <iostream>
using namespace std;

//Author: Austin Hoang
//CPSC 121 Lab 2
// <09/10/18>

int main () {

//Setting variables up for input

    double gradeQuizzes = 0;
    double gradeLabwork = 0;
    double gradeMidterm = 0;
    double gradeFinal = 0;
    double gradeParticipation = 0;
    double finalGrade = 0;

//Asking the user for grade inputs.
 
    cout << "Please enter your average grade for quizzes, labwork, " << endl;
    cout << "midterm, participation, and final. If there is no data " << endl;
    cout << "for a category, enter -1. " << endl;
    cout << "Quiz grade: " << endl;
    cin >> gradeQuizzes;
    cout << "Labwork: " << endl;
    cin >> gradeLabwork;
    cout << "Midterm: " << endl;
    cin >> gradeMidterm;
    cout << "Final: " << endl;
    cin >> gradeFinal;
    cout << "Participation: " << endl;
    cin >> gradeParticipation;

//Grade calculations
   
   if (gradeQuizzes == -1) {
      finalGrade = ((gradeLabwork * 35) + (gradeMidterm * 15) + (gradeFinal * 30) +
      (gradeParticipation * 10)) / 90;
    }
      else if (gradeLabwork == -1) {
        finalGrade = ((gradeQuizzes * 10) + (gradeMidterm * 15) + (gradeFinal * 30) +
        (gradeParticipation * 10)) / 65;
      }
      else if (gradeMidterm == -1) {
        finalGrade = ((gradeQuizzes * 10) + (gradeLabwork * 35) + (gradeFinal * 30) +
        (gradeParticipation * 10)) / 85;
      }
      else if (gradeFinal == -1) {
        finalGrade = ((gradeQuizzes * 10) + (gradeLabwork * 35) + (gradeMidterm * 15) +
        (gradeParticipation * 10)) / 70;
      }
      else if (gradeParticipation == -1) {
        finalGrade = ((gradeQuizzes * 10) + (gradeLabwork * 35) + (gradeMidterm * 15) + (gradeFinal * 30)) / 90;
      }
      else {
        finalGrade = ((gradeQuizzes * 10) + (gradeLabwork * 35) + (gradeMidterm * 15) + (gradeFinal * 30) +
        (gradeParticipation * 10)) / 100;
      }

//Displaying to user the grade they got in terms of percentage and letter.

    if ((finalGrade >= 90) || (finalGrade == 100)) {
      cout << "Your grade is " << finalGrade << " percent which is an A." << endl;
    }
      else if ((finalGrade >= 80) || (finalGrade == 89)) {
        cout << "Your grade is " << finalGrade << " percent which is a B." << endl;
      }
      else if ((finalGrade >= 70) || (finalGrade == 79)) {
        cout << "Your grade is " << finalGrade << " percent which is a C." << endl;
      }
      else if ((finalGrade >= 60) || (finalGrade == 69)) {
        cout << "Your grade is " << finalGrade << " percent which is a D." << endl;
      }
      else if (finalGrade <= 59) {
        cout << "Your grade is " << finalGrade << " percent which is an F." << endl;

      }

      return(0);
}
