
olean knows(int a, int b); */

public class Solution extends Relation {
    public int findCelebrity(int n) {
        
        int celebrity = -1;
       
        int personA = 0, personB = n-1;
        
        while(personA<personB){
            if(knows(personA,personB)){
                personA++;
                celebrity = personB;
            } else {
                personB--;
                celebrity = personA;
            }
        }
        
        if(celebrity==-1){
            return -1;
        }
        
        for(int i=0;i<n;i++){
            if(i!=celebrity &&(knows(celebrity,i) || !knows(i,celebrity))){
                return -1;
            }
        }
    
        return celebrity;
        
    }
}
