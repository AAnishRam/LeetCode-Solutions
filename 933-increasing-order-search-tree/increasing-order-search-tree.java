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

    public void inorder(TreeNode root, List<Integer>l)
    {
        if(root==null)return;
        inorder(root.left,l);
        l.add(root.val);
        inorder(root.right,l);
    }

    public TreeNode increasingBST(TreeNode root) {
        List<Integer> l = new ArrayList();

        inorder(root,l);

        TreeNode ans = new TreeNode(l.get(0));

        TreeNode temp = ans;

        for(var i:l)
        {
            if(i!=l.get(0))
            {
                temp.right = new TreeNode(i);
                temp = temp.right; 
            }
        }

        System.out.println(l);
        return ans;
    }
}