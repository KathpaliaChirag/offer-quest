 using ll = long long;

vector<string> solution(vector<string> fractions) {
    vector<string> ans;
    ans.reserve(fractions.size());

    for (const auto& expr : fractions) {
        size_t p1 = expr.find('/');
        size_t p2 = expr.find('+');
        size_t p3 = expr.find('/', p2 + 1);

        ll x = stoll(expr.substr(0,       p1));
        ll y = stoll(expr.substr(p1 + 1, p2 - p1 - 1));
        ll u = stoll(expr.substr(p2 + 1, p3 - p2 - 1));
        ll v = stoll(expr.substr(p3 + 1));

        ll num = x * v + u * y;
        ll den = y * v;

        ll g = std::gcd(num, den);
        num /= g;
        den /= g;

        ans.push_back(to_string(num) + "/" + to_string(den));
    }

    return ans;
}