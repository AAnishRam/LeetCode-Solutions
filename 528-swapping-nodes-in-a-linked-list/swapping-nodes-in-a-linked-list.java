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
        ListNode ref1 = head;
        ListNode ref2 = head;

        int index = 1;
        while(index != k)
        {
            ref1 = ref1.next;
            index++;
        }

        int count = 0;
        ListNode temp = head;
        while(temp!=null)
        {
            temp = temp.next;
            count++;
        }
        
        k = count-k+1;
        index = 1;
        while(index != k)
        {
            ref2 = ref2.next;
            index++;
        }

        int temp_int = ref1.val;
        ref1.val = ref2.val;
        ref2.val = temp_int;

        System.out.println(ref1.val);
        return head;
        
    }
}