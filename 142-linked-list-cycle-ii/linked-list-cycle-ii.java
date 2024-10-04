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
            
        boolean flag = true;
        ListNode temp = head;
        HashMap<ListNode,Integer> hm = new HashMap<>();

        while(flag && temp.next!=null)
        {
            if(temp.next == null)
                flag = false;

            if(hm.get(temp)!=null)
            {
                flag = false;
                return temp;
            }
        
            hm.put(temp,hm.getOrDefault(temp,0)+1);
            temp = temp.next;

        }
        return null;
    }
}