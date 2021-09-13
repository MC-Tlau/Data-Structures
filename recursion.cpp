#include <iostream>
#include <stdio.h>

using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

int main()
{
    struct Array a;
    int s;
    cout<<"Enter the size of the array: ";
    cin>>s;
    a.A = new int[s];
    cout<<"This is a pointer "<<a.A;
    cout<<"This is the size you entered" << a.size;

}   