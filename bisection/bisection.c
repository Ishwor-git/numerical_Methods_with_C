#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) (x * log10(x) - 1.2) // Define the function

void bisectionMethod() {
    float x0, x1, x2, f0, f1, f2, e = 0.0001;
    int iteration = 1;

    // Initial guesses
    x0 = 1.0;
    x1 = 3.50;

    printf("\nBisection Method\n");
    printf("\nc program by Ishwor Raj Pokharel on 2081-09-09\n");
    printf("\nInitial guess Left endpoint : %f\n", x0);
    printf("\nInitial guess Right endpoint : %f\n", x1);
    printf("\npredefined error tolerance : %f\n", e);
    printf("_________________________________________________________________________\n");
    printf("Iteration\t  x0\t\t  x1\t\t  x2\t\t  f(x2)\n");
    printf("_________________________________________________________________________\n");

    do {
        f0 = f(x0);
        f1 = f(x1);

        // Check if the initial guesses have opposite signs
        if (f0 * f1 > 0.0) {
            printf("Bisection method fails. f(x0) and f(x1) must have opposite signs.\n");
            return;
        }

        // Midpoint calculation
        x2 = (x0 + x1) / 2.0;
        f2 = f(x2);

        // Print iteration data
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", iteration, x0, x1, x2, f2);

        // Update the interval based on the sign of f(x2)
        if (f0 * f2 < 0.0) {
            x1 = x2; // Root lies in [x0, x2]
        } else {
            x0 = x2; // Root lies in [x2, x1]
        }

        iteration++;
    } while (fabs(f2) > e); // Loop until the error tolerance is met

    // Print the result
    printf("_________________________________________________________________________\n");
    printf("Root found: %.6f\n", x2);
}

int main() {
    bisectionMethod();
    return 0;
}
