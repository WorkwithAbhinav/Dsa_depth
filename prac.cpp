#include <iostream>
#include <vector> 
#include <bits/stdc++.h>
using namespace std;

// void fx(int n ){
//     if(n ==0){
//         return ;
//     }
//     cout <<"this is the number before function call" <<  n << endl;
//     fx(n-1);
//     cout << "this is after function call " << n << endl; 
// }

// int sumf(int n){
//     if(n == 0 ){
//         return 0;
//     }
//     cout << "this is before " << n << endl;
//     int ans = n + sumf(n-1);
//     cout << "this is n after " << n << endl;
//     cout << "this is ans after " << ans << endl;
//     return ans ;
// }

// int fibo (int n){
//     if(n <= 1){
//         return n;
//     }
//     cout << " fibo of n-1 before " << n-1 << endl;
//     cout << " fibo of n-2 before " << n-2 << endl;
//     int ans = fibo(n-1) + fibo(n-2);
//     cout << " fibo of n-1 after " << n-1 << endl;
//     cout << " fibo of n-2 after " << n-2 << endl;
//     cout << " fibo of ans " << ans << endl;

//     return ans ;
// }

//  void rev(vector<int> &arr , int n , vector<int> &ans){

//     if(n <0){
//         return ;
//     }
//     ans.push_back(arr[n]);
//     rev(arr,n-1,ans);
//  }

// void f(vector<string> &v, int n ,string current ="") {
//     if(current.length()==n){
//     cout<< " this is inside base case : " << current << endl;
//     v.push_back(current);
//     return;
//     }

//     if(current.empty() || current.back()=='0'){
//     cout<< " this is before 0 : " << current << endl;
//     f(v,n,current + '0');
//     cout<< " this is before 1 & after 0 : " << current << endl;
//     f(v,n,current + '1');
//     cout<< " this is after 0 & 1 : " << current << endl;
//     }
//     else {
//     f(v, n, current + '0');
//     cout<< " this is else condition 0 : " << current << endl;
//     }
// }

// vector<string> generateString(int n) {
//     vector<string> output;
//     f(output, n);
//     return output;

// }


    // bool isValid(string s) {
    //     stack<char> st; // Change stack<int> to stack<char>
    //     for (int i = 0; i < s.length(); i++) {
    //         if (s[i] == '(')
    //             st.push(s[i]);
    //         else {
    //             if (st.empty()) return false;
    //             char ch = st.top();
    //             st.pop();
    //             if (ch == '(' && s[i] == ')') {
    //                 continue;
    //             } else
    //                 return false;
    //         }
    //     }
    //     return st.empty();
    // }
    // void f(vector<string> &ans , int n , string s ="" ){
    //     if(s.length() == 2 * n){
    //         if(isValid(s)){
    //             ans.push_back(s);
    //         }
    //     }
    //     f(ans, n , s+'(');
    //     f(ans, n , s+')');
    // }



// void f(vector<string> & output , int open , int closed , int n , string &s){
//     if( s.length() == n*2){
//     cout<< " this is else condition 0 : " << s << endl;
//         output.push_back(s);
//         return;
//     }
//     if(open < n){
//         s.push_back('(');
//         f(output,open+1,closed,n, s);
//         s.pop_back();
//     }
//     if(closed < open){
//         s.push_back(')');
//         f(output,open,closed+1,n, s);
//         s.pop_back();
//     }
// }
// int solve(vector<int>& nums, int target, int index){
//         if(index>=nums.size()) return 0;
        
//         int res=0;
//     cout<< " value of res before : " << res << endl;
//         int sum=0;
//     cout<< " value of sum before : " << sum << endl;
        
        
//         for(int i=index;i<nums.size();i++){
//             sum=sum+nums[i];
//     cout<< " value of sum after : " << sum << endl;
//     cout<< " value of nums[i] before : " << nums[i] << endl;

//             if(sum==target){
//                 res+=1;
//             }
//         }
//         return res+solve(nums,target,index+1);
// }
int fx(int index , int target , vector<int> & nums , vector<vector<int>> &dp){
    if(index ==0 ){
        if(target- nums[0] == 0 || target + nums[0] == target){
            return 1;
        }
        return 0;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    int add = fx(index-1 , target + nums[index] , nums , dp);
    cout << target ;
    int sub = fx(index-1 , target - nums[index] , nums , dp);
    cout << target ;
    return dp[index][target] = add+sub;

}
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size() ;
    vector<vector<int>>dp(n , vector<int>(target , -1));
    return fx(n-1 , target , nums , dp);
}
int main () {
    vector<int> arr = {1,1,1,1,1} ;
    int target = 3;
    cout << findTargetSumWays(arr , target);
}