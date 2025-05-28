class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        int n = q.size() / 2;
        queue<int> firstHalf;
        
        // Step 1: Store first half
        for (int i = 0; i < n; i++) {
            firstHalf.push(q.front());
            q.pop();
        }

        queue<int> result;

        // Step 2: Alternate from firstHalf and remaining q
        while (!firstHalf.empty() && !q.empty()) {
            result.push(firstHalf.front());
            firstHalf.pop();

            result.push(q.front());
            q.pop();
        }

        // Step 3: If any leftovers (odd size case)
        while (!firstHalf.empty()) {
            result.push(firstHalf.front());
            firstHalf.pop();
        }

        while (!q.empty()) {
            result.push(q.front());
            q.pop();
        }

        return result;
    }
};
