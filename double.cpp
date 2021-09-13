#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

class Double 
{
    node *head;
    node *tail;

    public:
    Double()
    {
        head = NULL;
    }
    
    Double (int n)
    {
        if (n < 0)
        return;

        node *temp = new node;
        cout << "Enter the 1 element: ";
        cin >> temp->data;
        temp->next = NULL;
        temp->prev = NULL;
        head = tail = temp;

        for (int i = 1; i < n; i++)
        {
            temp = new node;
            cout << "Enter the " << i+1 << " element: ";
            cin >> temp->data;
            temp->next = NULL;
            temp->prev = tail;
            tail->next = temp;
            tail = temp; 
        }

    }

    void display()
    {
        node *p = head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void reverseDisplay()
    {
        node *p = tail;
        while (p)
        {
            cout << p->data<<" ";
            p = p->prev;
        }
        cout << endl;
    }

    int length ()
    {
        int count = 0;
        node *p = head;
        while (p)
        {
            count++;
            p = p->next;
        }
        return count;

    }

    void insert(int index, int x)
    {
        if (index < 0 || index > length())
        return;
        
        node *temp;

        if (index == 0)
        {
            if (head == NULL) //list is empty
            {   
                temp = new node;
                temp->data = x;
                temp->next = NULL;
                temp->prev = NULL;
                head = tail = temp;
            }
            else
            {
                temp = new node;
                temp->data = x;
                temp->next = head;
                temp->prev = NULL;
                head->prev = temp;
                head = temp;
            }
        }
        else
        {
            temp = new node;
            node *pre = head; 
            temp->data = x;
            for (int i = 1; i < index; i++) 
            {
                pre = pre->next;
            }
            temp->next = pre->next;
            temp->prev = pre;
            
            if (pre->next) // if it is not the last element
            {
                pre->next->prev = temp;
            }
            pre->next = temp;
        }
    }

    void del (int index)
    {
        if (index == 0)
        {    if (head->next)
            {
                node *p = head;
                head = head->next;
                head->prev = NULL;
                delete p;
            }
            else
            {
                head = NULL;
            }
            
        }
        else
        {
            node *p = head;
            for (int i = 1; i < index; i++)
            {
                p = p->next;
            }
            p->prev->next = p->next;
            if (p->next)
            {
                p->next->prev = p->prev;
            }            
            delete p;
        }   
    }

    void reverse()
    {
        node *p = head;
        while (p)
        {
            node* temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = p->prev;
            
            if (p != NULL && p->next == NULL) // if it is the last node
            {
                head = p;
            }
        }
    }
};


int main()
{
    Double a;
    a.insert(0,14);
    a.insert(1,15);
    a.insert(2,16);

    a.reverse();
    a.display();

}