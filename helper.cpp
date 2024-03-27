#include <iostream>

using namespace std;

bool isOperator(char c)
{
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

char getNextItem(string original_string, int i)
{
  if (i + 1 > original_string.size() - 1)
    return ' ';

  return original_string[i + 1];
}

int getParenthesesLevel(string term, int index)
{
  int parenthesesLevel = 0;

  for (int i = 0; i < index; i++)
  {
    char ch = term[i];

    if (ch == '(')
      parenthesesLevel++;
    if (ch == ')')
      parenthesesLevel--;
  }

  return parenthesesLevel;
}

int getHighestParenthesesLevel(string term)
{
  int highestParenthesesLevel = 0;

  for (int i = 0; i < term.length(); i++)
  {
    char ch = term[i];

    if (ch == '(')
      highestParenthesesLevel++;
    if (ch == ')')
      highestParenthesesLevel--;
  }

  return highestParenthesesLevel;
}

string *separateExpression(string expression)
{
  static string terms[100];
  int termsIndex = 0;

  string term = "";

  for (int i = 0; i < expression.length(); i++)
  {
    char ch = expression[i];

    if (getParenthesesLevel(expression, i) == 0 && (ch == '+' || ch == '-'))
    {
      terms[termsIndex++] = term;
      terms[termsIndex++] = ch;
      term = "";
      continue;
    }

    term += ch;

    if (i == expression.length() - 1)
    {
      terms[termsIndex++] = term;
      term = "";
    }
  }

  return terms;
}

// string *fitArr(string arr[])
// {
//   int arrLen = 1, i = 0;

//   while (i < arrLen)
//   {
//     if (arr[i].length() == 0)
//     {
//       arrLen--;
//       continue;
//     }

//     i++, arrLen++;
//   }

//   string fittedArr[arrLen + 1] = {arrLen + ""};

//   for (i = 1; i < arrLen; i++)
//   {
//     fittedArr[i] = arr[i];
//   }

//   return fittedArr;
// }