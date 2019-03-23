#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
public:
    int weight;
    pair<int,int> path;
};
///O(Log V) Disjoint +Sort
class Kruskal{
public:
    int arr[7];
    int w[7];
        int Find(int a){
        if(arr[a]==a) return a;
        return Find(arr[a]);
    }

    int Union(int a,int b){
        if(w[a]>w[b]) {
            arr[b]=Find(a);
            w[a]++;
        }
        else{
            arr[a]=Find(b);
            w[b]++;
        }

    }
    Kruskal(){
        for(int i=0;i<7;i++){
            arr[i]=i;
            w[i]=1;

        }
    }
    int kruskal(Graph g[]){
        int cost=0;
        for(int i=0;i<7;i++){
            if(Find(g[i].path.first)==Find(g[i].path.second)){
                    continue;
                    }
            else{
                Union(g[i].path.first,g[i].path.second);
                cost+=g[i].weight;

            }
        }
        ///test
       /* for(int i=0;i<5;i++){
            cout<<"***"<<arr[i]<<"<<"<<i<<endl;

        }*/
        return cost;
    }




};
int main()
{ Graph g[7];
g[0].path=make_pair(0,1);
g[0].weight=1;
g[1].path=make_pair(3,4);
g[1].weight=2;
g[2].path=make_pair(1,4);
g[2].weight=3;
g[3].path=make_pair(1,3);
g[3].weight=4;
g[4].path=make_pair(1,2);
g[4].weight=5;
g[5].path=make_pair(2,4);
g[5].weight=6;
g[6].path=make_pair(0,2);
g[6].weight=7;
Kruskal k;
cout<<k.kruskal(g)<<endl;
    return 0;
}
