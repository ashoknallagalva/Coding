class Solution {
    public int romanToInt(String s) {
        
        Map<Character, Integer> romans = new HashMap<>();
        romans.put('I',1);romans.put('V',5);romans.put('X',10);romans.put('L',50);
        romans.put('C',100);romans.put('D',500);romans.put('M',1000);
        int prevVal = romans.get(s.charAt(s.length()-1));
        int sum = prevVal;
        
        for(int i=s.length()-2;i>=0;i--){
            char current = s.charAt(i);
            int currentVal = romans.get(current);
            
            if(prevVal>currentVal){
                sum-=currentVal;
            } else {
                sum+=currentVal;
            }
            prevVal = currentVal;
        }
        
        return sum;
        
    }
}

