// http://www.cplusplus.com/reference/random/
// https://discuss.leetcode.com/topic/53979/straight-forward-c-solution

class Solution {
    vector<int> _nums;
public:
    Solution(vector<int> nums) {
        _nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> tmp(_nums);
        for(int i=1;i<_nums.size();i++){
            int j=rand()%(i+1);
            swap(tmp[i],tmp[j]);
        }
        return tmp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
