#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void bucketSort(vector<int>& marks) {
    // Create buckets
    vector<vector<int>> buckets(360);

    // Distribute marks into buckets
    for (int i=0; i<360; i++) {
        
        buckets[i].push_back(marks[i]);
    }

    // Sort each bucket
    for (int i = 0; i < 360; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    for (int i = 0; i < 360; ++i) {
        marks.insert(marks.end(), buckets[i].begin(), buckets[i].end());
    }
}

int main() {
    vector<int> studentMarks = {150, 270, 90, 330, 45, 200, 100, 320, 80, 360};

  
    cout << "Original Marks: ";
    for (int mark : studentMarks) {
        cout << mark << " ";
    }
    cout << endl;

    // Perform bucket sort
    bucketSort(studentMarks);

    // Display sorted marks
    cout << "Sorted Marks: ";
    for (int mark : studentMarks) {
        cout << mark << " ";
    }
    cout << endl;

    return 0;
}
