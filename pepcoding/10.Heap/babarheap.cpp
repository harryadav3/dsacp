#include <bits/stdc++.h>
using namespace std;


class heap {

    public:
    int arr[100];
    int size = 0;

    heap() {
        arr[0] = -1;
        size = 0;
        }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1 ) {
            int parent = index/2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return ;
            }
        }
    }

    void deletefromheap() {
        if(size == 0){
            cout << "nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while( i< size) {
            int left = 2 * i;
            int right = 2 * i + 1;


            if(left < size && arr[i] < arr[left]) {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if(right < size && arr[i] < arr[right]) {
                swap(arr[i], arr[right]);
                i = right;
            }
            else {
                return;
            }
        }
    }
    
    void print() {
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        } cout<<endl;
    }
};

void heapify( int arr[], int n, int i) {
    int largetst  = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left < n && arr[left] > arr[largetst]) {
        largetst = left;
    }

    if(right < n && arr[right] > arr[largetst]) {
        largetst = right;
    }

    if(largetst != i) {
        swap(arr[i], arr[largetst]);
        heapify(arr, n, largetst);
    }

}



int main() {

   heap h;
   h.insert(10);
   h.insert(20);
   h.insert(30);
   h.insert(40);
   h.insert(50);

   h.print(); 

    return 0;
}