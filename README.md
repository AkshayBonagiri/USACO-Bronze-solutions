# USACO-Bronze-solutions
# 💎 Diamond Collector – USACO Bronze

## 📌 Problem Summary

You are given a list of diamonds with different sizes. You are allowed to pick a subset of diamonds such that the difference between the smallest and largest diamond in that subset is at most `k`.

The goal is to **maximize the number of diamonds** you can collect under this constraint.

---

## 🚀 Approach

### 🧠 Strategy

- **Sort the diamond sizes**: Since we need to find ranges with limited difference, sorting helps us efficiently scan valid ranges.
- **Use a sliding window (two-pointer approach)**:
  - For every `i`, find the farthest `j` such that `array[j] - array[i] <= k`
  - This gives the maximum number of diamonds that can be collected starting at index `i` and staying within the size constraint.
- Keep track of the maximum count obtained from all such valid windows.

---

## 💻 Code

```cpp
#include <iostream>
#include <vector>
#include <climits>

int main() {
    int array[] = {1, 6, 4, 3, 1};
    int k = 3;
    int size = sizeof(array) / sizeof(array[0]);
    std::vector<int> ans_array;

    // Bubble Sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Find the max number of diamonds collectible within range k
    for(int i = 0 ; i < size ; i++){
        int j = i + 1;
        for(j = i + 1 ; j < size ; j++){
            if(array[j] - array[i] > k){
                break;
            }
        }
        j--;
        int values = (j - i) + 1;
        ans_array.push_back(values);
    }

    // Find max
    int max = INT_MIN;
    for(int val : ans_array){
        std::cout << val << " ";
        if(val > max){
            max = val;
        }
    }
    std::cout << "\nMax Diamonds: " << max << std::endl;

    return 0;
}

