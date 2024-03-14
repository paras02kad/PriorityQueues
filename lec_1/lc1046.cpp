class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a == b)
                pq.push(0);
            else
                pq.push(a - b);
        }
        return pq.top();
    }
};