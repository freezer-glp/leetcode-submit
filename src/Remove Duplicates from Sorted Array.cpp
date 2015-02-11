//Remove Duplicates from Sorted Array
/*Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 Do not allocate extra space for another array, you must do this in place with constant memory.*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int len = n;
        queue<int > q;
        int flag;
        flag =  A[0];
        int i = 1;
        while(i < n){
            if(A[i] == flag){
                q.push(i);
                len--;
            }else{
                if(!q.empty()){
                    A[q.front()] = A[i];
                    q.pop();
                    q.push(i);
                    flag = A[i];
                    //i--;
                }else
                    flag = A[i];
            }
            i++;
        }
        
        return len;
        
    }
};