#include<iostream>
#include<vector>
class Solution {
public:
   bool binary_search(vector<int> v, int n, int x)
   {
       int left, right, mid;
       bool res=false;
     
       left=0;
       right = n-1;
     
       while(left<=right){
           mid = left+(right-left)/2;
           if(x==v[mid]){
               res = true;
               break;
           }
            if(x<v[mid])
                right = mid-1;
          else
              left=mid+1;
    }
       return res;
       
   }
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        
        int row = matrix.size();
        
        if(!matrix.size()||!matrix[0].size())
           return false;
        int col = matrix[0].size();
        bool result=false;
        
        for(int i=0; i <row; i++){
            if(target>=matrix[i][0]&&target<=matrix[i][col-1]){
                return binary_search(matrix[i], col, target);
            }
        }