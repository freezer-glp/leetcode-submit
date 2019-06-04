/*
N cars are going to the same destination along a one lane road.  The destination is target miles away.

Each car i has a constant speed speed[i] (in miles per hour), and initial position position[i] miles towards the target along the road.

A car can never pass another car ahead of it, but it can catch up to it, and drive bumper to bumper at the same speed.

The distance between these two cars is ignored - they are assumed to have the same position.

A car fleet is some non-empty set of cars driving at the same position and same speed.  Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.


How many car fleets will arrive at the destination?

 

Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:
The cars starting at 10 and 8 become a fleet, meeting each other at 12.
The car starting at 0 doesn't catch up to any other car, so it is a fleet by itself.
The cars starting at 5 and 3 become a fleet, meeting each other at 6.
Note that no other cars meet these fleets before the destination, so the answer is 3.
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
      if (position.empty() || speed.empty() ||
          position.size() != speed.size()) return 0;
      vector<int> idxs;
      vector<float> times;
      for (int i = 0; i<speed.size(); ++i) {
        idxs.push_back(i);
        times.push_back(1.0 * (target-position[i]) / speed[i]);
      }
      // 横轴坐标降序排序，
      // 如果坐标小，而且时间长，说明距离远还跑的慢，是车队头
      // 如果坐标小，而且时间短，说明速度快，但是会被车队头卡住
      sort(idxs.begin(), idxs.end(), [&](int& a, int& b) ->bool {
        return (position[a] > position[b]); 
      } );
      int num = 1;
      float flag = times[idxs[0]];
      for (int i = 0; i<speed.size(); ++i) {
        if (times[idxs[i]] > flag) {
          num++;
          flag = times[idxs[i]];
        }
      }
      return num;
    }
};