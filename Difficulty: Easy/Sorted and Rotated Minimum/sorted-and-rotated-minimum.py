#User function Template for python3

class Solution:
    def findMin(self, arr):
        n = len(arr)
        left, right = 0, n - 1
        
        if arr[left] <= arr[right]:
            return arr[left]
            
        while left <= right:
            mid = left +(right - left) // 2
            
            if arr[mid] < arr[mid-1]:
                return arr[mid]
            if arr[mid] > arr[right]:
                left = mid + 1
            else:
                right = mid - 1
        return None



#{ 
 # Driver Code Starts
def main():
    T = int(input())

    while T > 0:
        a = list(map(
            int,
            input().strip().split()))  # Convert input to list of integers
        print(Solution().findMin(a))  # Call findMin with the array 'a'
        T -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends