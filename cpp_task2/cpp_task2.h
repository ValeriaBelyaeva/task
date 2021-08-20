#pragma once
void push(int x) {
	while (h.size() && a[t - 1] < a[x]) {
		t--;
		h.pop_back();
	}
	h.push_back(x);
}
int main();

