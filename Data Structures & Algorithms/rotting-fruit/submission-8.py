class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        queue = deque()
        fresh_count = 0
        minutes = 0
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 2:
                    queue.append((r, c, 0))
                elif grid[r][c] == 1:
                    fresh_count += 1
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        while queue:
            r, c, minutes = queue.popleft()
            
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                
                if 0 <= nr < len(grid) and 0 <= nc < len(grid[0]) and grid[nr][nc] == 1:
                    grid[nr][nc] = 2  # Mark as rotten
                    fresh_count -= 1
                    queue.append((nr, nc, minutes + 1))
                    
        # 3. If there are still fresh oranges left, impossible to rot all
        return minutes if fresh_count == 0 else -1
