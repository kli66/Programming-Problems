#include <queue>
#include <algorithm>
#include <cstdio>
#include <map>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>


#define loc_xy pair<int,int>
using namespace std;

int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

int check(loc_xy p){
    int x=p.first;
    int y=p.second;
    if((x>=0 && x<8) && (y>=0 && y<8))
        return 1;
    else
        return 0;
}

void bfs(int x,int y,int xf,int yf){
    map<loc_xy,int> dist_map;
    dist_map[loc_xy(x,y)]=0;
    queue<loc_xy> Q;
    Q.push(loc_xy(x,y));
    loc_xy inspecting, curr_dest;
    int found = 0;

    while(!Q.empty()){
        inspecting=Q.front();
        Q.pop();
        for(int z=0; z<8; z++){
            curr_dest=make_pair(inspecting.first+xMove[z],inspecting.second+yMove[z]);
            if(check(curr_dest)){
                if(dist_map.find(curr_dest)==dist_map.end()){
                    if(curr_dest.first==xf && curr_dest.second==yf){
                        found=1;
                    }
                    dist_map[curr_dest]=dist_map[inspecting]+1;
                    Q.push(curr_dest);
                }
            }
        }
        if(found){
            break;
        }
    }
    cout<<dist_map[make_pair(xf,yf)]<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1;
        cin>>s2;
        if(s1==s2){
            cout<<0<<endl;
            continue;
        }
        int x1,x2,y1,y2;
        y1=(s1[1]-'0');
        y2=(s2[1]-'0');
        y1--;
        y2--;
        x1=s1[0]-'a';
        x2=s2[0]-'a';
        bfs(x1,y1,x2,y2);
    }
}
