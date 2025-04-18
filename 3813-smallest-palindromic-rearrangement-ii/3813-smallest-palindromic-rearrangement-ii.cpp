class Solution {
public:
    int ncr(int n, int r, int limit) {
        long long res = 1;
        if (r > n - r) r = n - r;
        for (int i = 1; i <= r; i++) {
            res *= n - i + 1;
            res /= i;
            if (res > limit) return limit + 1;
        }
        return res;
    }

    int getAllPermsCount(vector<int> &cnt, int limit) {
        int total = accumulate(cnt.begin(), cnt.end(), 0);
        long long res = 1;
        for (int i = 0; i < 26; i++) {
            int choices = ncr(total, cnt[i], limit);
            if (choices == limit + 1) return limit + 1;
            res *= choices;
            if (res > limit) return limit;
            total -= cnt[i];
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
        char middle = '?';
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                middle = char(i + 'a');
            }
            cnt[i] /= 2;
        }
        if (getAllPermsCount(cnt, k) < k) return "";
        string ans = "";
        for (int i = 0; i < n / 2; i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (cnt[ch - 'a'] == 0) continue;
                cnt[ch - 'a']--;
                int perms = getAllPermsCount(cnt, k);
                if (perms >= k) {
                    ans += ch;
                    break;
                } else {
                    k -= perms;
                    cnt[ch - 'a']++;
                }
            }
        }
        if (middle != '?') ans += middle;
        for (int i = n / 2 - 1; i >= 0; i--) ans += ans[i];
        return ans;
    }
};