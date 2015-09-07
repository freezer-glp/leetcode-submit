/*Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Hide Tags Stack String
*/
class Solution {
public:
    string simplifyPath(string path) {
        int len = path.size();
        stack<char> s;
        for(int i = 0; i <= len - 1; i++){
            if(path[i] == '/'){
                if(i == len - 1){//the path end with /
                    //cout<<"1"<<endl;
                    if(len == 1){//path consist of only one /
                        s.push(path[i]);
                    }else
                        break;
                }else if(!s.empty() && s.top() == '/'){//two / get together
                    //cout<<"2"<<endl;
                    continue;
                }else{
                    cout<<"3"<<endl;
                    s.push(path[i]);
                    cout<<s.top()<<endl;
                }
            }else if(path[i] == '.'){
                if(s.top() != '.' && (i == len -1 || path[i+1] == '/')){//only one . here
                    cout<<"only ."<<endl;
                    i++;//skip the ., and make i point the / next .,when end of for,we skip / automaticlly
                }else if(s.top() == '.' || path[i+1] == '.'){//two or more . here
                    if(s.top() == '.' || (i + 2) < len && path[i+2] != '/' ){
                        cout<<"push"<<path[i]<<endl;
                        s.push(path[i]);
                    }
                    else{
                        //we need pop last dir from stack
                        //pop the last /xxxx/
                        int count = 0;//the counter of /
                        while(count != 2){
                            if(s.top() == '/'){
                                if(s.size() == 1)// /..
                                    break;
                                else
                                    count ++;
                            }
                            cout<<"pop "<<count<<endl;
                            s.pop();
                        }
                        i++;//skip the ..
                    }
                }else if(!(i == len - 1 && s.top() == '/'))
                    s.push(path[i]);
            }else
                s.push(path[i]);
        }
        
        //build the answer
        string ans = "",tmp = "";
        stringstream stream;
        cout<<s.size()<<endl;
        while(!s.empty()){
            //cout<<ans<<endl;
            stream.clear();
            stream << s.top();
            cout<<"~"<<s.top()<<endl;
            stream >> tmp;
            ans = tmp + ans;
            s.pop();
        }
        if(ans.size() != 1 && ans[ans.size()-1] == '/')
            ans.erase(ans.size()-1);
        return ans;
    }
    
};