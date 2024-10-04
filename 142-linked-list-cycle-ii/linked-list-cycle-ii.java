/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {

        if(head==null)
            return head;

        ListNode temp = head;
        HashMap<ListNode,Integer> hm = new HashMap<>();

        while(temp.next!=null)
        {

            if(hm.get(temp)!=null)
            {
                return temp;
            }
        
            hm.put(temp,0);
            temp = temp.next;

        }
        return null;
    }
}