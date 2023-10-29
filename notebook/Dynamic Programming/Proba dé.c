#include <stdio.h>
double Tab[600][100];
double prob(int n, int s, int a, int b) //s = 6n
{
    if(Tab[s][n] != -1)
    {
        return Tab[s][n];
    }
        if(n==0)
        {
            if( a<=s && s<=b)
                return 1;
            else
                return 0;
        }else
        {
             return Tab[s][n] = 1./6. * prob(n-1, s, a, b) + 1./6. * prob(n-1, s-1, a, b) + 1./6. * prob(n-1, s-2, a, b) +
                    1./6. * prob(n-1, s-3, a, b) + 1./6. * prob(n-1, s-4, a, b) + 1./6. * prob(n-1, s-5, a, b);
        }
}
 
int main()
{
    int a, b, n;
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i<=6*n; i++)
        for (int y = 0; y<=n; y++)
            Tab[i][y] = -1;
    printf("%lf\n", prob(n, 6*n, a, b));
}