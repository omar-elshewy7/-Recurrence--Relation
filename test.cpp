#include <iostream>

// #include "helper.cpp"
#include "checkValidity.cpp"

using namespace std;

int main()
{
  string testTerms[] =
      {
          "(a(n-1))/na(n-1)",
          "(a(n-1))^0.5",
          "3a(n-1)+a(n-2)",
          "3a(n-1)+2^n",
          "3a(n-1)+5",
          "(a(n-1))^1+3(a(n-2))^1",
          "2a(n-1)+na(n-2)",
          "(a(n-1))^2+a(n-2)",
          "(a(n-1))^1+n",
          "3a(n-1)+4a(n-2)+5a(n-3)",
          "4(a(n-2))^1+5(a(n-4))^1+(a(n-7))^1"};

  cout << endl
       << endl
       << endl
       << endl;

  for (int i = 0; i < testTerms->size(); i++)
  {
    string *terms = separateExpression(testTerms[i]);

    cout << i + 1 << ". ";

    for (int i = 0; i < terms->size(); i++)
    {
      cout << terms[i] << " ";
    }

    // cout << "\nIs Linear: " << (isLinear(terms) ? "true" : "false") << endl;
    // cout << "Is Homogeneous: " << (isHomogeneous(terms) ? "true" : "false") << endl;
    // cout << "Is Constant Coefficient: " << (isConstantCoefficient(terms) ? "true" : "false") << endl;

    cout << "\nThis is a" << (isLinear(terms) ? " " : " non-") << "linear" << (isHomogeneous(terms) ? " " : " non-") << "Homogeneous and is" << (isConstantCoefficient(terms) ? " " : " not ") << "constant coefficient." << endl;

    cout << endl;
  }
}