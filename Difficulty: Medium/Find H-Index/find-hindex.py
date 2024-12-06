#User function Template for python3
class Solution:
    # Function to find hIndex
  def hIndex(self, citations):
        #code here

        # Step 1: Sort citations in descending order
        citations.sort(reverse=True)
        
        # Step 2: Calculate H-Index
        h_index = 0
        for i, citation in enumerate(citations):
            if citation >= i + 1:  # Check if the citation count is at least the 1-based index
                h_index = i + 1
            else:
                break
        
        return h_index

#{ 
 # Driver Code Starts
# Initial Template for Python 3

# Main
if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        arr = [int(x) for x in input().strip().split()]

        ob = Solution()
        result = ob.hIndex(arr)

        print(result)
        print("~")

# } Driver Code Ends