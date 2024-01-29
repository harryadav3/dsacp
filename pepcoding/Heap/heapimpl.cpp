#include <bits/stdc++.h>
using namespace std;

class Heap {
    private:
        vector<int> arr;
        
        int left(int i) {
            return 2 * i + 1;
        }
        int right(int i){
            return 2 * i + 2;
        }
        int parent(int i){
            return (i-1) / 2;
        }
        void maxHeapify(int index){
            if( index >= 0 && parent(index) >=  0 && arr[index] > arr[parent(index)] ){
                swap(arr[index], arr[parent(index)]);
                
               maxHeapify(parent(index));
            }
        }
        void minHeapify(int index){ // heapify down
            int l = left(index);
            int r = right(index);
            int smallest = index;
            if( l < arr.size() && arr[l] < arr[smallest] ){
                smallest = l;
            }
            if( r < arr.size() && arr[r] < arr[smallest] ){
                smallest = r;
            }
            if( smallest != index  ) {
                swap(arr[index],arr[smallest]);
                minHeapify(smallest);
            }
        }

        public:


            int size() {
                return arr.size();
            }

            void push(int data) {
                arr.push_back(data);
                // maxHeapify(arr.size() - 1);
                minHeapify(arr.size() - 1);
            }

            int pop() {
                 //extract min
                if( arr.size() == 0 ) {
                    cout << "Heap Underflow" << endl;
                    return -1;
                }
                int data = arr[0];
                swap(arr[0], arr[arr.size() - 1]);
                arr.pop_back();
                minHeapify(0);
                return data;
            }
            bool isEmpty() {
                return arr.size() == 0;
            }

            void displayheap() {
                for(int i = 0; i < arr.size(); i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            
            }
            void buildheap() {
                for ( int i= (arr.size() - 2 ) / 2 ; i >= 0; i-- ) {
                    minHeapify(i);
                }
            }
};

int main() {

    Heap h;
    vector<int> a = { 80, 40, 90, 20, 10, 70, 30, 60, 50 };

    for(int i = 0; i < a.size(); i++) {
        h.push(a[i]);
    }

    h.displayheap();

    

    return 0;
}