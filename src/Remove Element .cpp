//Remove Element 
/*Given an array and a value, remove all instances of that value in place and return the new length. 
The order of elements can be changed. It doesn't matter what you leave beyond the new length.*/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0, j = n-1;
		int temp;
		if(n == 0)
		    return 0;
		while(i <= j){
			while(A[i] != elem){
				i++;
			    if(i >= n)
			        return n;
			}
			//if(i > j)
			   // break;
			while(A[j] == elem  && i < j){
				j--;
				if(j < 0)
			        return 0;
			}
			if(i > j)
			   break;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			i++;
			j--;
			
		}
		return j+1;
    }
};