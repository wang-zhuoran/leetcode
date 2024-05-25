class Solution {
public:

    string palindrome(string s, int l, int r) {

        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }

        return s.substr(l + 1, r - l - 1);

    }

    string longestPalindrome(string s) {

        string res = "";
        for(int i = 0; i < s.size(); i ++){
            // 找到以s[i]为中心的最长回文子串 （字符串长度为奇数）
            string s1 = palindrome(s, i, i);

            // 找到以s[i]和s[i+1]为中心的最长回文子串 （字符串长度为偶数）
            string s2 = palindrome(s, i, i+1);

            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;

    }
};
