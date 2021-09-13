#include <iostream>
#include <cstring>
using namespace std;

int out_pre(char x);
int in_pre(char x);
bool is_operand(char x);

struct node
{
    int data;
    struct node * next;
};

template <class T>
class Stack
{
    node *top;
    public:
    Stack()
    {
        top = NULL;
    }
    void push(T x)
    {
        node *t = new node;
        t->data = x;
        t->next = top;
        top = t;
    }
    void pop()
    {
        node *t = top;
        top = top->next;
        delete t;
    }

    T pop_character()
    {
        node *t = top;
        top = top->next;
        T a = t->data;
        delete t;
        return a;
    }

    bool isEmpty()
    {
        return top ?false : true;
    }

    T StackTop()
    {
        if (top == NULL)
        return -1;
        else
        return top->data;
    }
};

char *postfix(char infix[])
{
    char *post = new char[strlen(infix)];
    Stack <char> s;
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (is_operand(infix[i]))
        post[j++] = infix[i++];
        else
        {
            if(out_pre(infix[i]) > in_pre(s.StackTop()) )
            {
                s.push(infix[i++]);
            }
            else if (out_pre(infix[i]) == in_pre(s.StackTop()))
            {
                s.pop();
                i++;
            }
            else
            {
                post[j++] = s.pop_character();
            }
        }
    }
    while (!s.isEmpty())
    {
        post[j++] = s.pop_character();
    }
    post[j] = '\0';
    return post;
}

bool is_operand(char x)
{
    if (x == ')' || x == '(' || x == '+' || x == '-' ||x == '*' ||x == '/' ||x == '^')
    return false;
    else
    return true;
}

int out_pre(char x)
{
    if (x == '+' || x == '-')
    return 1;
    if (x == '*' || x == '/')
    return 3;
    if (x == '^')
    return 6;
    if (x == '(')
    return 7;
    if (x == ')')
    return 0;
    else
    return -1;
}

int in_pre(char x)
{
    if (x == '+' || x == '-')
    return 2;
    if (x == '*' || x == '/')
    return 4;
    if (x == '^')
    return 5;
    if (x == '(')
    return 0;
    else
    return -1;
}

int evaluate (char *postfix)
{
    Stack <int> s;
    int x1,x2;
    int result;
    int i = 0;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (is_operand(postfix[i]))
        {
            s.push(postfix[i] - '0');
        }
        else
        {
            x2 = s.pop_character();
            x1 = s.pop_character();
            switch(postfix[i])
            {
                case '+': result = x1+x2; break;
                case '-': result = x1-x2; break;
                case '*': result = x1*x2; break;
                case '/': result = x1/x2; break;
            }
            s.push(result);
        }
    }

    return s.pop_character();
}

int main()
{
    char infix[] = "2+3*4-8/2";
    char *pp = postfix(infix);
    cout << pp;
    cout << endl;
    cout << evaluate(pp);
    
}
