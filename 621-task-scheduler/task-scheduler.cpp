class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        // Count each task
        for (char c : tasks) {
            freq[c - 'A']++;
        }

        // Find maximum frequency
        int maxFreq = 0;
        for (int f : freq) {
            maxFreq = max(maxFreq, f);
        }

        // Count how many tasks have maximum frequency
        int countMax = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                countMax++;
            }
        }

        // Calculate minimum required intervals
        int result = (maxFreq - 1) * (n + 1) + countMax;

        // If other tasks completely fill the gaps
        return max((int)tasks.size(), result);
    }
};