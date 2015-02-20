/*
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.

Before we go further, let us understand with few examples:
    ab: Number of insertions required is 1. bab
    aa: Number of insertions required is 0. aa
    abcd: Number of insertions required is 3. dcbabcd
    abcda: Number of insertions required is 2. adcbcda which is same as number of insertions in the substring bcd(Why?).
    abcde: Number of insertions required is 4. edcbabcde

Let the input string be str[l……h]. The problem can be broken down into three parts:
1. Find the minimum number of insertions in the substring str[l+1,…….h].
2. Find the minimum number of insertions in the substring str[l…….h-1].
3. Find the minimum number of insertions in the substring str[l+1……h-1].
*/


// An LCS based program to find minimum number insertions needed to
// make a string palindrome
#include<stdio.h>
#include <string.h>
 
/* Utility function to get max of 2 integers */
int max(int a, int b)
{   return (a > b)? a : b; }
 
/* Returns length of LCS for X[0..m-1], Y[0..n-1]. 
   See http://goo.gl/bHQVP for details of this function */
int lcs( char *X, char *Y, int m, int n )
{
   int L[n+1][n+1];
   int i, j;
 
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
 
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
 
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
 
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}
 
// LCS based function to find minimum number of insersions
int findMinInsertionsLCS(char str[], int n)
{
   // Creata another string to store reverse of 'str'
   char rev[n+1];
   strcpy(rev, str);
   strrev(rev);
 
   // The output is length of string minus length of lcs of
   // str and it reverse
   return (n - lcs(str, rev, n, n));
}
 
// Driver program to test above functions
int main()
{
    char str[] = "geeks";
    printf("%d", findMinInsertionsLCS(str, strlen(str)));
    return 0;
}
