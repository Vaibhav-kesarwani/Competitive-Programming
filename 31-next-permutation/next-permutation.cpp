class Solution {
public:
    //binary search function to get the next greater element's index
    int bs(vector<int>& nums, int target, int start)
    {
        int n = nums.size();
        int ans=-1, l=start, r=n-1;        
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]>target)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int r = n-1;
        int l = -1;
        while(r>0)
        {
            if(nums[r-1] < nums[r]) //finding the 1st index which is smaller than the current index. this will be our index that we need to increase the value at first
            {
                l = r-1;
                break;                
            }
            r--;
        }        
        if(l == -1) //if we reach till beginning of the array, it means the array was in decreasing order, hence just sort the array to get the first permutation sequence of the array
        {
            sort(nums.begin(), nums.end());
            return;
        }
        sort(nums.begin()+r, nums.end()); //sort the array after the index where we need to increase the value
        int swapTarget = bs(nums, nums[l], r); //find the next greater element to the right of the index where we need to increase the value     
        swap(nums[l], nums[swapTarget]); //swap the value at the index which needed to be increased and the next greater element to the right of that index, leaving us with the desired array state
    }
};