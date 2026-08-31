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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head->next == nullptr) {
            return {-1, -1};
        }
        
        ListNode* slow = head;
        head = head->next;
        ListNode* fast = head->next;
        int i = 2;
        int minn = INT_MAX;
        int maxx = -1;
        vector<int> nodess;

        while (head->next != nullptr) {
            if (head->val > slow->val && head->val > fast->val) {
                nodess.push_back(i);
            } 
            
            if (head->val < slow->val && head->val < fast->val) {
                nodess.push_back(i);
            }

            slow = slow->next;
            head = head->next;
            fast = fast->next;
            i++;
        }   

        for (auto p: nodess) {
            cout << p << endl;
        }

        if (nodess.size() < 2) {
            return {-1, -1};
        }

        for (int i = 1; i < nodess.size(); i++) {
            minn = min(minn, nodess[i] - nodess[i-1]);
        }

        maxx = nodess[nodess.size() - 1] - nodess[0];
    
        return {minn, maxx};
    }
};