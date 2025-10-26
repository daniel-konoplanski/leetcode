/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (!head->next) return nullptr;

        auto left = head;
        auto right = head;

        // Move rigth to position N
        for (int i{0}; i < n; ++i)
        {
            if (!right->next) return head->next;
            right = right->next;
        }

        // Move right to the last element in list
        while (right->next)
        {
            left = left->next;
            right = right->next;
        }

        auto current = left->next;
        left->next = current->next ? current->next : nullptr;

        return head;
    }
};