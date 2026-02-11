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
class Solution{
    public:
    ListNode* checkKNodes(ListNode* node, int k) {
        for (int i = 0; i < k; i++) {
            if (!node) return nullptr;
            node = node->next;
        }
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {   
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        while (true) {
            ListNode* kthNode = prevGroupEnd;
            for (int i = 0; i < k && kthNode; i++) {
                kthNode = kthNode->next;
            }
            if (!kthNode) break;
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kthNode->next;

            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;
            while (curr != nextGroupStart) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            prevGroupEnd->next = kthNode;
            prevGroupEnd = groupStart;
        }
        return dummy->next;
    }
    
};