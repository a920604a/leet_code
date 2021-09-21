
## DFS: Connected Cell in a Grid



```python

def bfs(grid,  i, j):
    ret = 0
    n , m = len(grid) , len(grid[0])
    if i< 0 or j<0 or i>n-1 or j>m-1 or  grid[i][j] == 0:
        return ret
    
    grid[i][j] = 0
    ret = 1
    ret += bfs(grid,  i-1, j-1)
    ret += bfs(grid, i-1, j)
    ret += bfs(grid,  i-1, j+1)
    
    ret += bfs(grid,  i, j-1)
    ret += bfs(grid,  i, j+1)
    
    ret += bfs(grid,  i+1, j-1)
    ret += bfs(grid,  i+1, j)
    ret += bfs(grid,  i+1, j+1)
    
    return ret
    
    
def maxRegion(grid):
    # Write your code here
    maxArea = 0
    n , m = len(grid) , len(grid[0])
    for i in range(n):
        for j in range(m):
            if grid[i][j]==1:
                
                area = bfs(grid , i, j)
                maxArea = max(maxArea, area)

    return maxArea


```


##