#include <cstdio>
#include <cmath>
#include <cstdlib>
#define PI 3.141592654

double point[3][2], ql[3], cosa[3], qsina[3], qr, s;
unsigned i, a[3], res, g, b[3] = {0}, c[3], d, mind;

int main()
{
    for (i = 0; i < 3; i++)
        scanf("%lf%lf", &point[i][0], &point[i][1]);
    for (i = 0; i < 3; i++)
        ql[i] = (point[i][0] - point[(i + 1) % 3][0]) * (point[i][0] - point[(i + 1) % 3][0]) + (point[i][1] - point[(i + 1) % 3][1]) * (point[i][1] - point[(i + 1) % 3][1]);
    for (i = 0; i < 3; i++)
    {
        cosa[i] = (ql[(i + 2) % 3] + ql[(i + 1) % 3] - ql[i]) / (2 * sqrt(ql[(i + 1) % 3]) * sqrt(ql[(i + 2) % 3]));
        qsina[i] = 1 - cosa[i] * cosa[i];
        a[i] = acos(cosa[i]) * 1e5;
    }
    qr = (ql[0] / qsina[0] + ql[1] / qsina[1] + ql[2] / qsina[2]) / 12;
    b[0] = b[1] = b[2] = 1;
    mind = ~0;
    do
    {
        c[0] = a[0] / b[0];
        c[1] = a[1] / b[1];
        c[2] = a[2] / b[2];
        d = abs(c[0] - c[1]) + abs(c[1] - c[2]) + abs(c[2] - c[0]);
        if (mind > d)
        {
            mind = d;
            res = b[0] + b[1] + b[2];
        }

        i = 0;
        if (a[0] / b[0] < a[1] / b[1])
            i = 1;
        if (a[i] / b[i] < a[2] / b[2])
            i = 2;
        ++b[i];
    } while (b[0] + b[1] + b[2] <= 100);
    s = qr * sin(2 * PI / res) * res / 2;
    printf("%.8lf\n", s);
    return 0;
}