//Binomial distribution calculator
//Made by Carter Rows

#include <stdio.h>
#include <math.h>

double binomial(double a, double b, double c);
double factorial(double n);

int main()
{
    printf("\nWelcome to my Binomial distribtuion calculator!\n");

    double sampleSpace;
    printf("\nPlease enter size of the sample space:\t");
    scanf("%lf", &sampleSpace);

    double p;
    printf("Please enter value for P(success):\t");
    scanf("%lf", &p);
    
    double x;
    printf("Please enter your 'x' value:\t");
    scanf("%lf", &x);

    //probability X = x
    double equal = binomial(sampleSpace, p, x);
    printf("\nP(X = %.0lf) = %.5lf \n", x, equal);

    //probability X <= x
    double lessEqual = 0;
    for(int i = 0; i <= x; i++)
    {
        lessEqual += binomial(sampleSpace, p, i);
    }
    printf("\nP(X <= %.0lf) = %.5lf\n", x, lessEqual);

    //probability X < x
    double less;
    less = lessEqual - equal;
    printf("P(X < %.0lf) = %.5lf\n", x, less);

    //probability X >= x
    double greaterEqual = 0;
    for(int j = 0; j < x; j++)
    {
        greaterEqual += binomial(sampleSpace, p, j);
    }
    printf("\nP(X >= %.0lf) = %.5lf\n", x, (1 - greaterEqual));

    //probability X > x
    double greater;
    greater = 1 - greaterEqual - equal;
    printf("P(X > %.0lf) = %.5lf\n\n", x, greater);
    
    return 0;
}

double factorial(double n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

double binomial(double a, double b, double c)
{
    double temp1 = factorial(a) / (factorial(c) * factorial(a - c));
    double result = temp1 * pow(b, c) * pow(1 - b, a - c);
    
    return result;
}
