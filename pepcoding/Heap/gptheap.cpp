#include <vector>
#include <algorithm> // for std::swap
#include <stdexcept> // for std::out_of_range

using namespace std;

template <typename T>
class Heap {
private:
    vector<T> heap;
    bool isMinHeap;

public:
    // Constructor to initialize the heap type (min-heap or max-heap)
    Heap(bool isMin = true) : isMinHeap(isMin) {}

    // Function to push a new element onto the heap
    void push(T element) {
        heap.push_back(element);
        int index = heap.size() - 1;
        if (isMinHeap)
            minHeapifyUp(index);
        else
            maxHeapifyUp(index);
    }

    // Function to pop the top element from the heap
    void pop() {
        if (heap.empty()) {
            // Handle empty heap
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (isMinHeap)
            minHeapifyDown(0);
        else
            maxHeapifyDown(0);
    }

    // Function to delete a specific element from the heap
    void deleteElement(T element) {
        auto it = find(heap.begin(), heap.end(), element);
        if (it != heap.end()) {
            int index = distance(heap.begin(), it);
            heap[index] = heap.back();
            heap.pop_back();
            if (isMinHeap)
                minHeapifyDown(index);
            else
                maxHeapifyDown(index);
        }
    }

    // Function to get the top element of the heap
    T top() const {
        if (heap.empty()) {
            // Handle empty heap
            throw out_of_range("Heap is empty");
        }
        return heap.front();
    }

private:
    // Helper function to maintain the min-heap property
    void minHeapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] > heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Helper function to maintain the max-heap property
    void maxHeapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Helper function to maintain the min-heap property
    void minHeapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            minHeapifyDown(smallest);
        }
    }

    // Helper function to maintain the max-heap property
    void maxHeapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            maxHeapifyDown(largest);
        }
    }
};
