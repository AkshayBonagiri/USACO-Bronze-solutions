#include <iostream>
#include <cmath>
#include <vector>


int main(){
    int n = 4;
    std::vector<int> flowers_arr;
    std::vector<int> petals_size = {1, 1, 2, 3};


    //4   1   0   2   3
    //4   5   5   7   10
    //prefix sum : compute all the sum till the     
    //0, 0 + 1 , 0 + 1 + 2, 0 + 1 + 2 + 3, 

    for(int i = 1 ; i < n + 1 ; i++){
        flowers_arr.push_back(i);
    }

    //DEBUGGING
    // for(int val : flowers_arr){
    //     std::cout << val << " ";
    // }

    //finding all the pairs
    int no_pairs = n * n;
    std::vector<std::pair<int, int>> pairs;

    //USING 2-POINTER METHOD    

    int i = 1;
    int j = 1;
    while(i <= n){

        // std::cout << "counter:)" << std::endl;
        pairs.push_back({i - 1,j - 1});
        j++;

        if(j > n){
            i++;
            j = i;
        }
    }

    std::vector<double> avgs;          //if needed put FLOAT

    // for(const auto& p : pairs){
    //     std::cout << "(" << p.first << "," << p.second << ")" << std::endl;
    // }

    double sum = 0;

    for(const auto& p : pairs){
        for(int i = p.first ; i <= p.second ; i++){
            sum += petals_size[i];
        }
        int length = (p.second - p.first) + 1;
        avgs.push_back((double)sum/length);
        sum = 0;
    }

    for(int val : avgs){
        std::cout << val << " ";
    }
    std::cout << std::endl;

    int counter = 0;
    int idx = 0;
    for(const auto& p : pairs){
        std::cout << p.first << " " << p.second << std::endl;
        for(int i = p.first ; i <= p.second ; i++){
            if(petals_size[i] == avgs[idx]){
                counter++;
                std::cout << counter << std::endl;
                break;
            }
        }
        idx++;
    }
    
    std::cout << counter << std::endl;
    

    return 0;
}