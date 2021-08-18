#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#define NN 1000000
#define eps 1e-7

int n;
double C;
double a[NN], p[NN];
int h[NN];
int s, t, i, j;
double l, r;



double
get_h(void)
{
    assert(s < t);
    return a[h[s]];
}

int
pop_h(void)
{
    assert(s < t);
    return h[s++];
}

void
push_h(int x)
{
    while (s < t && a[h[t - 1]] < a[x])
        t--;
    h[t++] = x;
}

int
main(int argc, char* argv[])
{
    double ev, ev1, ev2;
    int x;
    scanf("%d%lf", &n, &C);
    for (i = 0; i < n - 1; i++)
        scanf("%lf", &a[i]);

    for (i = 0; i < n; i++)
        p[i] = 0;
    s = 0; t = 0;
    i = 0; j = 1;
    l = C; r = 0;
    push_h(0);
    //   printf('\n');

    while (j < n && i < j && l > a[j - 1] + eps)
    {
        ev1 = (l - r) * (j - i) / (j - i + 1);
        if (s < t)
        {
            ev2 = (l - get_h()) * (j - i);
            ev = (ev1 < ev2) ? ev1 : ev2;
        }
        else
            ev = ev1;
        l -= ev / (j - i);
        r += ev;
        assert(l + eps > r);
        if (fabs(l - r) < eps)
        {
            push_h(j);
            j++;
            r = 0;
        }
        if (fabs(l - get_h()) < eps)
        {
            x = pop_h();
            for (; i <= x; i++) {
                p[i] = l;
            }
            i = x + 1;
        }
        if ((i == j) || (l < a[j - 1] + eps))
        {
            for (; i < j; i++) {
                p[i] = l;
            }
            l = r;
            r = 0;
            i = j;
            push_h(j);
            j++;
        }
    }
    for (; i < j; i++) {
        p[i] = l;
    }

    for (i = 0; i < n; i++)
        printf("%0.20lf\n", p[i]);

    return 0;
}