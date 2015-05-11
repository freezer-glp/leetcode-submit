/*You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int num = matrix.size()-1;
        if(num <= 0){
            return ;
        }
        int temp,temp1,temp2;
        int len = num/2;
        for(int i=0; i <= len; i++){//竖着只需要转换一半
            for(int j=i; j <= num - i - 1; j++){//横轴达到整体往里缩一圈的效果
                int a = i,b = j,flag = 1;
                temp1 = matrix[a][b];
                while(flag <= 4 ){
                        temp2 = matrix[b][num-a];
                        matrix[b][num-a] = temp1;
                        temp1 = temp2;
                        temp = a;
                        a = b;
                        b = num - temp;
                        flag ++;
                }
                
            }
        }
    }
};