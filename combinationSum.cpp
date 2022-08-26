//
// Created by Alina on 8/25/2022.
//
#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> result = {};
    vector<int>* given_array;
    int array_length;

    void backtrack(int idx, vector<int> curr, int total, int target){
        if (total == target){
            result.push_back(curr);
            return;
        } else if (idx >= array_length || total>target){
            return;
        }

        curr.push_back(given_array->at(idx));
        backtrack(idx, curr, total+given_array->at(idx), target);
        curr.pop_back();
        backtrack(idx+1, curr, total, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        given_array = &candidates;
        array_length = candidates.size();
        backtrack(0, {}, 0, target);
        return result;
    }
};
