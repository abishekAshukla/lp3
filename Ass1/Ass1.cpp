#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of Fibonacci terms to calculate: ";
    cin >> n;

    long long fib1 = 1, fib2 = 1, nextTerm;
    int stepCount = 0;

    if (n <= 0)
    {
        cout << "Invalid input. Please enter a positive number." << endl;
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            stepCount++;
            if (i == 1)
                cout << "Fibonacci Sequence: " << fib1 << ", ";
            else if (i == 2)
                cout << fib2 << ", ";
            else
            {
                nextTerm = fib1 + fib2;
                fib1 = fib2;
                fib2 = nextTerm;
                cout << nextTerm << ", ";
            }
        }
        cout << "...\n";
        cout << "Total steps taken: " << stepCount << endl;
    }

    return 0;
}
