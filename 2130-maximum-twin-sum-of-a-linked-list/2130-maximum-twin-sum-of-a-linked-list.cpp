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
    int pairSum(ListNode* head) {
        ListNode* tail = head;
        stack<ListNode*> stck;

        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
            stck.push(curr);
        }
    
        // while (!stck.empty()) {
        //     debug(stck.top()->val);
        //     stck.pop();
        // }

        int maxx = INT_MIN;
        while (!stck.empty()) {
            int temp = head->val + stck.top()->val;
            head = head->next;
            stck.pop();
            maxx = max(maxx, temp);
        }

        return maxx;
    }
};