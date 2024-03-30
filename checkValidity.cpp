#include <iostream>

#include "helper.cpp"

using namespace std;

bool isLinear(string terms[])
{
  bool isLinearCheck = true;

  for (int i = 0; i < terms->size(); i++)
  {
    if (i % 2 == 1 || terms[i].size() == 0)
      continue;

    string term = terms[i];

    for (int j = 0; j < term.length(); j++)
    {
      char ch = term[j];

      if (ch == '^')
      {
        char power = getNextItem(term, j);

        if (getParenthesesLevel(term, j) == 0 && power != '1')
        {
          isLinearCheck = false;
          break;
        }
      }
    }
  }

  return isLinearCheck;
}

bool isHomogeneous(string terms[])
{
  bool isHomogeneousCheck = true;

  for (int i = 0; i < terms->size(); i++)
  {
    if (i % 2 == 1 || terms[i].size() == 0)
      continue;

    string term = terms[i];

    for (char ch : term)
    {
      if (term.find("a(n") == string::npos)
      {
        isHomogeneousCheck = false;
        break;
      }
    }
  }

  return isHomogeneousCheck;
}

bool isConstantCoefficient(string terms[])
{

  bool isConstantCoefficientCheck = true;

  for (int i = 0; i < terms->size(); i++)
  {
    if (i % 2 == 1 || terms[i].size() == 0)
      continue;

    string term = terms[i];
    int aCount = 0;
    int nCount = 0, nCountAfterA = 0;

    for (char ch : term)
    {
      if (isalpha(ch) && ch != 'a' && ch != 'n')
      {
        isConstantCoefficientCheck = false;
        break;
      }

      if (ch == 'a')
        aCount++;

      if (ch == 'n')
        nCount++;
    }

    int aOfNIndex = term.find("a(n");

    if (aOfNIndex != string::npos)
    {
      int j = aOfNIndex + 2, parenthesesCounter = 1;

      while (parenthesesCounter > 0)
      {

        if (term[j] == 'n')
          nCountAfterA++;

        if (term[j] == '(')
          parenthesesCounter++;

        if (term[j] == ')')
          parenthesesCounter--;

        j++;
      }
    }

    if (aCount > 1)
      isConstantCoefficientCheck = false;

    if (nCount != nCountAfterA)
      isConstantCoefficientCheck = false;
  }

  return isConstantCoefficientCheck;
}

int getDegree(string terms[])
{
  int termsSize = getActualArrSize(terms, terms->size());

  int degrees[termsSize];
  int degreesCount = 0;
  clearArr(degrees, termsSize);

  for (int i = 0; i < terms->size(); i++)
  {
    if (i % 2 == 1 || terms[i].size() == 0)
      continue;

    string term = terms[i];
    int aOfNIndex = term.find("a(n");

    if (aOfNIndex != string::npos)
    {
      int j = aOfNIndex + 3, parenthesesCounter = 1;

      string degree = "";

      while (parenthesesCounter > 0)
      {

        if (term[j] == '(')
          parenthesesCounter++;

        if (term[j] == ')')
          parenthesesCounter--;

        if (term[j] == '+' || term[j] == '-' || isdigit(term[j]))
          degree += term[j];

        j++;
      }

      degrees[degreesCount] = stoi(degree);
      degreesCount++;
    }
  }

  int largestDegree = getLargestNum(degrees, termsSize),
      leastDegree = getLeastNum(degrees, termsSize);

  if (largestDegree > 0)
    return 1;

  return leastDegree;
}