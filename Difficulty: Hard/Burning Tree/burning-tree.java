//{ Driver Code Starts
//Initial Template for Java


import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;

class Node {
	int data;
	Node left;
	Node right;

	Node(int data) {
		this.data = data;
		left = null;
		right = null;
	}
}

class GfG {

	static Node buildTree(String str) {

		if (str.length() == 0 || str.charAt(0) == 'N') {
			return null;
		}

		String ip[] = str.split(" ");
		// Create the root of the tree
		Node root = new Node(Integer.parseInt(ip[0]));
		// Push the root to the queue

		Queue<Node> queue = new LinkedList<>();

		queue.add(root);
		// Starting from the second element

		int i = 1;
		while (queue.size() > 0 && i < ip.length) {

			// Get and remove the front of the queue
			Node currNode = queue.peek();
			queue.remove();

			// Get the current node's value from the string
			String currVal = ip[i];

			// If the left child is not null
			if (!currVal.equals("N")) {

				// Create the left child for the current node
				currNode.left = new Node(Integer.parseInt(currVal));
				// Push it to the queue
				queue.add(currNode.left);
			}

			// For the right child
			i++;
			if (i >= ip.length)
				break;

			currVal = ip[i];

			// If the right child is not null
			if (!currVal.equals("N")) {

				// Create the right child for the current node
				currNode.right = new Node(Integer.parseInt(currVal));

				// Push it to the queue
				queue.add(currNode.right);
			}
			i++;
		}

		return root;
	}

	static void printInorder(Node root) {
		if (root == null)
			return;

		printInorder(root.left);
		System.out.print(root.data + " ");

		printInorder(root.right);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());

		while (t > 0) {
			String s = br.readLine();
			int target = Integer.parseInt(br.readLine());
			Node root = buildTree(s);

			Solution g = new Solution();
			System.out.println(g.minTime(root, target));
			t--;

		}
	}
}



// } Driver Code Ends


//User function Template for Java
class Index {
    int i;
    public Index() {
        i = 0;
    }
}
class Solution {
    static int BFS(List<HashSet<Integer>> adj,int src) {
        Queue<Integer> queue = new ArrayDeque<>();
        boolean[] visited = new boolean[adj.size()];
        int count = 0;
        
        queue.offer(src);
        visited[src] = true;
        
        while(!queue.isEmpty()) {
            int size = queue.size();
            count++;
            for(int i = 0; i < size; i++) {
                int parent = queue.poll();
                
                for(int v : adj.get(parent))
                    if(!visited[v]) {
                        visited[v] = true;
                        queue.offer(v);
                    }
            }
        }
        return count - 1;
    }
    
    static int countNodes(Node root) {
        if(root == null) return 0;
        int countLeft = countNodes(root.left);
        int countRight = countNodes(root.right);
        return countLeft + countRight + 1;
    }
    
    static Integer createGraph(Node root,List<HashSet<Integer>> adj,HashMap<Integer,Integer> map,Index ptr) {
        if(root == null) return null;
        if(root.left == null && root.right == null) return root.data;
        int index = root.data;
        Integer left = createGraph(root.left,adj,map,ptr);
        Integer right = createGraph(root.right,adj,map,ptr);
        if(!map.containsKey(index)) map.put(index,ptr.i++);
        if(left != null && !map.containsKey(left)) map.put(left,ptr.i++);
        if(right != null && !map.containsKey(right)) map.put(right,ptr.i++);
        if(left != null) { 
            adj.get(map.get(index)).add(map.get(left)); 
            adj.get(map.get(left)).add(map.get(index));
        }
        if(right != null) {
            adj.get(map.get(index)).add(map.get(right));
            adj.get(map.get(right)).add(map.get(index));
        }
        return root.data;
    }

    public static int minTime(Node root, int target) {
        if(root.left == null && root.right == null) return 0;
        List<HashSet<Integer>> adj = new ArrayList<>();
        HashMap<Integer,Integer> map = new HashMap<>();
        int totalNodes = 0;
        totalNodes = countNodes(root); 
        
        for(int i = 0; i <= totalNodes + 20; i++)
            adj.add(new HashSet<>());
    
        createGraph(root,adj,map,new Index());
        return BFS(adj,map.get(target));
    }
}


   