#include<stdio.h>

void numPattern(int n)
{
    for(int i=n; i>=1; i--)
    {
        for(int j=1; j<=i; j++)
            printf("%d ",i);
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    numPattern(n);
}
