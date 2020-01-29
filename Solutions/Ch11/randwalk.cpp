// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vect.h"
#include <fstream>
#include <vector>

int main()
{
    using namespace std;
    using VECTOR::Vector;
    ofstream fout;
    srand(time(0));     // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    double avg = 0;
    unsigned long maxval = 0, minval = 0;
    vector<unsigned long> stepList;

    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        fout.open("steps.txt", ios_base::trunc);

        if (!(cin >> dstep))
            break;
        fout << "Target Distance: " << target << ", Step Size: " <<  dstep << endl;

        while (result.magval() < target)
        {
            fout << steps << ": (x,y) = (" << result.xval() << ", " << result.yval() << ")\n";
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        stepList.push_back(steps);
        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval()/steps << endl;
        fout << "After " << steps << " steps, the subject has the following location:\n";
        fout << "(x,y) = (" << result.xval() <<", " << result.yval() << ")\n";
        fout << "or\n" << "(m, a) = (" << result.magval() << ", " << result.angval() << ")\n";
        fout << "Average outward distance per step = " << result.magval() / steps << endl;
        fout.close();
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
/* keep window open
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    if(!stepList.empty()) {
        minval = maxval = stepList[0];
        unsigned long sum = 0;
        for(int i = 0; i < stepList.size(); ++i)
        {
            sum += stepList[i];
            if (stepList[i] > maxval)
            {
                maxval = stepList[i];
            }
            if (stepList[i] < minval)
            {
                minval = stepList[i];
            }
        }
        avg = sum / stepList.size();
        cout << "maxval: " << maxval << ", minval: " << minval
        << ", and avgval: " << avg << endl;
    }
    return 0;
}
