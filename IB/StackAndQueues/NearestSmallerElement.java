public class Solution {
    public ArrayList<Integer> prevSmaller(ArrayList<Integer> A) {
        
        ArrayList<Integer> res = new ArrayList<>();
        Deque<Integer> stack = new ArrayDeque<>();
        
        int min=A.get(0);
        res.add(-1);
        stack.addFirst(min);
        
        for(int i=1;i<A.size();i++){
            while(!stack.isEmpty() && stack.peekFirst()>=A.get(i)){
                stack.removeFirst();
            }
            if(stack.isEmpty()){
                res.add(-1);
                
            } else {
                res.add(stack.peekFirst());
            }
            stack.addFirst(A.get(i));
        }
        
        return res;
    }
}

