Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
  
  
  

// use the concept of length of a string  (--)  lonest palidrome subsequence --> longest commmon subsequence


class Solution {
public:
    
    int solve(int m,int n,string &s1,string &s2,vector<vector<int> > &dp)
    {
        if(m<0 or n<0)
            return 0;
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        
        if(s1[m]==s2[n])
            return dp[m][n]=1+solve(m-1,n-1,s1,s2,dp);
        
        else 
            return dp[m][n]=max(solve(m-1,n,s1,s2,dp),solve(m,n-1,s1,s2,dp));
    
        
        //return dp[m][n];
        
    }
    
    int longestCommonSubsequence(string &text1, string &text2) 
    {
        
        int m=text1.size();
        int n=text2.size();
        
        vector<vector<int> > dp(1001,vector<int> (1001,-1));
        
       /* for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        } 
        
        return dp[m][n];*/
        
        return solve(m-1,n-1,text1,text2,dp);
        
        
            
    }
    int longestPalindromeSubseq(string &s) {
        
        string t=s;
        reverse(s.begin(),s.end());
        
        
        return longestCommonSubsequence(s,t);
        
        
        
    }
    int minInsertions(string s) 
    {
        
        int n=s.size();
        return n-longestPalindromeSubseq(s);
    }
};
