/*class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int loc, int low, int top, int target, int flag) {
        //loc: the number of the specific line or column
        if(flag == 0) {// search a line
            while(low <= top) {
                int mid = (low + top) >> 1;
                if(matrix[loc][mid] > target)
                    top = mid - 1;
                else if(matrix[loc][mid] < target)
                    low = mid + 1;
                else 
                    return true;
            }
            
        }else if(flag == 1){ //search a column
             while(low <= top) {
                int mid = (low + top) >> 1;
                if(matrix[mid][loc] > target)
                    top = mid - 1;
                else if(matrix[mid][loc] < target)
                    low = mid + 1;
                else 
                    return true;
            }
            
        }
        
        return false;
    }
    //大矩阵按照取中间点，进行切割为4个象限，然后化为分别在这四个矩阵中进行查找
    bool divideSearch(vector<vector<int>>& matrix, int hb, int ht, int wb, int wt, int target) {
        if(hb == ht && wb == wt) {
            return matrix[hb][wb] == target;
        }
        int hm = -1, wm = -1;
        if(hb != ht ) 
            hm = (hb + ht) >> 1;
        if(wb != wt)
            wm = (wb + wt) >> 1;
        bool f1, f2, f3, f4;
        
        if(hb != ht && wb != wt) {
            if(matrix[hb][wb] <= target && matrix[ht][wt] >= target) {//利用矩阵左上角的最小值和右下角的最大值进行剪枝
                f1 = divideSearch(matrix, hb, hm, wm + 1, wt, target);
                if(f1)
                    return true;
                f2 = divideSearch(matrix, hb, hm, wb, wm, target);
                if(f2)
                    return true;
                f3 = divideSearch(matrix, hm + 1, ht, wb, wm, target);
                if(f3)
                    return true;
                f4 = divideSearch(matrix, hm +1, ht, wm + 1, wt, target);
                if(f4)
                    return true;
            }else
                return false;
        }else if(hb != ht) {//only a single column
          //  cout<<"case 2"<<endl;
            if(matrix[hb][wb] <= target && matrix[ht][wb] >= target) {
                // f1 = false;
                // f2 = divideSearch(matrix, hb, hm, wb, wb, target);
                // if(f2)
                //     return true;
                // f3 = divideSearch(matrix, hm + 1, ht, wb, wb, target);
                // if(f3)
                //     return true;
                // f4 = false;
                return binarySearch(matrix, wb, hb, ht, target, 1);//如果只有一列，不用再切割了，直接进行二分查找
            }else
                return false;
        }else if(wb != wt) {//only a single line
            if(matrix[hb][wb] <= target && matrix[hb][wt] >= target) {
                // f1 = divideSearch(matrix, hb, hb, wm + 1, wt, target);
                // if(f1)
                //     return true;
                // f2 = divideSearch(matrix, hb, hb, wb, wb, target);
                // if(f2)
                //     return true;
                // f3 = false;
                // f4 = false;
                return binarySearch(matrix, hb, wb, wt, target, 0);//如果只有一行，不用再切割了，直接进行二分查找
            }else
                return false;
        }
        return f1 || f2 || f3 || f4;
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return divideSearch(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, target);
    }
};*/
class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int loc, int low, int top, int target, int flag) {
        //loc: the number of the specific line or column
        if(flag == 0) {// search a line
            while(low <= top) {
                int mid = (low + top) >> 1;
                if(matrix[loc][mid] > target)
                    top = mid - 1;
                else if(matrix[loc][mid] < target)
                    low = mid + 1;
                else 
                    return true;
            }
            
        }else if(flag == 1){ //search a column
             while(low <= top) {
                int mid = (low + top) >> 1;
                if(matrix[mid][loc] > target)
                    top = mid - 1;
                else if(matrix[mid][loc] < target)
                    low = mid + 1;
                else 
                    return true;
            }
            
        }
        
        return false;
    }
    //大矩阵按照取中间点，进行切割为4个象限，然后化为分别在这四个矩阵中进行查找
    bool divideSearch(vector<vector<int>>& matrix, int hb, int ht, int wb, int wt, int target) {
        if(hb == ht && wb == wt) {
            return matrix[hb][wb] == target;
        }
        int hm = -1, wm = -1;
        if(hb != ht ) 
            hm = (hb + ht) >> 1;
        if(wb != wt)
            wm = (wb + wt) >> 1;
        bool f1, f2, f3, f4;
        
        if(hb != ht && wb != wt) {
            if(matrix[hb][wb] <= target && matrix[ht][wt] >= target) {//利用矩阵左上角的最小值和右下角的最大值进行剪枝
                f1 = divideSearch(matrix, hb, hm, wm + 1, wt, target);
                if(f1)
                    return true;
                f2 = divideSearch(matrix, hb, hm, wb, wm, target);
                if(f2)
                    return true;
                f3 = divideSearch(matrix, hm + 1, ht, wb, wm, target);
                if(f3)
                    return true;
                f4 = divideSearch(matrix, hm +1, ht, wm + 1, wt, target);
                if(f4)
                    return true;
            }else
                return false;
        }else if(hb != ht) {//only a single column
          //  cout<<"case 2"<<endl;
            if(matrix[hb][wb] <= target && matrix[ht][wb] >= target) {
                // f1 = false;
                // f2 = divideSearch(matrix, hb, hm, wb, wb, target);
                // if(f2)
                //     return true;
                // f3 = divideSearch(matrix, hm + 1, ht, wb, wb, target);
                // if(f3)
                //     return true;
                // f4 = false;
                return binarySearch(matrix, wb, hb, ht, target, 1);//如果只有一列，不用再切割了，直接进行二分查找
            }else
                return false;
        }else if(wb != wt) {//only a single line
            if(matrix[hb][wb] <= target && matrix[hb][wt] >= target) {
                // f1 = divideSearch(matrix, hb, hb, wm + 1, wt, target);
                // if(f1)
                //     return true;
                // f2 = divideSearch(matrix, hb, hb, wb, wb, target);
                // if(f2)
                //     return true;
                // f3 = false;
                // f4 = false;
                return binarySearch(matrix, hb, wb, wt, target, 0);//如果只有一行，不用再切割了，直接进行二分查找
            }else
                return false;
        }
        return f1 || f2 || f3 || f4;
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return divideSearch(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, target);
    }
};