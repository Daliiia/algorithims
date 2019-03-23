
#include <iostream>

using namespace std;
class DisjointSet{
public:
    int Size;
    int *parent;
    int *weight;
    bool *visited;

void intialize(int n){
    Size=n;
    parent = new int[n];
    weight = new int[n];
    visited = new bool[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
        weight[i]=0;
        visited[i]=false;
    }
}
void destroy(){
    delete [] parent;
    delete [] weight;
    delete [] visited;
 }
int Find(int index){
    if(index==parent[index]) return parent[index];
    return Find(parent[index]);
}
bool Union(int a,int b){
    if(Find(a)==Find(b)) return false;
    if(weight[a]>weight[b]){
        parent[b]=Find(a);
        weight[a]++;
    }
    else if(weight[a]<=weight[b]){
            parent[a]=Find(b);
            weight[b]++;
    }
    return true;
}


};
int main(){
DisjointSet d;
int n;
cin>>n;
d.intialize(n);
d.Union(0,2);
d.Union(3,6);
d.Union(2,6);
d.Union(1,2);
cout<<"union "<<d.Union(1,2)<<endl;
for(int i=0;i<n;i++){
    cout<<"node "<<i<<" has parent "<<d.parent[i]<<endl;
}

return 0;
}
