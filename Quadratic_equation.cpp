/* Quadratic equation - napisz program, który wyznacza liczbę pierwiastków rzeczywistych równania kwadratowego.
Input:    Na wejście programu podana zostanie pewna nieokreślona, ale niewielka ilość zestawów danych.Każdy zestaw składać się będzie z 3 liczb rzeczywistych(współczynników A, B i C równania Ax ^ 2 + Bx + C = 0) rozdzielonych spacjami.
            Poszczególne zestawy zostaną rozdzielone znakiem nowej linii. Można przyjąć, że A jest różne od zera.
Output:    Na wyjściu ma się pojawić ciąg liczbowy, którego i - ta pozycja jest równa liczbie pierwiastków rzeczywistych i - tego wczytanego z wejścia równania.Poszczególne liczby należy rozdzielić znakami nowej linii. Przykład:

0.3x^2 + 0.3x + 0.4 = 0     ->      A = 0.3     B = 0.3     C = 0.4
0.5x^2 + x + 0.5 = 0        ->      A = 0.5     B = 1       C = 0.5
-0.5x^2 - 0.5x = 0          ->      A = -0.5    B = -0.5    C = 0

Input:
0.3 0.3 0.4
0.5 1 0.5
-0.5 -0.5 0

Output:
No answers.
Score = -0.25
Lower score = 0     Higher score = -0.25 */

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<double> A, B, C;

int main()
{
    string temporaryString;

    size_t lineNumber = 0;

    getline(cin, temporaryString);

    while (temporaryString != "")
    {
        A.push_back(stod(temporaryString.substr(0, temporaryString.find(" "))));

        temporaryString = temporaryString.substr(temporaryString.find(" ") + 1);

        B.push_back(stod(temporaryString.substr(0, temporaryString.find(" "))));

        C.push_back(stod(temporaryString.substr(temporaryString.find(" ") + 1)));

        getline(cin, temporaryString);
    }

    while (A.size() > lineNumber)
    {
        double delta = pow(B.at(lineNumber), 2) - (4 * A.at(lineNumber) * C.at(lineNumber));

        if (delta > 0)
        {
            double x1 = (-B.at(lineNumber) - sqrt(delta)) / 2 * A.at(lineNumber);

            double x2 = (-B.at(lineNumber) + sqrt(delta)) / 2 * A.at(lineNumber);

            cout << "Lower score = " << x1 << "; Higher score = " << x2 << endl;
        }

        else if (delta == 0)
        {
            double x = -B.at(lineNumber) / 2 * A.at(lineNumber);

            cout << "Score = " << x << endl;
        }

        else if (delta < 0)
        {
            cout << "No answers." << endl;
        }

        lineNumber++;
    }
}