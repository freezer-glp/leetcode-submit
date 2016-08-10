/*Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
Subscribe to see which companies asked this question

Hide Tags Hash Table Heap
Show Similar Problems
*/
class Solution {
public:
    struct pair {
        int key;
        int value;
    };
    struct cmp {
        bool operator()(pair* a, pair* b) {
            return a->value <= b->value;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        vector<int> res;
        priority_queue<pair* , vector<pair*>, cmp> pq;
        int heap[2][2]; // heap[0][1] <= heap[1][1]
        for(int num : nums) {
            if(m.find(num) != m.end()) {
                m[num] += 1;
            }else {
                //new one
                m[num] = 1;
            }
        }
        map<int, int>::iterator it;
        for(it = m.begin(); it != m.end(); it++) {
            struct pair * tmp = new pair();
            tmp -> key = it -> first;
            tmp -> value = it -> second;
            pq.push(tmp);
        }
        for(int i = 0; i < k; i++) {
            res.push_back(pq.top() -> key);
            pq.pop();
        }
        return res;
    }
    
};