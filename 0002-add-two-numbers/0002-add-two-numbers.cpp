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
        ListNode* temp = new ListNode(0);
        ListNode* curr = temp;
        int n = 0;

        while (l1 != nullptr || l2 != nullptr || n != 0){
            int count = n;

            if (l1 != nullptr){
                count += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr){
                count += l2->val;
                l2 = l2->next;
            }

            n = count/10;
            curr->next = new ListNode(count % 10);
            curr = curr->next;
        }

        return temp->next;
    }
};