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

int getActualArrSize(string arr[], int length)
{
  int size = 0;

  for (int i = 0; i < length - 1; i++)
  {
    if (i % 2 == 0 && arr[i].length() > 0)
      size++;
  }

  return size;
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
  static string terms[10];
  int termsIndex = 0;

  string term = "";

  for (int i = 0; i < expression.length(); i++)
  {
    char ch = expression[i];

    if (getParenthesesLevel(expression, i) == 0 && ch != ' ' && (ch == '+' || ch == '-'))
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

int getLargestNum(int numbers[], int length)
{
  int largest = numbers[0];

  for (int i = 1; i < length; i++)
  {
    if (largest < numbers[i])
      largest = numbers[i];
  }

  return largest;
}

int getLeastNum(int numbers[], int length)
{
  int smallest = numbers[0];

  for (int i = 1; i < length; i++)
  {
    if (smallest > numbers[i])
      smallest = numbers[i];
  }

  return smallest;
}

void printIntArr(int arr[], int length)
{
  for (int i = 0; i < length; i++)
  {
    cout << arr[i] << " ";
  }

  cout << endl;
}

void clearArr(int arr[], int length)
{
  for (int i = 0; i < length; i++)
  {
    arr[i] = 0;
  }
}