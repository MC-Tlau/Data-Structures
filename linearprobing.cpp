#include <iostream>
#define SIZE 10
using namespace std;

void Insert(int H[], int key);
int Hash(int key) {return key % 10;}
int probe(int H[], int key);
int Search(int H[], int key);

int main()
{
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A)/sizeof(A[0]);

    int HT[10] = {0}; 
    for (int i = 0; i < n; i++) Insert(HT,A[i]);

    
    int index = Search(HT, 25);
    cout << "key found at: " << index << endl;
 
    index = Search(HT, 35);
    cout << "key found at: " << index << endl;
 

}

void Insert(int H[], int key)
{
    int index = Hash(key);
    if (H[index] == 0) 
    index = probe(H, key);
    H[index] = key;
}

int probe (int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while (H[(index + i) % SIZE]  != 0) i++;
    return (index + i) % SIZE;
}

int Search(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while (H[(index + i) % SIZE]  != key) i++;
    if (H[(index + i) % SIZE] == 0)
    {
        return -1;
    }
    return (index + i) % SIZE;
}
