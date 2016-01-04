/*Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
https://leetcode.com/static/images/problemset/rectangle_area.png
Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.

Credits:
Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.

Subscribe to see which companies asked this question

Hide Tags Math
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(A <= E && C >= G || A >= E && C >= G) { //��֤ABCD����������ಢ�ҿ�ȱȽ�խ����һ��
            int tmp;
            tmp = A;A=E;E=tmp;
            tmp = B;B=F;F=tmp;
            tmp = C;C = G; G = tmp;
            tmp = D;D = H; H = tmp;
        }
        //case 1: no common area
        if(E >= C || G <= A || H < B || F > D) {
            return recArea(A, B, C, D) + recArea(E, F, G, H);
        }
        
        //has some  common areas
        if(E >= A && E <= C) {
            if(H >= B && H <= D && F <= B) {
                return recArea(A, B, C, D) + recArea(E, F, G, H) - recArea(E, B, C, H);
            }
            if(H >= D && F <= B) {//�����޴�������ȫ������ϵ
                return recArea(A, B, C, D) + recArea(E, F, G, H) - recArea(E, B, C, D);
            }else if(H <= D && F >= B) {
                return recArea(A, B, C, D) + recArea(E, F, G, H) - recArea(E, F, C, H);
            }
            if(F >= B && F <= D) {
                return recArea(A, B, C, D) + recArea(E, F, G, H) - recArea(E, F, C, D);
            }
                
        }
        if(E <= A && G >= C ) {
            if(H >= B && H <= D && F <= B) {
                return recArea(A, B, C, D) + recArea(E, F, G, H) - recArea(A, B, C, H);
            }
            if(H >= D && F <= B) {//һ����ȫ����һ������
                return  recArea(E, F, G, H);
            }else if(H <= D && F >= B) {//
                return recArea(A, B, C, D) + recArea(E, F, G, H) - recArea(A, F, C, H);
            }
            if(F <= D && F >= B) {
                return recArea(A, B, C, D) + recArea(E, F, G, H) - recArea(A, F, C, D);
            }
        }
        
    }
    int recArea(int a, int b, int c, int d) {
        //compute rectangle area through left and top corner
        return (c - a) * (d - b);
    }
};