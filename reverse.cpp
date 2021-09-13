#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a number";
    int n;
    int remainder = 0;
    cin >> n;

    for (int i = n; i >= n;)
    {
        remainder = i % 10;
        i = i / 10;
    }

    cout << remainder;
}