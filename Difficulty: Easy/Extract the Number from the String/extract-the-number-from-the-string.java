//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.regex.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S = read.readLine();
            Solution ob = new Solution();
            System.out.println(ob.ExtractNumber(S));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    long ExtractNumber(String s) {
        // code here
       String[] arr = s.split(" ");
       
     
       
    long maxValue = Long.MIN_VALUE;     
    for(int i =0;i<arr.length;i++)
    {
        if(arr[i].charAt(0)<='9' && arr[i].charAt(0)>='0')
        {
         long val = Long.parseLong(arr[i]);
         
         int idx=0;
         while(idx<arr[i].length())
         {
             if(arr[i].charAt(idx)=='9') break;
             idx++;
         }
         
         if(idx==arr[i].length()) 
         maxValue=Math.max(maxValue,val);
         }
        
         
        }
    
       if(arr.length==0) return -1;
       
       if(maxValue<0) return -1;
        

        return maxValue;
    }
}