//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(br.readLine().trim());

        while (testCases-- > 0) {
            String[] str = br.readLine().trim().split(" ");
            int[] arr = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                arr[i] = Integer.parseInt(str[i]);
            }

            Solution ob = new Solution();
            List<Integer> result = ob.findSplit(arr);

            if (result.get(0) == -1 && result.get(1) == -1 || result.size() != 2) {
                System.out.println("false");
            } else {
                int sum1 = 0, sum2 = 0, sum3 = 0;
                for (int i = 0; i < arr.length; i++) {
                    if (i <= result.get(0))
                        sum1 += arr[i];

                    else if (i <= result.get(1))
                        sum2 += arr[i];

                    else
                        sum3 += arr[i];
                }
                if (sum1 == sum2 && sum2 == sum3) {
                    System.out.println("true");
                } else {
                    System.out.println("false");
                }
            }
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {

    public List<Integer> findSplit(int[] arr) {
        
        int target = 0;
        for(int i:arr) target +=i;
        if(target == 0){
           if(arr.length>3) return new ArrayList<>(Arrays.asList(1,2));//give a thought y it works you will be amazed!!!..
        }
        if(target%3 != 0){
            return new ArrayList<>(Arrays.asList(-1,-1));
        }
        List<List<Integer>> index = new ArrayList<>();
        target /=3;
        int currSum = 0;int start  = 0;
        for(int i=0;i<arr.length;i++){
            currSum += arr[i];
            if(currSum == target){
                index.add(new ArrayList<>(Arrays.asList(start,i)));
                start=i+1;
                currSum = 0;
            }else if(currSum > target){
                return new ArrayList<>(Arrays.asList(-1,-1));
            }
        }
        //System.out.println(index);
        if(index.size() != 3) return new ArrayList<>(Arrays.asList(-1,-1));
        return new ArrayList<>(Arrays.asList(index.get(0).get(1),index.get(1).get(1)));
    }
}

