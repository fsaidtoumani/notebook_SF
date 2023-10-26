#include <stdio.h>

double prob(int n, int s, int a, int b) //s = 6n
{
    {
        if(n==0)
        {
            if( a<=s && s<=b)
                return 1;
            else
                return 0;
        }else
        {
            return 1./6. * prob(n-1, s, a, b) + 1./6. * prob(n-1, s-1, a, b) + 1./6. * prob(n-1, s-2, a, b) +
                    1./6. * prob(n-1, s-3, a, b) + 1./6. * prob(n-1, s-4, a, b) + 1./6. * prob(n-1, s-5, a, b);
        }
    }
}

int main()
{
    int a, b, n;
    scanf("%d %d %d", &n, &a, &b);
    printf("Prob = %lf\n", prob(n, 6*n, a, b));
}
