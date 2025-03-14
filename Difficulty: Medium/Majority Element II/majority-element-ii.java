//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume the newline character

        while (t-- > 0) {
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            int[] nums = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                nums[i] = Integer.parseInt(parts[i]);
            }
            Solution ob = new Solution();
            List<Integer> ans = ob.findMajority(nums);

            if (ans.size() == 0) {
                System.out.println("[]");
            } else {
                for (int i : ans) {
                    System.out.print(i + " ");
                }
                System.out.println();
            }
        }
        sc.close();
    }
}

// } Driver Code Ends

class Solution {
    public List<Integer> findMajority(int[] nums) {
        // Your code goes here.
        int n=nums.length;
        int one_third=n/3;
        HashMap<Integer,Integer> map=new HashMap<>();
        List<Integer> res=new ArrayList<>();
        
        for(int a:nums){
            map.put(a,map.getOrDefault(a,0)+1);
        }
        
        for (Integer key : map.keySet()) {
            if(map.get(key)>one_third)res.add(key);
        }
        
        return res;
    }
}

