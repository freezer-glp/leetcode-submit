/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      if (numCourses <= 0) {
        return {};
      }
      
      if (prerequisites.empty()) { // 有课，但没有依赖，随意填一种即可
        vector<int> res;
        for (int i = 0; i < numCourses; ++i) {
          res.push_back(i);
        }
        return res;
      } 
      
      vector<vector<int>> adj(numCourses, vector<int>(1, 0));
      for (auto& pair : prerequisites) {
        adj[pair[0]][0]++;  // 第一个位置，存当前节点的入度，
        adj[pair[1]].push_back(pair[0]); // 后面都是当前节点指向的后续节点
      }
      vector<int> res;
      queue<int> q;
      for (int i = 0; i < adj.size(); ++i) {
        if (adj[i][0] == 0) {
          q.push(i);
        }
      }
      while (!q.empty()) {
        int top = q.front();
        q.pop();
        res.push_back(top);
        if (adj[top].size() > 1) { //当前节点有后续节点，不过当前节点的前序节点已经没了
          for (int j = 1; j < adj[top].size(); ++j) {
            adj[adj[top][j]][0]--;
            if (adj[adj[top][j]][0] == 0) {
              q.push(adj[top][j]);
            }
          }
        }
      }
      if (res.size() == numCourses)
        return res;
      res.clear();
      return res;
    }
};