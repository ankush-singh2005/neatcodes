class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        int wordLength = words[0].size();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;

        unordered_map<string, int> wordMap;
        for (string &word : words) {
            wordMap[word]++;
        }

        for (int i = 0; i < wordLength; i++) { // Check all possible starting points
            int left = i, right = i;
            unordered_map<string, int> seenWords;
            int count = 0;

            while (right + wordLength <= s.size()) {
                string word = s.substr(right, wordLength);
                right += wordLength;

                if (wordMap.count(word)) {
                    seenWords[word]++;
                    count++;

                    while (seenWords[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLength);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLength;
                    }

                    if (count == wordCount) {
                        ans.push_back(left);
                    }
                } else {
                    seenWords.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return ans;
    }
};
