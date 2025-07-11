#include <iostream>
#include <vector>

int main() {
    int array[] = {1,6,4,3,1};
    int k = 3;
    int size = sizeof(array) / sizeof(array[0]); // Calculate array size
    std::vector<int> ans_array;

    // Bubble Sort Algorithm
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap if elements are in the wrong order
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // // Print sorted array
    // for (int c = 0; c < size; c++) {
    //     std::cout << array[c] << " ";
    // }


    //OUTPUT :- 1   1   3   4   6
    //INDEX:-   0   1   2   3   4
    //     j =  3   3   4   4   4
    for(int i = 0 ; i < size ; i++){
        int values = 1;
        
        
        // for(int j = i + 1 ; j < size - i ; j++){
        //                        here why shouldnt it be "size - i" -----> since the "j" ka array search base is decreasing
        
        int j = i + 1;
        for(j = i + 1 ; j < size ; j++){
            if(array[j] - array[i] <= k){
                // std::cout << values << " ";
            }
            // std::cout << std::endl;
            else{
                break;
            }
        }
        j--;
        values = (j - i) + 1;
        ans_array.push_back(values);


    //     while(j < size && (array[j] - array[i] <= k)){
    //         // std::cout << std::endl;
    //         j++;
    //     }
    //     j--;
    //     std::cout << j << " ";
    //     values = (j - i) + 1;
    //     ans_array.push_back(values);
        
    }

    
    
    // std::cout << std::endl;
    int max = INT_MIN;
    for(int val : ans_array){
        std::cout << val << " ";
        if(val > max){
            max = val;
        }
    }
    std::cout << max << std::endl;



    return 0;
}