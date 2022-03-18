// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=479 lang=cpp
 *
 * [479] Largest Palindrome Product
 */

// @lc code=start
class Solution {
public:
    int largestPalindrome(int n) {
        if(n == 1) return 9;
        int mx = pow(10, n) - 1;
        int mi = pow(10, n-1) ;
        for(int i = mx; i >= mi; i --){
            long candicate = convert(i);
            for(long j = mx; j *j >= candicate; j --){
                if(candicate % j == 0 && candicate / j <= mx){
                    return candicate % 1337;
                }
            }
        }
        return -1;
    }
    long convert(int i){
        string s = to_string(i);
        for(int i = s.size() - 1; i >= 0; i --){
            s += s[i];
        }
        return stol(s);
    }
};
// @lc code=end

