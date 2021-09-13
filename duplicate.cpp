#include <iostream>
using namespace std;

int main()
{
    int a[10] = {1,2,2,3,4,5,5,6,7,7};

    for (int i = 0; i < 9; i++)
    {
        if (a[i+1] == a[i])
        {
            int count = 2;
            int j = (i+1) + 1;

            while ( a[j] == a[i])
            {
                ++count;
                ++j;
            }
            
            cout << a[i] << " is repeated " << count << endl << "times";

            i = j;
        }
    }
}