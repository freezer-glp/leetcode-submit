/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"*/
class Solution {
public:
    bool check(string a){
	//	cout<<"check:"<<a<<endl;
		stack<char> s;
		int len = a.size();
		for(int i = 0; i < len; i++){
			if(a[i] == '('){
				s.push(a[i]);
			}else{
				if(!s.empty())
					s.pop();
				else
					return false;
			}
		}
		return s.empty();
	}
	bool generate(int n,int i,vector<string> &ans,string p){
			//cout<<"i:"<<i<<endl;
			if(i == 2*n){
				if(check(p)){
				//	cout<<"before p:"<<p<<endl;
					//for(int j=0; j< ans.size();j++)
					//	if(ans[j].compare(p) == 0)
						//	return false;
					ans.push_back(p);
					
					return true;
				}else
					return false;
			}else{
			    int flag=0;
			    for(int k= p.size()-1;k >= 0;k--)//避免重复的剪枝
			        if(p[k] == ')'){
			            flag = k;
			            break;
			        }
				for(int j=flag+1; j<= i; j++){
					string temp = p;
					if(j == i){
						temp += ")";
					}else{
						temp.insert(j,")");
					}
				//	cout<<"temp"<<temp<<endl;
					generate(n,i+1,ans,temp);
				}
			}
	}
	
	 vector<string> generateParenthesis(int n) {
        string a = "";
		vector<string> ans;
		int num = n;
		while(num-- != 0)
			a += "(";
		//cout<<"a:"<<a<<endl;
		generate(n,n,ans,a);
		return ans;
    }
};