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

        auto listSize = getListSize(head);
        auto indexToRemove = listSize - n;

        if (!indexToRemove) return head->next;

        auto prev = head;

        for (int i{ 1 }; i < indexToRemove; ++i)
        {
            prev = prev->next;
        }

        auto current = prev->next;

        prev->next = current->next ? current->next : nullptr;

        return head;
    }

private:
    int getListSize(ListNode* head)
    {
        int result{0};

        while (head)
        {
            ++result;
            head = head->next;
        }

        return result;
    }
};