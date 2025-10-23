class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: if head is null or has one element
        if (!head || !head->next) return head;

        // Step 1: Split the list into two halves
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect the two halves
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // Step 2: Sort each half
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Step 3: Merge sorted halves
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = (l1 ? l1 : l2);
        return dummy.next;
    }
};
