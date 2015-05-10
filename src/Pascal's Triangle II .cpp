/*Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = vector<int>();
        if(rowIndex == 0){
            vector<int> temp;
            temp.push_back(1);
            return temp;
        }else{
            vector<int> pre = getRow(rowIndex -1);
            for(int i = 0; i <= rowIndex; i++){
                if(i == 0 || i == rowIndex){
                    ans.push_back(1);
                }else{
                    int num = pre[i-1] + pre[i];
                    ans.push_back(num);
                }
            }
            return ans;
        }
    }
};