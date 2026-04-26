class Solution {
public:
    bool isPalindrome(ListNode* head){
        ListNode *fast = head, *slow = head;

        while (fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode *prev = nullptr;
        while (slow){
            ListNode *tmp = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = tmp;
        }

        ListNode *left = head, *right = prev;
        while (right){
            if (left -> val != right -> val) return false;
            left = left -> next;
            right = right -> next;
        }
        return true;
    }
};