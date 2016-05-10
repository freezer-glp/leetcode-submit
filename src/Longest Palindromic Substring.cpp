/*Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Subscribe to see which companies asked this question

Hide Tags String
Show Similar Problems
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 0)
            return s;
            //用以下这种方法开数组会 Memory Limit Exceeded
        // bool** dp = new bool* [len];
        // for(int i = 0; i < len; i++) {
        //     dp[i] = new bool[len];
        // }
        //改成以下这种可以~
        bool dp[len][len];//dp[i][j] 表示s(i,j)是否为回文子串
        for(int i = 0; i < len; i++)
            dp[i][i] = true;
        
        string res = s.substr(0, 1);
        //cout<<res<<endl;
        for(int i = len - 1; i >= 0; i--) {
            for(int j = i + 1; j < len; j++) {
                dp[i][j] = (s[i] == s[j]) && (j - i < 3 || dp[i + 1][j - 1]);
                // cout<<"i:"<<i<<" j:"<<j<<" dp:"<<dp[i][j]<<endl;
                if(dp[i][j] &&  (j - i + 1 > res.size())) {
                  //  cout<<i<<" "<<j<<endl;
                    res = s.substr(i, j - i + 1);
                }
            }
        }
        return res;
        
    }
};