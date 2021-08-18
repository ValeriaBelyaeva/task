#include <iostream>
#include <vector>
#define sz 1000000
#define eps 1e-7
using namespace std;

vector<double> a(sz), p(sz, 0);
vector<int> h(sz);
double e, e1, e2;
int s, t, i, j;
double l, r;
double C;
int n;

void push_h(int x) {
    while (s < t && a[h[t - 1]] < a[x])
        t--;
    h[t++] = x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(10);
    int x;
    cin >> n >> C;

    for (i = 0; i < n - 1; i++) cin >> a[i];
    
    s = 0; t = 0;
    i = 0; j = 1;
    l = C; r = 0;
    push_h(0);

    while (j < n && i < j && l > a[j - 1] + eps) {
        e1 = (l - r) * (j - i) / (j - i + 1);
        if (s < t)
        {
            e2 = (l - a[h[s]]) * (j - i);
            e = (e1 < e2) ? e1 : e2;
        }
        else e = e1;

        l -= e / (j - i);
        r += e;
        if (fabs(l - r) < eps) {
            push_h(j++); r = 0;
        }
        if (fabs(l - a[h[s]]) < eps) {
            x = h[s++];
            for (i; i <= x; i++)
                p[i] = l; 
            i = x + 1;
        }
        if ((i == j) || (l < a[j - 1] + eps)) {
            for (; i < j; i++)
                p[i] = l;
            l = r; r = 0;
            i = j;
            push_h(j++);
        }
    }
    for (i; i < j; i++) p[i] = l;
    for (i = 0; i < n; i++) cout << p[i] << "\n";

    return 0;
}