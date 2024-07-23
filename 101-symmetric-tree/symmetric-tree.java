/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        Queue<TreeNode> q = new LinkedList();

        q.offer(root.left);
        q.offer(root.right);

        while(!q.isEmpty())
        {
            TreeNode left = q.poll();
            TreeNode right = q.poll();

            if(left==null  && right==null)
                    continue;
                    
            if(left==null  || right==null)
                return false;

            if(left.val!=right.val)
                return false;


            if(left.left!=null || right.right!=null)
            {
                q.offer(left.left);
                q.offer(right.right);
            }

            if(left.right!=null || right.left!=null)
            {
                q.offer(left.right);
                q.offer(right.left);
            }

            System.out.println(left.val + " " + right.val + " ");
            
            
            
        }

        return true;
    }
}