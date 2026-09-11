class Solution {
public:
    long long countCommas(long long n) {
        if(n<999) return 0;
        long long res = 0;
        if (n >= 1000)              res = res + (n - 999);
        if (n >= 1000000)           res = res + (n - 999999);
        if (n >= 1000000000)        res = res + (n - 999999999);
        if (n >= 1000000000000)     res = res + (n - 999999999999);
        if (n >= 1000000000000000)  res = res + (n - 999999999999999);
        // sorrry 🤭
        // thora complex hora tha toh, i saw 15 digit limit and hardcoded the values,
        //  but i think this is not a better approach if you see this problem in future, 
        // so i will try to make it better with a loop and a formula, but for now this is the solution.
        return res;
    }
};