/*
Problem: Linked List Cycle II
Platform: LeetCode

Approach:
- Use Floyd’s Cycle Detection Algorithm
- Step 1: Detect cycle using slow & fast pointers
- Step 2: Move one pointer to head
- Step 3: Move both one step at a time
- Meeting point = cycle start

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Detect cycle
        while(fast != NULL && fast->next != NULL){

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){

                // Find cycle start
                ListNode* temp = head;

                while(temp != slow){
                    temp = temp->next;
                    slow = slow->next;
                }

                return temp;
            }
        }

        return NULL;
    }
};
