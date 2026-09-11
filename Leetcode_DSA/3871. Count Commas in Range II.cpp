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
        return res;

    }
};