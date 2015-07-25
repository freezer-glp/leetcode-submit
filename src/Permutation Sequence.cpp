/*The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.*/
class Solution {
public:
    int u[10] = {0};
    string res="";
    int num = 0;
    string getPermutation(int n, int k) {
	   getAllString(n,"",0,k);
	   return res;
    }
	void getAllString(int n,string a,int index,int k){
    	if(index == n){
    		num++;
    		if(num == k)
    		    res = a;
    		return ;
    	}
    	
    	string temp;
    	for(int i = 1;  i <= n; i++){
    	    if(num == k){
    	        return;
        	}
    		if(u[i] == 0){
    			temp = a;
    			temp += i + '0';
    			u[i] = 1;
    			getAllString(n,temp,index+1,k);
    			u[i] = 0;
    		}
    	}
	
    }

};