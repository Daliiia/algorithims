#include <iostream>

using namespace std;
class Item{
public:
    string name;
    int value;
    int weight;
};

class KnapSack{
public:
    int knapsack(int i,int Max,Item arr[]){
        if(i<0) return 0;
        int ret=knapsack(i-1,Max,arr);
        if(arr[i].weight<=Max){
            Max-= arr[i].weight;
            return max(ret,knapsack(i-1,Max,arr)+arr[i].value);
        }

        return ret;
    }

};
int main()
{ int MaxWeight=50;
    Item i[3];
    KnapSack k;
    i[0].weight=10;
    i[0].value=60;
    i[1].weight=20;
    i[1].value=100;
    i[2].weight=30;
    i[2].value=120;
    cout<<"optimal solution: "<<k.knapsack(3,50,i)<<endl;

    return 0;
}
