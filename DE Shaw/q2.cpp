vector<int> findValidPasswords(vector<string> a) {
    vector<int> r;
    for (auto &s : a) {
        stack<char> st;
        for (char c : s)
            if (!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        r.push_back(st.empty());
    }
    return r;
}