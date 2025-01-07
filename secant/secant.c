#include <stdio.h>
#include <math.h>

#define f(x) (x * log(x) - 1.2) // Define the function f(x)

void secantMethod() {
    float x0, x1, x2, f0, f1, f2, e = 0.0001;
    int iteration = 1, n = 10; // n is the maximum number of iterations

    // Initial guesses
    x0 = 1.0;
    x1 = 2.5;

    printf("\nSecant Method\n");
    printf("\nc program by Ishwor Raj Pokharel on 2081-09-09\n");
    printf("\nInitial guess x0 : %f\n", x0);
    printf("\nInitial guess x1 : %f\n", x1);
    printf("\nMax number of iterations : %d\n", n);
    printf("\nPredefined error tolerance : %f\n", e);
    printf("_________________________________________________________________________\n");
    printf("Iteration\t  x0\t\t  x1\t\t  x2\t\t  f(x2)\n");
    printf("_________________________________________________________________________\n");

    do {
        f0 = f(x0);
        f1 = f(x1);

        // Secant Method formula
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0); 
        f2 = f(x2);

        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", iteration, x0, x1, x2, f2);

        // Update the guesses
        x0 = x1;
        x1 = x2;
        iteration++;

        // Check for convergence
        if (fabs(f2) < e) {
            printf("_________________________________________________________________________\n");
            printf("Root found: %.6f\n", x2);
            return;
        }

    } while (iteration <= n);

    printf("_________________________________________________________________________\n");
    printf("Method failed to converge within %d iterations.\n", n);
}

int main() {
    secantMethod();
    return 0;
}
