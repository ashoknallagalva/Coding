/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    class IntWraper{
        int val;
        public IntWraper(int val){
            this.val = val;
        }
    }
    
    public int diameterOfBinaryTree(TreeNode root) {
        IntWraper value = new IntWraper(1);
        depthOfTree(root,value);
        return value.val-1;
    }
    
    private int depthOfTree(TreeNode root,IntWraper ans){
        if(root==null){
            return 0;
        }
        
        int left = depthOfTree(root.left,ans);
        int right = depthOfTree(root.right,ans);
        ans.val = Math.max(ans.val,left+right+1);
        return 1+Math.max(left,right);
    }
    
   
}
