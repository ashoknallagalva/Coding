class Solution {
    public String toGoatLatin(String S) {
        
        Set<Character> vowels = new HashSet<>();
        StringBuilder ans = new StringBuilder();
        
        vowels.add('a');vowels.add('e');vowels.add('i');vowels.add('o');vowels.add('u');
        vowels.add('A');vowels.add('E');vowels.add('I');vowels.add('O');vowels.add('U');
        
        String[] words = S.trim().split(" ");
        
        for(int i =0;i<words.length;i++){
            ans.append(getGoatLatinWord(words[i],i+1,vowels));
            if(i<words.length-1){
                ans.append(" ");
            }
            
        }
              
        return ans.toString();
        
    }
    
    public String getGoatLatinWord(String word,int wordNumber, Set<Character> vowels){
        StringBuilder ans = new StringBuilder();
        
        char first = word.charAt(0);
        if(vowels.contains(first)){
            ans.append(first);
        }
        
        for(int i=1;i<word.length();i++){
            ans.append(word.charAt(i));
        }
        
        if(!vowels.contains(first)){
            ans.append(first);
        }
        
        ans.append("ma");
        while((wordNumber--)!=0){
            ans.append('a');
        }
        
        return ans.toString();
        
    }
}
