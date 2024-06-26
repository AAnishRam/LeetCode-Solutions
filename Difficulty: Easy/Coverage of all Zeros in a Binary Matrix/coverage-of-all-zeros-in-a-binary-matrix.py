#User function Template for python3
class Solution:
	def FindCoverage(self, matrix):
	    row, col = len(matrix), len(matrix[0])
	    count = 0
	    
	    for i in range(row):
	        for j in range(col):
	            if matrix[i][j]==0:
	                if -1<i-1<row and matrix[i-1][j]==1:
	                    count+=1
	                if -1<j-1<col and matrix[i][j-1]==1:
	                    count+=1
	                if -1<j+1<col and matrix[i][j+1]==1:
	                    count+=1
	                if -1<i+1<row and matrix[i+1][j]==1:
	                    count+=1
	    return count
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n, m = input().split()
        n = int(n)
        m = int(m)
        matrix = []
        for _ in range(n):
            matrix.append(list(map(int, input().split())))
        ob = Solution()
        ans = ob.FindCoverage(matrix)
        print(ans)

# } Driver Code Ends