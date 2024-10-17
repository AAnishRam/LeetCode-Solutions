//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class Main {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = sc.nextLine();
            Scanner ss = new Scanner(input);

            while (ss.hasNextInt()) {
                arr.add(ss.nextInt());
            }

            Node head = new Node(arr.get(0));
            Node tail = head;

            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }

            Solution ob = new Solution();
            Node[] result = ob.alternatingSplitList(head);
            printList(result[0]);
            printList(result[1]);
        }

        sc.close();
    }
}

// } Driver Code Ends


// User function Template for Java
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    // Function to append a new node with newData at the end of a linked list
    Node[] alternatingSplitList(Node head) {
        
        ArrayList<Integer> l = new ArrayList<>();
        
        Node temp = head;
        
        while(temp!=null)
        {
            l.add(temp.data);
            temp = temp.next;
        }
        
        
        
        Node t1 = new Node(l.get(0));
        Node t2 = new Node(l.get(1));
        
        
        Node  temp1 = t1;
        Node  temp2 = t2;
        
        for(int i = 2; i<l.size();i++)
        {
            if(i%2==0)
            {
                temp1.next = new Node(l.get(i));
                temp1 = temp1.next;
            }
            else
            {
                temp2.next = new Node(l.get(i));
                temp2 = temp2.next;
            }
        }
        
        
        Node[] ans = new Node[2];
        ans[0] = t1;
        ans[1] = t2;
        
       // System.out.println(l);
        
        return ans;
    }
}
