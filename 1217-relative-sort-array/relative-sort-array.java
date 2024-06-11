class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        HashMap<Integer,Integer> hm = new HashMap();
        
        for(int i=0;i<arr2.length;i++)
        {
            hm.put(arr2[i],i);
        }    
        System.out.println(hm);

        for(int i=0;i<arr1.length;i++)
        {
            for(int j=i+1;j<arr1.length;j++)
            {
                boolean iInArr2 = hm.get(arr1[i]) != null;
                boolean jInArr2 = hm.get(arr1[j]) != null;

                if (iInArr2 && jInArr2) 
                {
                    if (hm.get(arr1[i]) > hm.get(arr1[j])) 
                    {
                        int temp = arr1[i];
                        arr1[i] = arr1[j];
                        arr1[j] = temp;
                    }
                } 
                else if (iInArr2) 
                {
                    continue;
                } 
                else if (jInArr2) 
                {
                    int temp = arr1[i];
                    arr1[i] = arr1[j];
                    arr1[j] = temp;
                } 
                else 
                {
                    if (arr1[i] > arr1[j]) {
                        int temp = arr1[i];
                        arr1[i] = arr1[j];
                        arr1[j] = temp;
                    }
                }
            }
            System.out.println(arr1[i]);
        }
        return arr1;
    }
}