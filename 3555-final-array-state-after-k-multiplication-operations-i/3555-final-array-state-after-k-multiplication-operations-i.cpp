class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
       while(k--)
       {
         int mini=*min_element(nums.begin(),nums.end());
         int idx=-1;
         for(int i=0;i<nums.size();i++)
         {
            if(nums[i]==mini)
            {
                nums[i]*=multiplier;
                break;
            }
         }
       }
       return nums;
    }
};