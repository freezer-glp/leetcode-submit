/*Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
Subscribe to see which companies asked this question

Hide Tags Math String
Show Similar Problems
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if(!len1 || !len2) {
            return "0";
        }
        vector<char> res(len1 + len2, '0');
        //two index when we compute sum
        int in1 = 0;
        int in2 = 0;
        for(int i = len1 - 1; i >= 0; i--) {
            in2 = 0;
            int n1 = num1[i] - '0';
            int add = 0;
            for(int j = len2 - 1; j >= 0; j--) {
                int n2 = num2[j] - '0';
                int tmp = res[in1 + in2] - '0' +  n1 * n2 + add;
                //cout<<"tmp:"<<tmp<<endl;
                add = tmp / 10;
                res[in1 + in2] = tmp % 10 + '0';
                in2 ++;
            }
            if(add > 0)
                res[in1 + in2] = add + '0';
            // for(char c : res)
            //     cout<<c<<" ";
            // cout<<endl;
            in1++;
        }
       
        int k = res.size() - 1;
        while(res[k] == '0') {
            k --;
        }
       // cout<<"k:"<<k<<endl;
        if(k == -1)
            return "0";
        string result = "";
        while(k >= 0) {
            result += (char)res[k];
           // cout<<"result:"<<result<<endl;
            k--;
        }
        return result;
    }
};