from math import fabs as abs
def func():
N, eps = 1000000, 1e-7
h = [0 for _ in range(N)]
a = [0 for _ in range(N)]

def push(x):
    global t, h, s, a
    while s < t and a[h[t - 1]] < a[x]:
        t -= 1
    h[t] = x;  t += 1


n, C = input().split()
n = int(n)
C = float(C)

for i in range(n - 1):
    a[i] = int(input())


a = tuple(a)
p = [0 for i in range(n)]

s = 0; t = 0
i = 0; j = 1
l = C ; r = 0
push(0)

while j < n and i < j and l > (a[j - 1] + eps):
    ev1 = (l - r) * (j - i) / (j - i + 1)

    if s < t:
        ev2 = (l - a[h[s]]) * (j - i)
        ev = min(ev2, ev1)
    else: ev = ev1

    l -= ev / (j - i)
    r += ev

    if abs(l - r) < eps:
        push(j)
        j += 1; r = 0

    if abs(l - a[h[s]]) < eps:
        x = h[s]
        s += 1
        while i <= x:
            p[i] = l
            i += 1
        i = x + 1 

    if i == j or l < (a[j - 1] + eps):
        while i < j:
            p[i] = l
            i += 1
        l = r; r = 0
        i = j
        push(j); j += 1

while i < j:
    p[i] = l
    i += 1

for i in range(n):
    print(p[i])