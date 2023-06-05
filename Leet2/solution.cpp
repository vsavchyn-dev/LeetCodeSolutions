#include <iostream>
#include <algorithm>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* start = new ListNode{};
        ListNode* tmp = start;

        int sum = 0;

        while (l1 || l2 || sum) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            tmp->next = new ListNode(sum % 10);
            tmp = tmp->next;

            sum /= 10;
        }

        return start->next;
    }
};  