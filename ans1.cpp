#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    int fact=1;
    for(int i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    return fact;
}

int main()
{
    int n;scanf("%d",&n);
    int b[n];
    char a[n];
    for(int i=0;i<n;i++)
    {cin>>a[i];}
    sort(a,a+n);
    string word;
    cin>>word;
    /*all possible words*/
    int rank=1, i,j;
    for(i=0;i<n;i++)
    {   for(j=0;j<n;j++)
        {   if(i==0)
            {   if(word[i]==a[j])
                {
                    b[i]=j;
                    rank+=j*fact(n-i-1);
                }
            }
            else
            {
                if(word[i]==a[j])
                {   int count=0;
                    for(int k=0;k<i;k++)
                    { if(j>b[k])
                    {count++;}
                    }
                    b[i]=j;
                    int z=j-count;
                    rank+=z*fact(n-i-1);
                }
            }
        }
    }
    printf("%d",rank);
    return 0;
}
