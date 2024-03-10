#include <stdio.h>
#include <conio.h>
#include <math.h>

//y' = f(x,y)
double f(double x, double y)
{
    return (x*x - y);
}

int main()
{
    double x0, y0, xn, h, k1, k2, k3, k4, k;
    double a, b;
    int i, n;

    printf("Enter the initial condition (x,y): ");
    scanf("%lf%lf", &x0, &y0);

    printf("Enter the final x and number of sub-intervals: ");
    scanf("%lf%d", &xn, &n);

    h = (xn-x0)/n;

    a = x0;
    b = y0;

    printf("\n%12.4f %12.4f", a, b);
    for(i=1; i<=n; i++)
    {
        k1 = h*f(a,b);
        k2 = h*f(a+h/2,b+k1/2);
        k3 = h*f(a+h/2,b+k2/2);
        k4 = h*f(a+h,b+k3);

        k = (k1 + 2*(k2+k3) + k4) / 6;

        a += h;
        b += k;
        printf("\n%12.4f %12.4f", a, b);
    }

    return 0;
}
