//Name: Pritam Shaw
//Roll : 2024UG3011  sec:B
//subject: Algorithm lab(CS-2107/CD-2107)
//Experiment-3 Task-4-Implementation of Karotsuba Algoritham


#include<bits/stdc++.h>
using namespace std;

void eqLen(string &a, string &b) {
    int l1 = a.size(), l2 = b.size();
    if (l1 < l2) a.insert(0, l2 - l1, '0');
    else if (l2 < l1) b.insert(0, l1 - l2, '0');
}

string addStr(const string &a, const string &b) {
    string r;
    int c = 0, n = max(a.size(), b.size());
    for (int i = 0; i < n; ++i) {
        int x = (i < a.size()) ? a[a.size() - 1 - i] - '0' : 0;
        int y = (i < b.size()) ? b[b.size() - 1 - i] - '0' : 0;
        int s = x + y + c;
        r.push_back(s % 10 + '0');
        c = s / 10;
    }
    if (c) r.push_back(c + '0');
    reverse(r.begin(), r.end());
    return r;
}

string subStr(const string &a, const string &b) {
    string r;
    int brw = 0;
    for (int i = 0; i < a.size(); ++i) {
        int x = a[a.size() - 1 - i] - '0';
        int y = (i < b.size()) ? b[b.size() - 1 - i] - '0' : 0;
        int d = x - y - brw;
        if (d < 0) {
            d += 10;
            brw = 1;
        } else brw = 0;
        r.push_back(d + '0');
    }
    while (r.size() > 1 && r.back() == '0') r.pop_back();
    reverse(r.begin(), r.end());
    return r;
}

string shiftL(const string &s, int n) {
    return s + string(n, '0');
}

string karatsuba(const string &x, const string &y) {
    string a = x, b = y;
    eqLen(a, b);
    int n = a.size();
    if (n == 1) return to_string((a[0] - '0') * (b[0] - '0'));
    int m = n / 2;
    string a1 = a.substr(0, n - m), a0 = a.substr(n - m);
    string b1 = b.substr(0, n - m), b0 = b.substr(n - m);
    string z2 = karatsuba(a1, b1);
    string z0 = karatsuba(a0, b0);
    string z1 = karatsuba(addStr(a1, a0), addStr(b1, b0));
    z1 = subStr(z1, addStr(z2, z0));
    string r = addStr(addStr(shiftL(z2, 2 * m), shiftL(z1, m)), z0);
    r.erase(0, min(r.find_first_not_of('0'), r.size() - 1));
    return r;
}

int main() {
    string a, b;
    cin >> a >> b;
    if (a == "0" || b == "0") {
        cout << "0\n";
        return 0;
    }
    cout << karatsuba(a, b) << endl;
    return 0;
}