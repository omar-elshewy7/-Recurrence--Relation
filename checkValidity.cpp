#include <iostream>
#include <string>

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

    // cout << "n count: " << nCount << " n in a count: " << nCountAfterA << endl;

    if (aCount > 1)
      isConstantCoefficientCheck = false;

    if (nCount != nCountAfterA)
      isConstantCoefficientCheck = false;
  }

  return isConstantCoefficientCheck;
}

int getDegree(string terms[])
{
  int degree = 0;
}