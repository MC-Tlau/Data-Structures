#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

class CCDoubly //cicular doubly linked list
{
    node *head;

    public:
    CCDoubly()
    {
        head = NULL;
    }
    void insert(int x);
    void del(int index);
    void display();
    int length();

};

void CCDoubly::insert(int x)
{
    node * temp;

    if (head == NULL)
    {
        head = new node;
        head->data = x;
        head->prev = head;
        head->next = head;
    }
    else
    {
        node *t = head;
        do
        {
            t = t->next;
        } while (t ->next != head); // go to the last node
        
        temp = new node;
        temp->data = x;
        temp->next = head;
        temp->prev = t;
        t->next = temp;
        head->prev = temp;
    }
}

void CCDoubly::display()
{
    node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while(p != head);
    cout << endl;
}

int CCDoubly::length()
{
    int count = 0;
    node *p = head;
    do
    {
        count ++;
        p = p->next;
    } while (p!=head);
    
    return count;
}

void CCDoubly::del(int index)
{
    if (index < 0 || index > length())
    {
        cout << "INVALID INDEX!!";
        return;
    }
    
    if (index == 0)
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            node *temp = head;
            head = head->next;
            head->prev = temp->prev;
            temp->prev->next = head;
            delete temp;
        }
    }
    else
    {
        node *t = head;
        for (int i = 0; i < index ; i++)
        {
            t = t->next;
        }
        t->prev->next = t->next;
        t->next->prev = t->prev;
        delete t;
    }
}

int main()
{
    CCDoubly a;
    a.insert(3);
    a.insert(5);
    a.insert(6);
    a.insert(2);
    a.insert(1);
    a.del(4);

    a.display();
    cout << a.length();
}
