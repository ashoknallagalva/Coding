class Solution {
    public int maxProfit(int[] prices) {
        
       int maxProfit = 0;
        int minValue = Integer.MAX_VALUE;
        
        for(int i=0;i<prices.length;i++){
            if(minValue>prices[i]){
                minValue = prices[i];
            }
            
            if(prices[i]>minValue){
                maxProfit = Math.max(maxProfit, prices[i]-minValue);
            }
        }
        
        return maxProfit;
        
        
    }
}
