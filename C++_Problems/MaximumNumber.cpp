#include <iostream>
#include <vector>
#include <algorithm>  // For max function
using namespace std;

// Function to find the maximum number of length k from a single array while preserving order
vector<int> maxNumberFromSingleArray(vector<int> nums, int k) {
    int drop = nums.size() - k;  // Number of elements we can drop to get length k
    vector<int> out;  // Vector to store the result of length k

    for (int num : nums) {
        // Keep removing elements from 'out' if they are smaller than the current number
        // and we still have elements to drop.
        while (drop && out.size() && out.back() < num) {
            out.pop_back();
            drop--;
        }
        out.push_back(num);  // Add the current number to the result
    }

    // Resize the result vector to ensure it's of length k
    out.resize(k);
    return out;
}

// Function to merge two arrays to form the maximum possible number while preserving order
vector<int> mergeMaxNumber(vector<int> nums1, vector<int> nums2) {
    vector<int> out;  // Vector to store the merged result
    while (!nums1.empty() || !nums2.empty()) {
        // Compare the two vectors and take the greater lexicographical number
        vector<int>& now = (nums1 > nums2) ? nums1 : nums2;
        out.push_back(now[0]);  // Add the maximum number from the selected array
        now.erase(now.begin());  // Remove the used number
    }
    return out;
}

// Function to find the maximum number of length k from two arrays nums1 and nums2
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> best;  // To store the best maximum number found

    // Try all possible splits of length k between nums1 and nums2
    for (int k1 = max(k - n2, 0); k1 <= min(k, n1); ++k1) {
        // Get the maximum number from nums1 of length k1 and from nums2 of length (k - k1)
        vector<int> candidate = mergeMaxNumber(
            maxNumberFromSingleArray(nums1, k1),
            maxNumberFromSingleArray(nums2, k - k1)
        );
        // Update the best result if the candidate is greater
        best = max(best, candidate);
    }

    return best;  // Return the best possible result
}

int main() {
    int m, n, k;

    // Input the size of the first array
    cout << "Enter the number of elements in the first array (nums1): ";
    cin >> m;
    vector<int> nums1(m);
    cout << "Enter the elements of nums1: ";
    for (int i = 0; i < m; ++i) {
        cin >> nums1[i];
    }

    // Input the size of the second array
    cout << "Enter the number of elements in the second array (nums2): ";
    cin >> n;
    vector<int> nums2(n);
    cout << "Enter the elements of nums2: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }

    // Input the value of k
    cout << "Enter the value of k (length of the result array): ";
    cin >> k;

    // Call the function to get the maximum number of length k
    vector<int> result = maxNumber(nums1, nums2, k);

    // Output the result
    cout << "The maximum number of length " << k << " is: ";
    for (int num : result) {
        cout << num;
    }
    cout << endl;

    return 0;
}
