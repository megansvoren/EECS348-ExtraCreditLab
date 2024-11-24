/*
 * Name: Megan Svoren
 * Lab Session: Wednesday @ 1:00pm
 * Lab #: Extra Credit
 * Last modified: 11/22/24
 * Purpose: A program that reads a string from the user and extracts a valid double-precision floating-point number from it.
 * Note: Please put the points earned on this lab towards my quiz/exam grades
*/
#include <iostream>
#include <iomanip> // For formatting a double-precision number.
#include <string>
#include <string.h>
#include <cmath>

// Add this line to avoid repeating std::
using namespace std;

// Declaring global variable for if a positive or negative sign is used
bool posNegUsed = false;

// Prototype for the extractNumeric function
double extractNumeric(const string& str) {
  int length = str.length();
  bool periodUsed = false;
  double result = 0.0;
  for (int i = 0; i < length; i++) {
    if (int(char(str[i])) == 43 || int(char(str[i])) == 45 || int(char(str[i])) == 46 || (int(char(str[i])) >= 48 && int(char(str[i])) <= 57)) { // Ensuring all are valid characters by using their ASCII values
      if (int(char(str[i])) == 46) {
        periodUsed = true;
      } else if (int(char(str[i])) == 43 || int(char(str[i])) == 45) {
        posNegUsed = true; 
      } else if ((int(char(str[i])) == 46 && periodUsed) || (i > 0 && (int(char(str[i])) == 43 || int(char(str[i])) == 45))) // Checks if there are multiple periods or a + or - past the first character
      {
        return -999999.99;
      }
    } else {
      return -999999.99;
    }
  }

  string revString = "";
  if (posNegUsed){
    if (periodUsed) {
      int periodIndex = str.find(".");
      for (int k = periodIndex - 1; k >= 1; k--) {
        // Reverses the string str
        revString += str[k];
      }
      for (int i = 0; i < periodIndex - 1; i++) {
        result += (int(char(revString[i])) - 48) * pow(10, i);
      }
      for (int j = periodIndex + 1, k = 1; j < length; j++, k++) {
        result += (int(char(str[j])) - 48) / pow(10, k);
      }
    } else {
      for (int k = length - 1; k >= 1; k--) {
        revString += str[k];
      }
      for (int i = 0; i < length; i++) {
        result += pow(10, i) * (int(char(revString[i])) - 48);
      }
    }
  } else {
    if (periodUsed) {
      int periodIndex = str.find(".");
      for (int k = periodIndex - 1; k >= 0; k--) {
        // Reverses the string str
        revString += str[k];
      }
      for (int i = 0; i < periodIndex; i++) {
        result += (int(char(revString[i])) - 48) * pow(10, i);
      }
      for (int j = periodIndex + 1, k = 1; j < length; j++, k++) {
        result += (int(char(str[j])) - 48) / pow(10, k);
      }
    } else {
      for (int k = length - 1; k >= 0; k--) {
        revString += str[k];
      }
      for (int i = 0; i < length; i++) {
        result += pow(10, i) * (int(char(revString[i])) - 48);
      }
    }
  }
  return result;
}

int main() {
  string input;
  while (true) {
    cout << "Enter a string (or 'END' to quit): ";
    cin >> input;

    if (input == "END") {
      break;
    }

    double number = extractNumeric(input);

    if (number != -999999.99 && int(char(input[0])) == 45) {
      cout << "The input is " << input[0] << fixed << setprecision(4)
           << number << endl;
    } else if (number != -999999.99) {
      cout << "The input is " << fixed << setprecision(4)
           << number << endl;
    } else {
      cout << "The input is invalid." << endl;
    }
  } 

  return 0;
}