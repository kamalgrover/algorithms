#include <iostream>
#include <vector>
using namespace std;
class ListNode
{
public:
    int val = 0;
    ListNode *next = NULL;
};

class LinkedList
{
public:
    ListNode *head = NULL;
    void createList(vector<int> input);
    ListNode *createNode(int num);
    void printList();
    void printList(ListNode *cur);
    void reverseList();
    ListNode *reverseList(ListNode *cur, int k);
    void reverseList(int m, int n);
};
void LinkedList::printList(ListNode *cur)
{
    for (ListNode *it = cur; it; it = it->next)
    {
        cout << it->val << " ";
    }
    cout << endl;
}
ListNode *LinkedList::createNode(int num)
{
    ListNode *node = new ListNode();
    node->val = num;
    node->next = NULL;
    return node;
}
void LinkedList::createList(vector<int> input)
{
    if (input.size() == 0)
        return;
    ListNode *cur = createNode(input[0]);
    head = cur;
    for (int i = 1; i < input.size(); i++)
    {
        cur->next = createNode(input[i]);
        cur = cur->next;
    }
}
void LinkedList::printList()
{
    for (ListNode *cur = head; cur; cur = cur->next)
    {
        cout << cur->val << " ";
    }
    cout << endl;
}
void LinkedList::reverseList()
{
    //empty list
    if (head == NULL)
        return;
    //list with one node
    if (head->next == NULL)
        return;
    //list with 2 or more nodes
    ListNode *prev = NULL;
    ListNode *cur = head;
    ListNode *fwd = cur->next;
    // NULL  1 -> 2 -> NULL
    // prev cur  fwd
    do
    {
        cur->next = prev;
        prev = cur;
        cur = fwd;
        fwd = fwd->next;
        // NULL <- 1    2 -> NULL
        //
        //       prev   cur   fwd
    } while (fwd);
    cur->next = prev;
    head = cur;
}

ListNode *LinkedList::reverseList(ListNode *cur, int k)
{
    ListNode *st = cur;
    if (cur == NULL || cur->next == NULL || k < 1)
        return cur;
    // now we have atleast 2 nodes
    ListNode *fwd = cur->next;
    while (fwd and k--)
    {
        ListNode *temp = fwd->next;
        fwd->next = cur;
        cur = fwd;
        fwd = temp;
    }
    st->next = fwd;
    return cur;
}
void LinkedList::reverseList(int m, int n)
{
    if (m <= 0 || m >= n)
        return;
    ListNode *cur = head;
    ListNode *prev = NULL;
    // number of links traversed to reach the mth node is m - 1
    for (int i = 0; i < m - 1; i++)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev)
        prev->next = reverseList(cur, n - m);
    else
    {
        head = reverseList(cur, n - m);
    }
}
// 5
// 1 2 3 4 5
int main()
{
    // int m, n;
    // cin >> m >> n;
    // int N;
    // cin >> N;
    // vector<int> input;
    // int number;
    // while (N--)
    // {
    //     cin >> number;
    //     input.push_back(number);
    // }
    LinkedList ll;
    ll.createList({1, 2, 3, 4, 5, 6});
    ll.reverseList(4,6);
    ll.printList();
    return 0;
}