/*Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]*/
class Solution {
public:
    bool check(string s){
        int i=0,j=s.size()-1;
        while(i <= j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        if(s.size() == 1){
            temp = vector<string>();
            temp.push_back(s);
            ans.push_back(temp);
        }else{
            vector<vector<string>> right;
            for(int i=1; i <= s.size(); i++){
                string s1 = s.substr(0 , i);
                if(check(s1)){
                    if(i == s.size()){
                        temp = vector<string>();
                        temp.push_back(s);
                        ans.push_back(temp);
                    }else{
                        right = vector<vector<string>>();
                        right = partition(s.substr(i));
                        for(int j = 0; j <= right.size()-1; j++){
                            right[j].insert(right[j].begin(),s1);
                        }
                        ans.insert(ans.end(),right.begin(),right.end());
                        
                    }
                }
            }
        }
        
        return ans;
    }
};