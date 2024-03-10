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
    double x0, y0, xn, h, k;
    double a, b;
    int i, n;

    printf("Enter the initial condition (x,y): ");
    scanf("%lf%lf", &x0, &y0);//lf represents long float

    printf("Enter the final x and number of sub-intervals: ");
    scanf("%lf%d", &xn, &n);

    h = (xn-x0)/n;

    a = x0;
    b = y0;

    printf("\n%12.4f %12.4f", a, b);
    for(i=1; i<=n; i++)
    {
        k = h*f(a,b);
        a += h;
        b += k;
        printf("\n%12.4f %12.4f", a, b);
    }

    return 0;
}
