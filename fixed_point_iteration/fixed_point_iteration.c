#include <stdio.h>
#include <math.h>
#define g(x) (cbrt(2*x + 5)) // Define g(x)

void fixedPointIteration() {
    float x0, x1, n,e = 0.0001;
    int iteration = 1;
    x0 = 0.0;
    n = 10;

    printf("\nFixed Point Iteration Method\n");
    printf("\nc program by Ishwor Raj Pokharel on 2081-09-09\n");
    printf("\nInitial guess  : %f\n", x0);
    printf("\nMaximum number of iteration : %f\n", n);
    printf("\npredefined error tolerance : %f\n", e);
    printf("_________________________________________________________________________\n");
    printf("Iteration\t  x0\t\t  x1\t\t  g(x)\n");
    printf("_________________________________________________________________________\n");

    // Initial guess

    do {
        x1 = g(x0); // Compute next point
        printf("%d\t\t%.6f\t%.6f\t%.6f\n", iteration, x0, x1, g(x0));

        if (fabs(x1 - x0) < e) {
            printf("_________________________________________________________________________\n");
            printf("Root found: %.6f\n", x1);
            return;
        }

        x0 = x1;
        iteration++;
    } while (iteration < n);

    printf("_________________________________________________________________________\n");
    printf("Method failed to converge.\n");
}

int main() {
    fixedPointIteration();
    return 0;
}
