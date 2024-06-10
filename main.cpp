 // This program calculates the user's pay.
   //
   // Taken from Starting Out With C++ from Control Structures through Objects (Ninth Edition) by Tony Gaddis (2018)
   //
   // Programmed by Langley Redmill, CIS251 student
   // June 7, 2024
#include <iostream>
using namespace std;
int main()
{
    double hours;
    double rate;
    double paycheck;

    cout << "How many hours did you work this week?" << endl;
    cin >> hours;

    cout << "How much do you get paid per hour?" << endl;
    cin >> rate;

    paycheck = rate*hours;
    cout << "You have earned $" << paycheck << " this month." << endl;
    return 0;
}
