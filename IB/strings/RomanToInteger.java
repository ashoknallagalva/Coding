
public class Solution {
    public int romanToInt(String A) {
        
        Map<Character,Integer> romanNumerals = new HashMap<>();
        
        romanNumerals.put('I',1);
        romanNumerals.put('V',5);
        romanNumerals.put('X',10);
        romanNumerals.put('L',50);
        romanNumerals.put('C',100);
        romanNumerals.put('D',500);
        romanNumerals.put('M',1000);
        
        int res = romanNumerals.get(A.charAt(A.length()-1));
        int last = res;
        for(int i=A.length()-2;i>=0;i--){
            int val = romanNumerals.get(A.charAt(i));
            if(last>val){
                res-=val;
            } else {
                res+=val;
            }
            last = val;
        }
        
        return res;
    }
}

