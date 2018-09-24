class Solution {
    public boolean validPalindrome(String s) {
        
        boolean isDeleted = false;
        int start = 0,end = s.length()-1;
        
        while(start<=end){
           if(s.charAt(start)!=s.charAt(end)){
               break;
           }
            start++;
            end--;
        }
        
        if(start<=end && s.charAt(start)!=s.charAt(end)){
           return checkPolindromHelper(s,start+1,end) || checkPolindromHelper(s,start,end-1); 
        }
        
        return true;
        
    }
    
    private boolean checkPolindromHelper(String s, int start,int end){
        while(start<=end){
            if(s.charAt(start)!=s.charAt(end)){
                return false;
            }
            start++;
            end --;
        }
        
        return true;
    }
}
