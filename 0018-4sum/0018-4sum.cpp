class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>s;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                set<long long>st;
                for(int k=j+1;k<n;k++)
                {
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    long long fourth=target-sum;
                    if(st.find(fourth)!=st.end())
                    {
                        vector<int>temp={nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                   st.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};