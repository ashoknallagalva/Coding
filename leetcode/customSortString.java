class Solution {
    public String customSortString(String S, String T) {
        
        StringBuilder sb = new StringBuilder();
        int[] map = new int[26];
        
        
        for(char c: T.toCharArray()){
            map[c-'a']++;
        }
        
        for(char c: S.toCharArray()){
            for(int i=0;i<map[c-'a'];i++){
                sb.append(c);
            }
            map[c-'a']=0;
        }
        
        for(char c='a';c<='z';c++){
            for(int i=0;i<map[c-'a'];i++){
                sb.append(c);
            }
        }
        
        return sb.toString();
        
    }
}
