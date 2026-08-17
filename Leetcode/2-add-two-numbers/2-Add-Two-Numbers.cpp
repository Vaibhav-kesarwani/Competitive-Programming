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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        int add_one = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                tail->next = new ListNode((l2->val + add_one) % 10);
                tail = tail->next;
                add_one = (l2->val + add_one) / 10;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                tail->next = new ListNode((l1->val + add_one) % 10);
                tail = tail->next;
                add_one = (l1->val + add_one) / 10;
                l1 = l1->next;
            } else {
                tail->next = new ListNode((l1->val + l2->val + add_one) % 10);
                tail = tail->next;
                add_one = (l1->val + l2->val + add_one) / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if (add_one) {
            tail->next = new ListNode(add_one);
        }
        return dummy.next;
    }
};