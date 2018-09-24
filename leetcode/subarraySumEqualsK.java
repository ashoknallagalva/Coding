/*

    O(N) Time
    O(N) Space
*/

class Solution {
    public int subarraySum(int[] nums, int k) {
       
        int sum = 0, ans=0;
        
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0,1);
        
        for(int numsIndex = 0;numsIndex<nums.length;numsIndex++){
            sum+=nums[numsIndex];
            if(map.containsKey(sum-k)){
                ans+=map.get(sum-k);
            }
            
            map.put(sum,map.getOrDefault(sum,0)+1);
        }
        
        return ans;
        
    }
}
