#include <iostream>
using namespace std;

class Stack
{
public:
    Stack(int cap);
    bool push(int a);
    int pop();
    int top();
    bool isEmpty();

private:
    int *m_s;  // will hold the stack
    int m_top; // will point to the top element of the stack
    int m_cap; // will hold the capacity of the stack after initialization of the instance
};

Stack::Stack(int cap)
{
    m_s = new int[cap];
    m_top = -1;
    m_cap = cap;
}
bool Stack::isEmpty()
{
    if (m_top == -1)
        return true;
    return false;
}
int Stack::top()
{
    if (isEmpty())
    {
        return INT_MIN;
    }
    return m_s[m_top];
}
int Stack::pop()
{
    if (isEmpty())
    {
        return INT_MIN;
    }
    int reVal = top();
    m_top--;
    return reVal;
}
bool Stack::push(int a)
{
    if (m_top == m_cap -1)
        return false;
    m_s[++m_top]=a;
    return true;
}



int main()
{ //This is the driver program
    cout << "Hello, World!" << endl;
    Stack stack(4);
    cout << stack.isEmpty() << endl;
    stack.push (1);
    cout << stack.isEmpty() << endl;
    stack.push (2);
    stack.push (3);
    stack.push (4);
    stack.push (5);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.isEmpty() << endl;
    return 0;
}
