class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      stack<int>st;
      int n=temperatures.size();
      vector<int>ans(n,0);
      for(int i=0;i<n;i++)
      {
         while(!st.empty() && temperatures[st.top()]<temperatures[i])
         {
            int idx=st.top();
            st.pop();
            ans[idx]=i-idx;
         }
         st.push(i);
      }
      return ans;
    }
};