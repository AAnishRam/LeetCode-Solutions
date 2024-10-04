/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {

        if(head==null)
        {
            return null;
        }

        Node temp = head;
        HashMap<Node,Node> hm = new HashMap();

        Node deepCopy =  new Node(head.val);
        Node temp_deepCopy = deepCopy;

        hm.put(temp,temp_deepCopy);


        
        while(temp.next!=null)
        {
            temp_deepCopy.next = new Node(temp.next.val);

            hm.put(temp.next,temp_deepCopy.next);

            temp_deepCopy = temp_deepCopy.next;
            temp = temp.next;

        }
        
        temp_deepCopy = deepCopy;
        temp = head;

        while(temp_deepCopy != null)
        {
            temp_deepCopy.random = hm.get(temp.random);

            temp_deepCopy = temp_deepCopy.next;
            temp = temp.next;
        }

        return deepCopy;

    }
}