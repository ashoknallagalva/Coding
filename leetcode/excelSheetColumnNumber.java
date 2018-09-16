class Solution {
    public int titleToNumber(String s) {    
        int res=0;
        int len = s.length()-1;
        int pow = 1;
        for(int i=s.length()-1;i>=0;i--){
            char c = s.charAt(i);
            res+=((c-'A'+1)*pow);
            pow = pow*26;
        }
        
        return res;
    }
}
