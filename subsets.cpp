#include<iostream>
#include<vector>
using namespace std;
void printSubsets(vector<int>& nums,vector<int>&ans,int i,vector<vector<int>>&allSubsets){
    if(i==nums.size()){
    allSubsets.push_back({ans});
    return;
    }
    ans.push_back(nums[i]);
    printSubsets(nums,ans,i+1,allSubsets);
    ans.pop_back();
    printSubsets(nums,ans,i+1,allSubsets);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int>ans;
        printSubsets(nums,ans,0,allSubsets);
        return allSubsets;
    }
    int main(){
        vector<int> nums = {1,2,3};
        vector<vector<int>> allSubsets = subsets(nums);
        cout << "[";
        for(size_t i = 0; i < allSubsets.size(); ++i){
            cout << "[";
            for(size_t j = 0; j < allSubsets[i].size(); ++j){
                cout << allSubsets[i][j];
                if(j != allSubsets[i].size() - 1) cout << ", ";
            }
            cout << "]";
            if(i != allSubsets.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        return 0;
    }