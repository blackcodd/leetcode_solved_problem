class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        for (auto &w : words) {
            mp[w]++;
        }

        int ans = 0;
        bool hasCentralPalindrome = false;

        for (auto it = mp.begin(); it != mp.end(); ) {
            string word = it->first;
            int count = it->second;

            string rev = string{word[1], word[0]};

            if (word == rev) {  // Palindromic word like "aa"
                int pairs = count / 2;
                ans += pairs * 4;
                if (count % 2 == 1) hasCentralPalindrome = true;
                it = mp.erase(it);
            } else if (mp.count(rev)) {
                int pairCount = min(count, mp[rev]);
                ans += pairCount * 4;
                mp[rev] -= pairCount;
                it = mp.erase(it);
            } else {
                ++it;
            }
        }

        if (hasCentralPalindrome) ans += 2;

        return ans;
    }
};
