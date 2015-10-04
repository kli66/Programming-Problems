#include <iostream>
using namespace std;
int main(){
    int n,b,h,w,p,a;
    while(cin>>n>>b>>h>>w){
        int ans=500008;
        for(int z=0;z<h;z++){
            cin>>p;
            for(int i=0;i<w;i++){
                cin>>a;
                if(a>=n&&p*n<ans){
                    ans=p*n;
                }
            }
        }
        if(ans>b)cout<<"stay home"<<endl;
        else cout<<ans<<endl;
    }
}
