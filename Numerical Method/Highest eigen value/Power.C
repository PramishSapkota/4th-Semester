#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int n, i, j;
    double A[10][10], X[10], Y[10], Z[10], D[10];
    double tol_error = 5.0e-5, max_error, lambda;

    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    printf("Enter the matrix row-wise:\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%lf", &A[i][j]);

    printf("Enter the initial guess vector:\n");
    for(i=0; i<n; i++) scanf("%lf", &X[i]);



    do{
        //[Z] = [A]*[X]
        for(i=0; i<n; i++)
        {
            Z[i] = 0;
            for(j=0; j<n; j++)
            {
                Z[i] += A[i][j]*X[j];
            }
        }

        //Find largest absolute value in [Z] (with sign)
        lambda = Z[0];
        for(i=1; i<n; i++)
        {
            if(fabs(Z[i]) > fabs(lambda)) lambda=Z[i];
        }

        //Scaling, Difference Vector, and Replacement
        for(i=0; i<n; i++)
        {
            Y[i] = Z[i] / lambda;
            D[i] = fabs(Y[i] - X[i]);
            X[i] = Y[i];
        }

        //Compute maximum error
        max_error = D[0];
        for(i=1; i<n; i++)
        {
            if(D[i] > max_error) max_error=D[i];
        }

        // output of each step
        printf("\n%10.3f \t", lambda);
        for(i=0; i<n;i++) printf("%10.4f ", Y[i]);


    }while(max_error >= tol_error);


    //Print the final output
    printf("\nLargest Eigen Value = %.3f", lambda);

    printf("\nVector: ");
    for(i=0; i<n;i++) printf("%.4f ", Y[i]);


}
