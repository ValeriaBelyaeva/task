#include <iostream>
#include <fstream> 
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main(){
	int n; 
	double h1;
	cin >> n >> h1;
	double l = 0, r = h1;
	double last = -1;
	while (r - l > 0.0000000001 / (n - 1)) {
		double mid = (l + r) / 2;
		double prev = h1;
		double cur = mid;
		bool ground = cur > 0;
		for (int i = 3; i <= n; i++) {
			double next = 2 * cur - prev + 2;
			ground &= next > 0;
			prev = cur;
			cur = next;
		}
		if (ground) {
			r = mid;
			last = cur;
		}
		else {
			l = mid;
		}
	}
	cout << fixed << setprecision(10) << last;
	return 0;
}