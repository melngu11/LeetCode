#include <iostream>
#include <vector>


using namespace std;

class Array_Solution {
public:
    // 238. Product of Array Except Self
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        //Answer array initalized with 1's
        vector<int> answer(n, 1);

        for (int i = 1; i < n; i++){
            answer[i] = answer[i-1] * nums[i-1];
        }
        int post = 1;
        for (int i = n-1; i >= 0; i--){
            answer[i] *= post;
            post *= nums[i];
        }
    return answer;
        
    }
    vector<int> productExceptSelf2(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1); // Answer array initalized n number of elements with value 1

        //Left side calculation
        for (int i = 1; i < n; i++) {
            answer[i] = answer[i-1] * nums[i-1];
        }
        //Right side calculation
        int post_value = 1; /// Post value is used to store the product of the right side elements. Starting from 1 because the last element will have 1 as its right side product
        for(int i = n-1; i >= 0; i--) {
            answer[i] *= post_value;
            post_value *= nums[i]; // Updating the post_value for the next element
        }
        return answer;
    }
    
};