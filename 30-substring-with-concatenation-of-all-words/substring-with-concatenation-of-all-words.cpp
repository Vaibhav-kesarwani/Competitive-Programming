class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), wordCount = words.size();
        if (n == 0 || wordCount == 0) return {};

        int wordLen = words[0].size();
        int substrLen = wordLen * wordCount;
        vector<int> res;

        // Create frequency map of words
        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }

        // Sliding window approach
        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> windowFreq;

            while (right + wordLen <= n) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.find(word) != wordFreq.end()) {
                    windowFreq[word]++;
                    count++;

                    while (windowFreq[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowFreq[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        res.push_back(left);
                    }
                } else {
                    windowFreq.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return res;
    }
};