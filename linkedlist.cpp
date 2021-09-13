#include <iostream>
using namespace std;

struct Node
{
    public:
    int data;
    Node *next;
};

class LinkedList
{   public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = NULL;
    }
    LinkedList(int n)
    {
        head = new Node;
        if (n < 1)
        { 
            cout << "Invalid number !!!";
            return;
        }
        
        cout << "Enter the 1 element : ";
        cin >> head->data;
        head->next = NULL;
        tail = head;

        for (int i = 1; i < n; i++)
        {
            Node *temp = new Node;
            cout << "Enter the " << i+1 << " element: ";
            cin >> temp->data;
            temp->next = NULL;
            tail->next = temp;        
            tail = temp;
        }

    }
    ~LinkedList()
    {
        Node *p = head;
        while (head)
        {
            head = head->next;
            delete p;
            p = head;
        }
    }
    void insert(int x);
    void insert(int index, int x);
    void del(int index);
    int length();
    bool isSorted();
    void removeDuplicate();
    void reverseElements();
    void reverseLinks(Node *q, Node *p); //recursive
    void reverseLinks2(); //sliding window
    void mergeLinkedList(Node *first, Node *second);
    bool isLoop();
    void display();
};

void LinkedList::display()
{
    Node *p = head; 
    while (p)
    {
        cout << p->data << "->";
        p = p->next;
    }
}

void LinkedList::insert(int x) //Insert at last
{
    if (head == NULL) // if they are 0 elements
    {
        head = new Node;
        head->data = x;
        head->next = NULL;
        tail = head;
    }
    else
    {   
        Node *temp = new Node;
        temp->data = x;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    cout << "Successfully inserted " << x << endl;

}

void LinkedList::insert(int index, int x)
{
    if (index < 0 || index > length()) //out of bound
    {
        cout << "Invalid index! ";
        return;
    }

    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;

    if (index == 0)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        Node *t;
        t = head;
        for (int i = 1; i < index; i++) 
        {
            t = t->next; // get to the index
        }

        temp->next = t->next;
        t->next = temp;
        
    }
}

void LinkedList::del(int index)
{
    if (index < 1 || index > length())
    {
        cout << "Invalid index!!";
        return;
    }
    
    if (index == 1)
    {
        Node *t = head;
        head = head->next;
        delete t;
    }
    else
    {
        Node *current = head;
        Node *prev = NULL;
        for (int i = 1; i < index; i++)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        delete(current);
    }
    
    cout << "Successfully deleted element at index " << index << endl;
}


int LinkedList::length()
{
    Node *p = head;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

bool LinkedList::isSorted()
{
    int min = INT_MIN;
    Node *t = head;
    while (t)
    {
        if (t->data < min)
        return false;
        else
        {
            min = t->data;
            t = t->next;
        }
    }
    return true;
}

void LinkedList::removeDuplicate()
{
    if (!isSorted())
    {
        cout << "Cannot remove duplicates if the list is not sorted !! \n";
        return;
    }

    Node *first = head;
    Node *second = first->next;

    while (second != NULL)
    {
        if (second->data == first->data)
        {
            first->next = second->next;
            delete second;
            second = first->next;
        }
        else
        {
            first = second;
            second = second->next;
        }
    }
    cout << "Successfully removed duplicates \n";
}

void LinkedList :: reverseElements()
{
    Node *t = head;
    int n = length();
    int temp[n];
    int i = 0;

    while (t)
    {
        temp[i] = t->data;
        t = t->next;
        i++;
    }

    Node *p = head;
    for (int j = i-1; j >= 0; j--)
    {
        p->data = temp[j];
        p = p->next;
    }
}

void LinkedList::reverseLinks(Node *q , Node *p) //recursive
{
    if(p == NULL)
    {
        head = q;
    }
    else
    {
        reverseLinks(p, p->next);
        p -> next = q;
    }
}

void LinkedList::reverseLinks2() // sliding window
{
    Node *prev = NULL;
    Node *curr = NULL;
    Node *last = head;

    while (last)
    {
        prev = curr;
        curr = last;
        last = last->next;
        curr->next = prev;
    }
    head = curr;
}

void LinkedList::mergeLinkedList(Node *first, Node *second)
{
    Node *third = NULL; // starting address of the merged list
    Node *last = NULL; // tail pointer

    if (first->data < second->data)
    {
        third = last = first;
        first = first->next; // move ahead
        third->next = NULL;
    } 
    else
    {
        third = last = second;
        second = second->next;
        third->next = NULL;
    }

    while (first && second) //until either reach null
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next= second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }

    if (first) last->next = first; //copy the remaining elements;
    if (second) last->next = second; 

    head = third;
    tail = last;
}

bool LinkedList::isLoop()
{
    Node *p;
    Node *q;
    p = q = head;

    do
    {
        p = p->next;
        q = q->next;
        q = q!=NULL ? q->next : q;
    } while (p && q || p!=q);

    if (p == q)
    return true;
    else
    return false;
    
}


int main()
{
    LinkedList a(3);
    a.insert(19);
    a.insert(29);
    a.display();
    
}
