class SparseVector {
    Map<Integer, Integer> mp = new HashMap<>();
    SparseVector(int[] nums) {
        
        for(int i = 0; i < nums.length; i++){
            if(nums[i] != 0){
                mp.put(i, nums[i]);
            }
        }
    }
    
	// Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {
        int ans = 0;
        for(int key : vec.mp.keySet()){
            if(this.mp.containsKey(key)){
                ans += this.mp.get(key) * vec.mp.get(key);
            }
        }

        return ans;
    }
}

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1 = new SparseVector(nums1);
// SparseVector v2 = new SparseVector(nums2);
// int ans = v1.dotProduct(v2);