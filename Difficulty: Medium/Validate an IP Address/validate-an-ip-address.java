//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

import java.io.*;
import java.util.*;

public class validip {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            String s = sc.next();
            Solution obj = new Solution();

            if (obj.isValid(s))
                System.out.println("true");
            else
                System.out.println("false");
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {

    public boolean isValid(String str) {
        
        String [] arrstr = str.split("\\.");     // arrstr[0] = "22", arrstr[1] = "45", arrstr[2] = "67", arrstr[3] = "12"
        // or   String[] arrstr = {"222", "45", "67", "12"};
        
        if (arrstr.length !=4){
            return false;
        }
        for (String part: arrstr){
            // Check if the part is non-empty
            if (part.isEmpty()) {
                return false;
            }
            
            if (!isNumeric(part)){
                    return false; 
            }
       if (hasleadingZeros(part)){
           return false;
       }
          if (!validRange(part)){
              return false;
          }  
          
        } return true; 
    }
    
    private static boolean isNumeric (String st){
        for (char c:st.toCharArray()){
            if(!Character.isDigit(c)){
                return false;
            }
        }
        return true;
    }
    
    private static boolean hasleadingZeros(String st){
        return st.length()>1 && st.charAt(0) == '0';  //if this is true, will return false in function call
    }
        
    private static boolean validRange( String st){
        int num = Integer.parseInt(st);
        return num>=0 && num<=255;
    }
}