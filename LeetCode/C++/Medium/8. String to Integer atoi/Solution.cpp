class Solution {
public:
    int convert(string &s, int i, long long res, int sign) {
        if(i >= s.size() || !isdigit(s[i]))
            return (int)(sign * res);

        res = (res * 10) + (s[i] - '0');

        if(res*sign <= INT_MIN) return INT_MIN;
        if(res*sign >= INT_MAX) return INT_MAX;

        return convert(s, i+1, res, sign);
    }

    int myAtoi(string s) {
        int i = 0;
        long long res = 0;
        int sign = 1;

        while(i < s.size() && s[i] == ' ') 
            i++;
        
        if(i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        return convert(s, i, res, sign);
    }
};