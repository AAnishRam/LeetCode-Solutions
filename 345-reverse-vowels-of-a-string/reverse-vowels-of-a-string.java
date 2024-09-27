class Solution {

    public boolean isVowel(char c)
    {
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;

        return false;
    }

    public String reverseVowels(String s) {

        char [] arr = s.toCharArray();
        
        int n = s.length();
        int i = 0,j = n-1;

        while(i<j)
        {
            if(!isVowel(arr[i]))
            i++;

            if(!isVowel(arr[j]))
            j--;

            if(isVowel(arr[i]) && isVowel(arr[j]))
            {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        return String.valueOf(arr);


    }
}