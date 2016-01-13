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
        //������˼·��Hindex1���ƣ�ֻ����1�У�ʹ�ÿ��Ž����˽������������Դ�Ϊ��������
        //��Ѱ�Ҵ��ڵ���ת��ΪѰ�ҵ���
        int len = citations.size();
        //the index is from 0 to (len - 1)
        int low = 0, high = len - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(citations[mid] == len - mid)//��N = len - 1, �±�Ϊi����Ϊ�� N - i + 1���������len-1-i+1 = len - i, �˴���mid����i 
                return len - mid;
            else if(citations[mid] < len - mid) {
                low = mid + 1;
            }else if(citations[mid] > len - mid) {
                high = mid - 1;
            }
        }
        //���û���ҵ����ڵ��������˵�������һ�ε� low ~ high�䶼���㣬���Խ��Ϊlen - (high + 1)
        return len -(high + 1);
    }
};