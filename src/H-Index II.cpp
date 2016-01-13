/*Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Hint:

Expected runtime complexity is in O(log n) and the input is sorted.
Subscribe to see which companies asked this question

Hide Tags Binary Search
Show Similar Problems
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        //这个题的思路和Hindex1类似，只是在1中，使用快排进行了降序排序，这里自带为增序排序
        //将寻找大于等于转换为寻找等于
        int len = citations.size();
        //the index is from 0 to (len - 1)
        int low = 0, high = len - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(citations[mid] == len - mid)//设N = len - 1, 下标为i的数为第 N - i + 1大的数，即len-1-i+1 = len - i, 此处将mid带入i 
                return len - mid;
            else if(citations[mid] < len - mid) {
                low = mid + 1;
            }else if(citations[mid] > len - mid) {
                high = mid - 1;
            }
        }
        //如果没有找到等于的情况，则说明在最后一次的 low ~ high间都满足，所以结果为len - (high + 1)
        return len -(high + 1);
    }
};