#include<iostream>
using namespace std;
int a[107];
void printmask(int mask,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(mask%2)
        {
            cout<<a[i]<<' ';
        }
        mask/=2;
    }
}
 
int main()
{
    int n, number;
    cin>>n >> number;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int mask=1;mask<(1<<n);mask++)
    {
        int tmp=mask,cur_sum=0;
        for(int i=1;i<=n;i++)
        {
            if(tmp%2)
            {
                cur_sum+=a[i];
            }
            tmp/=2;
        }
        if(cur_sum==number)
        {
            cout<<"OMG!!! It's impossible, but I found subset with zero sum!!! Let's dance!!! Here it is: ";
            printmask(mask,n);
            return 0;
        }
    }
    cout<<"Okay... There is no subset with zero sum is this set. I'm so sorry..."<<endl;
}