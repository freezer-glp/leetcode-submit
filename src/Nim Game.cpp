/*You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.

Hint:

If there are 5 stones in the heap, could you figure out a way to remove the stones such that you will always be the winner?*/
class Solution {
public:
    //以下为初始的基本思想：用递归，期间用map保存已经计算出的解，但依旧超时，
    //因为map的find需要时间
    /*
    map<int, bool> m;
    bool canWinNim(int n) {
        if(n < 0)
            return false;
        map<int, bool>::iterator iter;
        iter = m.find(n);
        if(iter != m.end())
            return iter->second;
        if(n <= 3) {
            m[1] = true;   
            m[2] = true;
            m[3] = true;
            return true;
        }
        if(n == 4) {
            m[4] = false;
            return false;
        }
        bool win3 = canWinNim(n - 3);
        if(!win3) {
            m[n] = true;
            return true;
        }
            
        bool win2 = canWinNim(n - 2);
        if(!win2){
            m[n] = true;
            return true;
        }
        bool win1 = canWinNim(n - 1);
        if(!win1) {
            m[n] = true;
            return true;
        }
        m[n] = false;
        return false;
    }
    */
    //看了讨论区大神的，给跪了，原来需要找到背后的数学规律
    //即如果能整除4则会必败
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};