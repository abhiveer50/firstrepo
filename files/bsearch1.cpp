#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int searchRange(vector<int>& nums, int target) {
        int i=-1;
        int j = -1;
        int l = 0;
        int h= nums.size()-1;
        while(l<=h && h!=-1){
            int m = (l+h)/2;
             if(target> nums[m]) l = m+1;
            else h = m-1;
        }
        return l;
    }

int pivot(vector<int>& nums){
        int l = 0;
        int h = nums.size()-1;
        if(h == -1) return 0;
        while(l<h){
            int m = (l+h)/2;
            if(nums[0]<=nums[m]) l = m+1;
            else h = m;
        }
        return h;
    }

int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int l = 0;
        int h = nums.size() -1;
        int p = pivot(nums);
        if(target== nums[0]){
            return 0;
        }
        else if(target< nums[0]){
            l = p;
        }
        else { 
            h = p-1;
        }
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m]== target) return m;
            else if(target> nums[m]) l= m+1;
            else h = m-1;
        }
        return -1;
    }

int main(){
    vector<int> sap = {11,13,15,17};
    cout << pivot(sap);
}