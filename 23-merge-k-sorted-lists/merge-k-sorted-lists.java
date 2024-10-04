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
    public ListNode mergeKLists(ListNode[] lists) {

        if(lists.length==0)
            return null;
        else if(lists.length==1)
            return lists[0];

        ListNode dummy = new ListNode(0);
        ListNode temp = dummy;
        ListNode p1 = lists[0];
        for(int i=1;i<lists.length;i++)
        {

            ListNode p2 = lists[i];
            temp = dummy;


            while(p1!=null && p2!=null)
            {
                if(p1.val<=p2.val)
                {
                    temp.next = p1;
                    temp = p1;
                    p1 = p1.next;
                }
                else 
                {
                    temp.next = p2;
                    temp = p2;
                    p2 = p2.next;
                }

                
            }

            if(p1!=null)
                temp.next = p1;
            else
                temp.next = p2;

            p1 = dummy.next;
            
        }
            

        return dummy.next;

    }
}