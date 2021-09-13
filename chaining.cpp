#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class HashTable
{
    node **h;
    int size;

    public:
    HashTable()
    {
        size = 10; h = new node *[size];
        for (int i = 0; i < size; i++)
        {
            h[i] = NULL;
        }
    }

    ~HashTable();
    int hash(int x);
    void Insert(int x);
    void Delete(int x);
    int Search(int x);
    
};

int HashTable::hash(int x)
{
    return x % 10;
}

void HashTable::Insert(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;

    int index = hash(x);
    if (h[index] == NULL) h[index] = temp;
    else
    {
        node *p = h[index];
        node *q = h[index];
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (q == h[index])
        {
            temp->next = h[index];
            h[index] = temp;
        }
        else
        {
            temp->next = q->next;
            q->next = temp;           
        }
    }
    
}
int HashTable::Search(int key)
 {
	int hIdx = hash(key);
	node* p = h[hIdx];
	while (p){
		if (p->data == key)
        {
			return p->data;
		}
		p = p->next;
	}
	return -1;
}

HashTable::~HashTable() 
{
	for (int i =0 ; i < 10; i++)
    {
		node* p = h[i];
		while (h[i]){
			h[i] = h[i]->next;
			delete p;
			p = h[i];
		}
	}
	delete [] h;
}

int main()
{
    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int n = sizeof(A)/sizeof(A[0]);
	HashTable H;
	for (int i=0; i<n; i++)
    {
		H.Insert(A[i]);
	}
	cout << "Successful Search" << endl;
	int key = 6;
	int value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	cout << "Unsuccessful Search" << endl;
	key = 95;
	value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;

	return 0;
}