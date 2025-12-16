1class Solution {
2public:
3    vector<vector<int>> subsets(vector<int>& nums) {
4        int n = nums.size();
5        int total = 1 << n; // i.e. 2^n
6        vector<vector<int>> ans;
7        for(int mask = 0; mask <= total - 1; mask++){
8            vector<int> subset;
9            for(int i = 0; i < n; i++){
10                if(mask & (1 << i)){
11                    subset.push_back(nums[i]);
12                } 
13            }
14            ans.push_back(subset);
15        }
16        return ans;
17    }
18};