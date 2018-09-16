class Solution {
    public int majorityElement(int[] nums) {
        
        int count=0;
        int val=Integer.MIN_VALUE;
        
        for(int i=0;i<nums.length;i++){
            if(count==0){
                val = nums[i];
            }
            
            count+= (val==nums[i]) ? 1 : -1;
            
        }
        
        return val;
        
    }
}
