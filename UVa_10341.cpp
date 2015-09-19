/* Taking derivative of original function shows that the function vakue is
 * decling on the [0,1]. Then using the bisection method to approach the answer
 * within the available range.
*/

#include <stdio.h>
#include <math.h>
double p,q,r,s,t,u;

double f(double x)
{
    double ans=p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
    return ans;
}
int main()
{
    double a1,a2,ans,k;
    while(~scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u))
    {
        a1=0;a2=1;
        if(f(0)*f(1)>0) printf("No solution\n");
        else
        {
            while(a2-a1>0.000000001)
            {
                ans=a1+(a2-a1)/2;
                k=f(ans);
                if(k<0) a2=ans;
                else a1=ans;
            }
            printf("%.4lf\n",a1);
        }
    }
    return 0;
}
