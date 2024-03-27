#include <iostream>

using namespace std;

// Function to check if parentheses count matches
bool checkParentheses(string expression)
{
  int count = 0;

  // Counting opening and closing parentheses
  for (char ch : expression)
  {
    if (ch == '(')
      count++;
    if (ch == ')')
      count--;
  }

  return count == 0; // Returns true if counts match
}

// bool digitsAndOperatorsCheck(string expression)
// {
//   bool valid = true;

//   for (char ch : expression)
//   {
//     if (!isOperator(ch) && !isdigit(ch) && ch != '.' && ch != '(' && ch != ')' && ch != 'x')
//     {
//       cout << ch << endl;
//       valid = false;
//     }
//   }

//   return valid;
// }

string checkValidity(string expression)
{
  // Check if the expression has more than two variables
  // bool countCheck = variablesCountChecker(expression);
  // if (!countCheck)
  // return "Error: There are other variables instead of \"x\".\n";

  // Check if the expression has parentheses
  bool parenthesesCheck = checkParentheses(expression);
  if (!parenthesesCheck)
    return "Error: Opening parentheses count and closing parentheses count don't match.\n";

  // Check if the expression has digits and operators
  // if (!digitsAndOperatorsCheck(expression))
  //   return "Error: Invalid Character found in expression";

  return "";
}