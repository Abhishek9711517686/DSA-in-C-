1class Solution {
2public:
3    int minBitFlips(int start, int goal) {
4        int x = start ^ goal;
5        int count = 0;
6        
7        while(x > 0){
8            count += (x & 1);
9            x >>= 1;
10        }
11        return count;
12    }
13};