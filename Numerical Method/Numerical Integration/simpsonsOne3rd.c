#include <stdio.h>
#include <conio.h>
#include <math.h>

double f(double x)
{
    return (sin(x)+cos(x) + 5);
}

int main()
{
    double a, b, h, sum;
    int i, n, m;

    do{
        printf("Enter the limits of integration: ");
        scanf("%lf%lf", &a, &b);
    }while(a > b);

    do{
        printf("Divide into how many sub-intervals? ");
        scanf("%d", &n);
    }while(n<2 || n%2 != 0);

    h = (b-a)/n;

    sum = f(a) + f(b); // y0 + yn

    for(i=1; i<n; i++)
    {
        if(i%2 == 0)
            m = 2;
        else
            m = 4;

        sum = sum + m*f(a+i*h);
    }

    sum = sum * h/3;


    printf("Integral value : %f", sum);

    return 0;
}
