#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {
    int n, x;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        max_heap.push(x);
        
        if (max_heap.size() > min_heap.size() + 1) {
            int m = max_heap.top(); max_heap.pop();
            min_heap.push(m);
        } else if (min_heap.size() > max_heap.size()) {
            int m = min_heap.top(); min_heap.pop();
            max_heap.push(m);
        }
        
        if (max_heap.size() == min_heap.size()) {
            double median = (max_heap.top() + min_heap.top()) / 2.0;
            cout << fixed << setprecision(1) << median << endl;
        } else {
            cout << fixed << setprecision(1) << max_heap.top() << endl;
        }
    }
    
    return 0;
}
