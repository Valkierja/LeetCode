class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid;
        while(left<right){
            mid = left + (right - left)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target < nums[mid]){
                right = mid;
            }
            else if(target > nums[mid]  ){
                left = mid +1;
            }
        }
        return -1;
        
    }
};
