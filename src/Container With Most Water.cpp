/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container.
*/
//first edition -> time limit exceed
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = -1;
		for (int i = 0; i <= height.size()-1; i++ )
			for (int j = 0; j <= height.size()-1; j++){
				int tmp = getArea(i,height[i],j,height[j]);
				if( tmp > res)
					res = tmp;
			}
		return res;
    }
	int getArea(int i1, int a1, int i2, int a2){
		int h = getMin(a1, a2);
		int l = i1 < i2 ? i2 - i1 : i1 - i2;
		return h * l;
	}
	int getMin(int a1,int a2) {
		return a1 < a2 ? a1 : a2;
	}
};*/

//second edition
//开始假设最左和最右构成的最大，然后向中间移动。每次算面积都要看柱子的最小值，所以向中间移动时，如果当前柱子大于最小值，就没必要移动了
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0,res = 0,a1,a2,area;
		int j = height.size()-1;
		int l = i < j ? j - i : i - j;
		res = getArea(i,height[i], j, height[j]);
		while(i < j){
			int h = getMin(height[i], height[j]);
			while(height[i] <= h && i < j) 
				i++;
			area = getArea(i,height[i], j, height[j]);
			if(area > res)
				res = area;
			while(height[j] <= h && i < j)
				j--;
			area = getArea(i,height[i], j, height[j]);
			if(area > res)
				res = area;
		}
		return res;
		
		
	}
	int getArea(int i1, int a1, int i2, int a2){
		int h = getMin(a1, a2);
		int l = i1 < i2 ? i2 - i1 : i1 - i2;
		return h * l;
	}
	int getMin(int a1,int a2) {
		return a1 < a2 ? a1 : a2;
	}
};