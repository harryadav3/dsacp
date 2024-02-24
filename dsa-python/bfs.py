def bfs(graph,start):

    vis = set()
    queue = deque([start])
    vis.add(start)

    bfs_order = []

    while queue:
        node = queue.popleft()
        bfs_order.append(node)
        for nei in graph[node]:
            if nei not in vis:
                queue.append(nei)
                vis.add(nei)
            
    return bfs_order
    
