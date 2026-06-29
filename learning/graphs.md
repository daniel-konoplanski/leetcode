# Graph Theory — Core Knowledge

## What is a Graph?
- Set of **nodes** (vertices) connected by **edges**
- Formally: G = (V, E)

---

## Types of Graphs

| Type | Description |
|------|-------------|
| Undirected | Edges have no direction (A—B means A↔B) |
| Directed (Digraph) | Edges have direction (A→B ≠ B→A) |
| Weighted | Edges have costs/distances |
| Unweighted | All edges equal |
| Cyclic | Contains at least one cycle |
| Acyclic | No cycles |
| DAG | Directed Acyclic Graph — critical for topological sort |
| Connected | Every node reachable from every other node |
| Disconnected | Some nodes unreachable from others |

---

## Representations

### Adjacency List (most common in LC)
```
graph = {
  0: [1, 2],
  1: [0, 3],
  2: [0],
  3: [1]
}
```
- Space: O(V + E)
- Good for sparse graphs

### Adjacency Matrix
```
     0  1  2  3
  0 [0, 1, 1, 0]
  1 [1, 0, 0, 1]
  2 [1, 0, 0, 0]
  3 [0, 1, 0, 0]
```
- Space: O(V²)
- Good for dense graphs, O(1) edge lookup
- **Grids are implicit adjacency matrices**

### Edge List
```
edges = [(0,1), (0,2), (1,3)]
```
- Used in some problems (e.g. Union-Find problems)

---

## Traversals

### DFS — Depth-First Search
- Go deep before going wide
- Uses: **stack** (iterative) or **recursion** (implicit stack)
- Good for: connected components, cycle detection, topological sort, backtracking

```python
def dfs(graph, node, visited):
    visited.add(node)
    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)
```

**On a grid:**
```python
def dfs(grid, r, c, visited):
    if r < 0 or r >= rows or c < 0 or c >= cols:
        return
    if (r, c) in visited or grid[r][c] == '0':
        return
    visited.add((r, c))
    dfs(grid, r+1, c, visited)
    dfs(grid, r-1, c, visited)
    dfs(grid, r, c+1, visited)
    dfs(grid, r, c-1, visited)
```

### BFS — Breadth-First Search
- Go wide before going deep
- Uses: **queue** (deque)
- Good for: **shortest path** in unweighted graph, level-order traversal

```python
from collections import deque

def bfs(graph, start):
    visited = set([start])
    queue = deque([start])
    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
```

**Key BFS insight:** First time you reach a node = shortest path to it.

---

## Connected Components
- Isolated subgraphs with no edges between them
- Count: run DFS/BFS, each new unvisited starting node = new component

---

## Cycle Detection

**Undirected graph:** During DFS, if you reach a visited node that isn't your parent → cycle.

**Directed graph:** Track nodes in current recursion stack. If you reach a node already in stack → cycle.

---

## Topological Sort
- Only valid on **DAGs**
- Ordering of nodes such that all edges go left→right
- Used for: dependency resolution, course scheduling

**Kahn's Algorithm (BFS-based):**
1. Compute in-degree for all nodes
2. Add all 0-in-degree nodes to queue
3. Process queue: reduce neighbors' in-degrees, add any that hit 0
4. If output has all nodes → valid DAG; else → cycle exists

---

## Union-Find (Disjoint Set Union)
- Tracks which nodes belong to same connected component
- Operations: `find(x)` → root of x's component, `union(x, y)` → merge components
- Used for: Kruskal's MST, detecting cycles in undirected graphs

```python
parent = list(range(n))

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])  # path compression
    return parent[x]

def union(x, y):
    px, py = find(x), find(y)
    if px == py:
        return False  # already connected
    parent[px] = py
    return True
```

---

## Shortest Path Algorithms

| Algorithm | Graph Type | Complexity | Use Case |
|-----------|-----------|------------|----------|
| BFS | Unweighted | O(V+E) | Shortest hops |
| Dijkstra | Weighted, no negative edges | O((V+E) log V) | Shortest weighted path |
| Bellman-Ford | Weighted, negative edges ok | O(VE) | Negative weights |
| Floyd-Warshall | All pairs | O(V³) | All-pairs shortest path |

---

## Key Patterns in LeetCode

| Pattern | Example Problems |
|---------|-----------------|
| DFS flood fill | 200 (Islands), 695 (Max Area of Island) |
| BFS shortest path | 994 (Rotting Oranges), 127 (Word Ladder) |
| Connected components | 323, 547 (Friend Circles) |
| Topological sort | 207, 210 (Course Schedule) |
| Union-Find | 684, 721 |
| Dijkstra | 743 (Network Delay Time) |
| Cycle detection | 207, 802 |

---

## Complexity Reference

| Operation | Adj List | Adj Matrix |
|-----------|----------|------------|
| Space | O(V+E) | O(V²) |
| Add edge | O(1) | O(1) |
| Remove edge | O(E) | O(1) |
| Check edge | O(degree) | O(1) |
| Get neighbors | O(degree) | O(V) |
| DFS/BFS | O(V+E) | O(V²) |

---

## Common Pitfalls
1. **Forgetting visited set** → infinite loop on cycles
2. **Off-by-one on grid bounds** → check `0 <= r < rows` and `0 <= c < cols`
3. **Directed vs undirected** → build graph accordingly
4. **Disconnected graph** → outer loop over all nodes, not just one start
5. **Modifying grid in-place vs visited set** → both valid, in-place saves space
