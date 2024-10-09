class Solution
{
    public:
        vector<int> nextGreaterElements(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> ans(2 *n, -1);
            nums.insert(nums.end(), nums.begin(), nums.end());
            stack<int> st;
            for (int i = 2 *n - 1; i >= 0; i--)
            {
                while (!st.empty())
                {
                    if (st.top() > nums[i])
                    {
                        ans[i] = st.top();
                        break;
                    }
                    else st.pop();
                }
                st.push(nums[i]);
            }
            ans.erase(ans.begin() + n, ans.end());
            return ans;
        }
};