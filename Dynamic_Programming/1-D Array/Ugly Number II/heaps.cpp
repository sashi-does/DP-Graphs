class Solution {
public:
    int nthUglyNumber(int n) {


        // ********************* Heaps *********************
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        unordered_set<int> seen;
        long long a, b, c;
        long long curr = 1, top;
        for(int i = 0; i < n; i++) {

            top = pq.top();
            curr = top;
            pq.pop();

            a = top * 2;
            b = top * 3;
            c = top * 5;

            if(!seen.count(a)) {
                seen.insert(a);
                pq.push(a);
            }
            if(!seen.count(b)) {
                seen.insert(b);
                pq.push(b);
            }
            if(!seen.count(c)) {
                seen.insert(c);
                pq.push(c);
            }

        }
        return curr;
    }
};