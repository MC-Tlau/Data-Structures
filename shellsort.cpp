#include <iostream>
using namespace std;

void ShellSort(int A[], int n)
{
    int i, j;
    for (int pass = n/2; pass >= 1; pass = pass/2)
    {
        for (i = 0, j = i + pass; j < n; i++, j = i+pass)
        {
            // int j = i + pass;
            int k = i;
            // if (j > n-1) break;

            while ( k >= 0)
            {
                if (A[k] < A[j]) break;
                else
                {
                    int temp = A[k];
                    A[k] = A[j];
                    A[j] = temp;
                    j = k;
                    k = j - pass;
                }
            }
        }
    }
}

int main()
{
    int a[] = {2,5,12,4,23,1,15,55,-1,6};
    int size = sizeof(a)/sizeof(int);

    ShellSort(a, size);

    for (int i = 0; i < size; i++) cout << a[i] << " ";
}