// Code to find frequency of elements in a given array in O(1) time complexity.
// Submitted on geek for geek also

#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    int arr[] = {1, 3, 2, 1, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    cout << "Element  Frequency" << endl;
    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); ++it) {
        cout << setw(7) << it->first << "  " << setw(9) << it->second << endl;
    }

    return 0;
}
