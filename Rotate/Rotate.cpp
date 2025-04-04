// Rotate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {// copy array
        int n = nums.size();
        vector<int>nums2(n);
        for (int i = 0; i < n; i++) {
            nums2[(i + k) % n] = nums[i];
        }

        for (int i = 0; i < n; i++) {
            nums[i] = nums2[i];
        }



    }

};

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void RotateRight(vector<int>& nums)
    {
        int last = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--) 
        {
            nums[i + 1] = nums[i];
        }
        nums[0] = last;
    }

    void rotate(vector<int>& nums, int k) 
    {
        int size = nums.size();
        k %= size; // Avoid unnecessary full rotations
        while (k--) 
        {
            RotateRight(nums);
        }
    }
};

int main() {
    vector<int> nums = { 1, 2, 3, 4, 5 };
    int k = 2;

    Solution sol;
    sol.rotate(nums, k);

    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}

//////////
// 
using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size; // Handle cases where k > size

        // Step 1: Reverse entire array
        reverse(nums, 0, size - 1);

        // Step 2: Reverse first k elements
        reverse(nums, 0, k - 1);

        // Step 3: Reverse remaining elements
        reverse(nums, k, size - 1);
    }
};

int main() {
    vector<int> nums = { 1, 2, 3, 4, 5 };
    int k = 2;

    Solution sol;
    sol.rotate(nums, k);

    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}

// 
// 1ms
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k > n

        // Step 1: Reverse the entire array using a loop
        reverseWithLoop(nums, 0, n - 1);

        // Step 2: Reverse the first k elements using a loop
        reverseWithLoop(nums, 0, k - 1);

        // Step 3: Reverse the remaining n-k elements using a loop
        reverseWithLoop(nums, k, n - 1);
    }

    void reverseWithLoop(vector<int>& nums, int start, int end) {
        while (start < end) {
            // Swap elements using a loop
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};
// 
// 
// 
// class Solution {
//public:// 2ms
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
