class Solution {
    public int maxProfit(int[] prices) {
        
        int sum = 0;
        int n = prices.length;
        boolean flip = true;
        
        if(prices.length==1){
            return 0;
        }
        
        for(int i=0;i<n-1;i++){
            if(flip){
                if(prices[i]<prices[i+1]){
                    sum-=prices[i];
                    flip=!flip;
                    if(i+1==n-1){
                        sum+=prices[i+1];
                    }
                }
                
            } else {
                if(prices[i]>prices[i+1]){
                    sum+=prices[i];
                    flip=!flip;
                } else if(i+1==n-1){
                    sum+=prices[i+1];
                    flip=!flip;
                }
            }
            
        }
        
        return sum;
        
        
    }
}
