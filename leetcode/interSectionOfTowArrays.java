class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        
        Set<Integer> hashIt = new HashSet<>();
        Set<Integer> ans = new HashSet<>();
        
        for(int i=0;i<nums1.length;i++){
            hashIt.add(nums1[i]);
        }
        
        for(int i=0;i<nums2.length;i++){
            if(hashIt.contains(nums2[i])){
                ans.add(nums2[i]);
            }
        }
        
        return toInt(ans);
        
        
    }
    
    private int[] toInt(Set<Integer> s){
        int[] ans = new int[s.size()];
        int i=0;
        for(Integer val: s){
            ans[i] = val;
            i++;
        }
        return ans;
    }
}
