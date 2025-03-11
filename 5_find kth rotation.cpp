// https://www.geeksforgeeks.org/problems/rotation4723/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size() ;
        
        int i = 0 ;
        int j = n - 1 ;
        
        while(i < j)
        {
            int mid = i + (j-i)/2 ;
            
            if(arr[mid] < arr[j])
            {
                j = mid ;
            }
            else
            {
                i = mid + 1 ;
            }
        }
        return j ;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends
