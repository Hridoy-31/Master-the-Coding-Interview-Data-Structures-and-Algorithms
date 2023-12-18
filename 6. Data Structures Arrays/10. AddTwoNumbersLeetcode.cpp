#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printlist(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Optimal Approach: (The only approach it has)
// Time Complexity: O(max (m,n)) where, m is the size of l1 and n is the size of l2.
//                  because, the while loop will continue running untill both l1 and
//                  l2 are exhausted.
// Space Complexity: O(max(m,n)) where, m is the size of l1 and n is the size of l2.
//                   This space complexity comes from the "result" linked list. Because
//                   it is adding nodes as the while loop traverses node by node in l1 and l2.

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummyhead = new ListNode();
    ListNode *temp = dummyhead;
    int carry = 0;

    while (l1 != NULL or l2 != NULL or carry != 0)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        sum = sum + carry;
        carry = sum / 10;

        ListNode *result = new ListNode(sum % 10);
        temp->next = result;
        temp = temp->next;
    }
    return dummyhead->next;
}

int main()
{
    // ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    // ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    // ListNode *l1 = new ListNode();
    // ListNode *l2 = new ListNode();

    ListNode *l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode *l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

    ListNode *result = addTwoNumbers(l1, l2);
    printlist(result);
    return 0;
}