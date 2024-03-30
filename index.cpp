#include <iostream>

#include "checkValidity.cpp"

using namespace std;

string getResult(bool linear, bool homogeneous, bool constantCoefficient, int degree)
{
  string linearMessage = linear ? " " : " non-",
         homogeneousMessage = homogeneous ? " " : " non-",
         constantCoefficientMessage = constantCoefficient ? " " : " not ",
         degreeMessage = degree == 1 ? "n cannot be a negative number" : degree == 0 ? "n cannot be zero"
                                                                                     : to_string(-1 * degree);

  return "This is a" + linearMessage + "linear" + homogeneousMessage + "homogeneous and is" + constantCoefficientMessage + "constant coefficient. Degree: " + degreeMessage;
}

int main()
{
  string expression = "";

  cout << "Enter the expression as (4(a(n-2))^1 + 5(a(n-4))^1 + (a(n-7))^1): " << endl;
  getline(cin, expression);

  string *terms = separateExpression(expression);
  bool linear = isLinear(terms),
       homogeneous = isHomogeneous(terms),
       constantCoefficient = isConstantCoefficient(terms);
  int degree = getDegree(terms);

  cout << endl
       << getResult(linear, homogeneous, constantCoefficient, degree)
       << endl;

  return 0;
}