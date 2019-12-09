/*
 * C program to input a infinate number of real numbers from stdin and find the
 * mean, variance and standard deviation with out using any arraies.
 *
 * To build: gcc -Wall -O3 -o stats stats.c -lm
 * To run: cat data | ./stats
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main()
{
    double element, average, variance, std_deviation;
    double count = 0, xmax = 0, xmin = 0, sum = 0, sum2 = 0;

    /*  Compute the needed terms of all elements */
    while (scanf("%lf", &element) == 1) 
    {
        sum += element;
        sum2 += element * element;
        count++;
        if (element < xmin)
           xmin = element;
        else if (element > xmax)
                xmax = element;
    }

    printf("Number of elements = %.0f\n", count);

    /* Report min and max of elements */
    printf("Range of elements (max = %2lf - min = %.2lf) = %.2lf\n", xmax, xmin, xmax-xmin);

    /*  Compute  average */
    average = sum / count;
    printf("Average of all elements = %.2lf\n", average);

    /*  Compute variance */
    variance = (count * sum2 - sum * sum) / (count * count);
    printf("Variance of all elements = %.2lf\n", variance);

    /*  Compute and standard deviation  */
    std_deviation = sqrt(variance);
    printf("Standard deviation = %.2lf\n", std_deviation);

    /*  Compute Sigmas */
    printf("Plus and Minus One sigma (68%%) = %.2lf %.2lf  Range = %.2lf\n", 
	average - std_deviation, average + std_deviation, 2 * std_deviation);
    printf("Plus and Minus Two sigma (95%%)= %.2lf %.2lf  Range = %.2lf\n", 
	average - 2 * std_deviation, average + 2 * std_deviation, 4 * std_deviation);
    printf("Plus and Minus Three * sigma (99%%) = %.2lf %.2lf  Range = %.2lf\n", 
	average - 3 * std_deviation, average + 3 * std_deviation, 6 * std_deviation);

    exit(0);
}
