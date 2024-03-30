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
          "3a(n-1)+a(n+2)",
          "3a(n-0)+2^n",
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

    bool linear = isLinear(terms),
         homogeneous = isHomogeneous(terms),
         constantCoefficient = isConstantCoefficient(terms);
    int degree = getDegree(terms);

    cout << i + 1 << ". ";

    for (int i = 0; i < terms->size(); i++)
    {
      cout << terms[i] << " ";
    }

    // cout << "\nIs Linear: " << (linear? "true" : "false") << endl;
    // cout << "Is Homogeneous: " << (homogeneous? "true" : "false") << endl;
    // cout << "Is Constant Coefficient: " << (constantCoefficient? "true" : "false") << endl;
    /*
    cout << "Degree: " << (degree == 1 ? "n cannot be a negative number" : degree == 0 ? "n cannot be zero"
                                                                                       : to_string(degree))
         << endl;
    */

    cout << "\nThis is a" << (linear ? " " : " non-") << "linear"
         << (homogeneous ? " " : " non-") << "Homogeneous and is"
         << (constantCoefficient ? " " : " not ") << "constant coefficient. Degree: " << (degree == 1 ? "n cannot be a negative number" : degree == 0 ? "n cannot be zero"
                                                                                                                                                      : to_string(-1 * degree))
         << '.' << endl
         << endl;
  }
}