#include <iostream>

int max(int ans, int temp){
    if(ans >= temp){
        return ans;
    }
    else{
        return temp;
    }
}

int main(){
    int x = 17;
    int y = 25;
    int m = 77;
    int a_max = m/x;
    int b_max = m/y;


    int ans = y;

    for(int A = 0 ; A <= a_max ; A++){
        int temp = ans;
        for(int B = 0 ; B <= b_max ; B++){
            if(x*A + y*B <= m){
                ans = x*A + y*B;
                ans = max(ans,temp);
            }
        }
    }


    std::cout << ans << std::endl;
    return 0;
}