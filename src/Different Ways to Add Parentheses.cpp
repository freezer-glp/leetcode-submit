/*Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Divide and Conquer
Show Similar Problems
*/
class Solution {
public:
    unordered_map<string, vector<int>> dp;
    vector<int> diffWaysToCompute(string input) {
        int len =  input.size();
        vector<int> res;
        if(len == 0)
            return res;
        if(dp.find(input) != dp.end()) { // already computed this string
            return dp[input];
        }
        int flag = 0;//0：there is no operator, 1 : find at least one operator in input
        for(int i = 0; i < len; i++) {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
                flag = 1;
                vector<int> leftRes = diffWaysToCompute(input.substr(0, i));
                vector<int> rightRes = diffWaysToCompute(input.substr(i + 1));
                for(int j : leftRes)
                    for(int k : rightRes) {
                        int tmp = 0;
                        if(input[i] == '+') {
                            tmp =  j + k;
                        }else if(input[i] == '-') {
                            tmp = j - k;
                        }else if(input[i] == '*') {
                            tmp = j * k;
                        }
                        res.push_back(tmp);
                        
                    }
            }
        }
        if(!flag) { // input is only a number
            res.push_back(atoi(input.c_str()));
        }
        dp[input] = res;
        return res;
        
    }
};