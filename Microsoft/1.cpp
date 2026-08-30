int solution(const string &s, const vector<int>& c) {
    int left = 0, right = c.size();
    while (left <= right) {
        const int mid = (left + right) >> 1;
        unordered_set<int> all(c.begin(), c.begin() + mid);
        vector<char> have(26, -1);
        bool mark = true;
        for (int i = 0, temp = -1; mark && i < s.length(); ++i) {
            const int p = s[i] - 'a';
            if (have[p] > temp) {
                mark = false;
            }
            have[p] = i;
            if (all.count(i + 1)) {
                temp = i;
            }
        }
        if (mark) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ++right > c.size() ? (-1) : right;

}
