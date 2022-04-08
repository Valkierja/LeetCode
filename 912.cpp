
#include <random>

class Solution {
public:
    void shuffle(vector<int>& nums) {
        default_random_engine e;
        int n = nums.size();
        uniform_int_distribution<unsigned> u(0, n-1);
        for (int i = 0 ; i < n; i++) {
            // 生成 [i, n - 1] 的随机数
            int r =u(e);
            swap(nums[i], nums[r]);
        }
    }
	vector<int> sortArray(vector<int>& nums) {
        shuffle(nums);
		QuickSort(nums, 0, nums.size() - 1);
		return nums;
	}
	void QuickSort(vector<int>& nums, int l, int r) {
		if (l < r)
		{
			int mid = partition(nums, l, r);
			QuickSort(nums, l, mid - 1);//注意点，l和r的值自己写错
			QuickSort(nums, mid + 1, r);//注意点,l和r的值自己写错
		}
	}
	int partition(vector<int>& nums, int l, int r)
	{
		int pivot = nums[l];
		int i = l + 1, j = r;
		while (true)
		{
			while (i <= j && nums[i] <= pivot) i++;//寻找比pivot大的元素
			while (i <= j && nums[j] >= pivot) j--;//寻找比pivot小的元素
			if(i>=j) break;
			swap(nums[i], nums[j]);
		}
		//把arr[j]和主元交换
		swap(nums[j], nums[l]);
		return j;
	}
};
