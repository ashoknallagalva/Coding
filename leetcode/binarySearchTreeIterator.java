/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {
    
    private Deque<TreeNode> stack;

    public BSTIterator(TreeNode root) {
        stack = new LinkedList<>();
        while(root!=null){
            stack.addFirst(root);
            root=root.left;
        }
        
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        
        return !stack.isEmpty();
    }

    /** @return the next smallest number */
    public int next() {
        
        if(!stack.isEmpty()){
            TreeNode top = stack.removeFirst();
            traverseTree(top.right);
            return top.val;
        }
        
        return -1;
        
    }
    
    private void traverseTree(TreeNode root){
         while(root!=null){
            stack.addFirst(root);
            root=root.left;
         }
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */
