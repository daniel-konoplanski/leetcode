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

#include <cstddef>
#include <iostream>
#include <utility>

struct ListNode
{
    int       val;
    ListNode* next;

    ListNode()
        : val(0)
        , next(nullptr)
    {
    }

    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }

    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

class Solution
{
private:
    std::size_t getSize(ListNode* head)
    {
        std::size_t result{1U};

        while (head->next)
        {
            ++result;
            head = head->next;
        }

        return result;
    }

public:
    ListNode* deleteMiddle(ListNode* head)
    {
        ListNode* middle = head;
        ListNode* prev = nullptr;

        std::size_t middle_idx{getSize(head) / 2U};
        std::size_t idx{0};

        while (idx < middle_idx)
        {
            prev = middle;
            middle = middle->next;
            ++idx;
        }

        if (!prev) return nullptr;
        else if (!middle->next) prev->next = nullptr;

        prev->next = middle->next;

        return head;
    }
};
