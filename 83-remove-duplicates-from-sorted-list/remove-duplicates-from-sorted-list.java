/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        
        if(head == null)
            return head;

        ListNode temp = head;
        ListNode prev = null;

        while(temp!=null)
        {
            if(temp==head)
            {
                prev = temp;
                temp = temp.next;
            }
            else
            {
                if(prev.val == temp.val)
                {
                    prev.next = temp.next;
                    temp = prev.next;
                }
                else
                {
                    prev = temp;
                    temp = temp.next;
                }
            }
        }

        return head;
    }
}