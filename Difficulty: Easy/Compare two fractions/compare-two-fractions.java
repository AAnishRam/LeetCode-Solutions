//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class GFG {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        Solution ob = new Solution();
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str = read.readLine().trim();
            String ans = ob.compareFrac(str);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {

    String compareFrac(String str) {
        // Code here
        String s1[]=str.replaceAll(" ","").split(",");
        String s10[]=s1[0].split("/");
        String s11[]=s1[1].split("/");
        double a = Integer.valueOf(s10[0]);
        double b = Integer.valueOf(s10[1]);
        double c = Integer.parseInt(s11[0]);
        double d = Integer.parseInt(s11[1]);
        if(a / b == c / d){
            return "equal";
        }
        else if(a / b > c / d){
            return s1[0];
        }
        else{
            return s1[1];
        }
    }
}


