public class Solution {
    public ArrayList<ArrayList<Integer>> subsets(ArrayList<Integer> A) {
        
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        res.add(new ArrayList<>());
        
        A.sort((a,b) -> a-b);
        if(A.size()==0){
            return res;
        }
        
        powerSet(A,0,new ArrayList<>(),res);
        
        return res;
    }
    
    public void powerSet(ArrayList<Integer> A,int index,ArrayList<Integer> temp, ArrayList<ArrayList<Integer>> res){
        
        for(int i=index;i<A.size();i++){
            
            temp.add(A.get(i));
            res.add(new ArrayList<>(temp));
            powerSet(A,i+1,temp,res);
            temp.remove(temp.size()-1);
        }
    }
}

