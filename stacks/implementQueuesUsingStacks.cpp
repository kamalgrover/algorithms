#include <iostream>
#include <stack>
using namespace std;

class Queue
{
public:
    bool enqueue(int a);
    int dequeue();
    bool empty();
    int size();

private:
    int m_cap;
    stack<int> m_main_stack;
    stack<int> m_aux_stack;
};

bool Queue::empty()
{
    return m_main_stack.empty();
}
int Queue::size()
{
    return m_main_stack.size();
}
bool Queue::enqueue(int a) //make enqueue expensive
{
    //newest element will go to the bottom of the main stack.
    while (!m_main_stack.empty())
    {
        int number = m_main_stack.top();
        m_aux_stack.push(number);
        m_main_stack.pop();
    }
    m_main_stack.push(a);
    while (!m_aux_stack.empty())
    {
        int number = m_aux_stack.top();
        m_main_stack.push(number);
        m_aux_stack.pop();
    }
    return true;
}
int Queue::dequeue()
{
    if (!empty())
    {
        int number = m_main_stack.top();
        m_main_stack.pop();
        return number;
    }
    return INT_MIN;
}

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}