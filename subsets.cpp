//
// Created by Alina on 8/25/2022.
//
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> result = {};
    int given_length;

    void backtrack( int idx, vector<int> curr, vector<int>& nums ){

        if(idx>=given_length){
            result.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        backtrack(idx+1, curr, nums);

        curr.pop_back();
        backtrack(idx+1, curr, nums);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        given_length = nums.size();
        backtrack(0, {}, nums);
        return result;
    }

};
