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
    public ListNode swapNodes(ListNode head, int k) {

        ListNode temp1 = head;
        ListNode temp2 = head;
        ListNode temp = head;

        int index = 1;
        while(temp != null)
        {
            if(index == k)
                temp2 = temp;
        
            if(index>k)
            {
                temp1 = temp1.next;
            }
            temp = temp.next;
            index++;
        }

        int temp_val = temp1.val;
        temp1.val = temp2.val;
        temp2.val = temp_val;
        return head;
    }
}