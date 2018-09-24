class Solution {
    public String addBinary(String a, String b) {
       
        StringBuilder ans = new StringBuilder();
        int sum = 0;
        
        int i=a.length()-1,j=b.length()-1;
        for(;i>=0 || j>=0;j--,i--){
            
            sum+= (i>=0) ? a.charAt(i)-'0' : 0;
            sum+= (j>=0) ? b.charAt(j)-'0' : 0;
            
            ans.append((char)(sum%2 + '0'));
            sum = sum/2;
        }
        
        if(sum==1){
            ans.append('1');
        }
        
        return ans.reverse().toString();
        
    }
    
   
}
