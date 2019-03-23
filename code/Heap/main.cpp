#include <iostream>

using namespace std;
class Heap{
public:
int *heap;
int capacity=0;
int heapSize=0;
void intialize(int n){
    heap=new int[n];
    capacity=n;
}
int heapify(int i){
    if(i==0) return 1;
    if(heap[i]<heap[(i-1)/2])
        swap(heap[i],heap[(i-1)/2]);
    heapify((i-1)/2);
}

bool add(int val){
if(capacity==heapSize) return false;
heapSize++;
heap[heapSize-1]=val;
heapify(heapSize-1);
}
void heapifyMax(int i){
   if(i>=heapSize) return;
   int smallest =i;
    if(heap[i]>heap[2*i+1]){
        smallest=2*i+1;
        }
    if(heap[smallest]> heap[2*i+2]){
        smallest=2*i+2;
    }
    if(smallest!=i){
         swap(heap[i], heap[smallest]);
        heapifyMax(smallest);
    }
}
void extractMin(){
    heap[0]=heap[heapSize-1];
    heapifyMax(0);
    heapSize--;
}

void extractMax(){
    heapSize--;
     }
int MinHeap(){return heap[0];}

};
int main()
{
Heap h;
h.intialize(3);
h.add(2);

h.add(1);

h.add(3);

for(int i=0;i<3;i++){

    cout<<"array "<<i<<"___"<<h.heap[i]<<endl;
}
cout<<h.MinHeap()<<endl;
h.extractMin();
cout<<h.MinHeap()<<endl;
for(int i=0;i<2;i++){

    cout<<"array "<<i<<"___"<<h.heap[i]<<endl;
}
    return 0;
}
