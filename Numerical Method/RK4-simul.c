#include <stdio.h>
#include <conio.h>
#include <math.h>

//y' = f1(x,y,z)
double f1(double x, double y, double z)
{
    //return (3*x + y - z);
    return z;
}

//z' = f2(x,y,z)
double f2(double x, double y, double z)
{
    //return (2*x - y + z);
    return (x+2*y+z);

}

int main()
{
    double x0, y0, z0, xn, h;
    double k1, k2, k3, k4, k;
    double l1, l2, l3, l4, l;
    double a, b, c;
    int i, n;

    printf("Enter the initial condition (x, y, z): ");
    scanf("%lf%lf%lf", &x0, &y0, &z0);

    printf("Enter the final x and number of sub-intervals: ");
    scanf("%lf%d", &xn, &n);

    h = (xn-x0)/n;

    a = x0;
    b = y0;
    c = z0;

    printf("\n%12.4f %12.4f %12.4f", a, b, c);
    for(i=1; i<=n; i++)
    {
        k1 = h*f1(a, b, c);
        l1 = h*f2(a, b, c);

        k2 = h*f1(a+h/2, b+k1/2, c+l1/2);
        l2 = h*f2(a+h/2, b+k1/2, c+l1/2);

        k3 = h*f1(a+h/2, b+k2/2, c+l2/2);
        l3 = h*f2(a+h/2, b+k2/2, c+l2/2);

        k4 = h*f1(a+h, b+k3, c+l3);
        l4 = h*f2(a+h, b+k3, c+l3);

        k = (k1 + 2*(k2+k3) + k4) / 6;
        l = (l1 + 2*(l2+l3) + l4) / 6;

        a += h;
        b += k;
        c += l;
        printf("\n%12.4f %12.4f %12.4f", a, b, c);
    }

    return 0;
}
