1class Solution {
2public:
3    int minOperations(vector<int>& nums, int k) {
4        long long sum = 0;
5        for(int x : nums) sum += x;
6
7        int rem = sum % k;
8        return rem;      // minimum operations
9    }
10};
11