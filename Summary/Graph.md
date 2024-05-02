# Graph

## Overview

- Graph (and tree) is very useful in modelling several problem
- Checking connectivity
  - DFS
  - BFS
  - CC - Connected Component
  - SCC - Strongly Connected Component
  - Detecting a Cycle
  - Topological Sorting
    - Kahn’s Algorithm
- Calculating Minimum Spanning Tree:
  - Prim’s Algorithm
  - Kruskal’s Algorithm
- Finding a shortest path:
  - Dijkstra
  - Bellman-Ford
  - Floyd-Warshall

## Graph Representation

- A graph G = (V,E) consist of a
  - set of nodes (V)
  - set of edges (E)
  - Each edge is a
    - pair of vertices (a,b)
      - indicating that there is a connectivity from a &rarr; b
- Undirected graph
  - edge (a,b) = edge (b,a)
- Weighted graph
  - Each edge has a weight
- Path
  - sequence of nodes such that there is an edge for every adjacent pair of nodes in the sequence
- Simple path
  - no duplicate nodes in the sequence
- Circuit
  - path that the first and the last nodes in the sequence is the same
- Simple circuit
  - no duplicate nodes in the sequence except the first and last
- Degree of a node
  - number of edges that connect to that node
- Simple graph
  - graph with no
    - self-loop: edge connecting a same node
    - duplicate edge: two or more edges connecting the same pair of node
- Data Structure for Graph
  - Adjacency Matrix
    - 2D array: A[1..n][1..n]
    - A[x][y] = 1 when there is an edge connecting node x and node y
  - Adjacency List
    - A[1..n] = Array of a vector (or some other data structure)
    - A[x] is a *list of all neighbor* of x
    - We can use vector, BST, hash instead of list but it really depends on usage and density of edges
  - Incidence matrix
    - A[1..n][1..e]
    - Row represent nodes while columns represent edges
    - A[v1][v1] = 1 when edge e1 connect nodes v1
  - basic operations
    - static graph
      - nodes(): get a list of nodes in the graph
      - adj(v1): Given a node v1, get a list of nodes such that there is an edge from v1 to them
      - has_edge(v1,v2): Given two nodes v1 and v2, return true only when there is an edge connecting v1 to v2
    - dynamic graph
      - add/remove nodes and edges


## Checking Connectivity

### DFS - Depth First Search
Visiting nodes in a graph

```cpp
def dfs(a,G,visited)
    visited[a] = true
    for b in G.adj(a)
        if visited[b] == false
            dfs(b,G,state)
end
```

DFS using stack
```cpp
def dfs_by_stack(a,G)
    s = new Stack
    s.push(a)
    visited[a] = true
    while (s.size > 0)
        u = s.top
        s.pop
        for b in G.adj(u)
            if visited[b] == false
                visited[b] = true
                s.push(b)
end
```

**Time Complexity**
So, it is *O(n^2^)* However, a better analysis is *O(n+e)*

### BFS - Breadth First Search
Another algo for exploring nodes in a graph

BFS using queue
```cpp
def bfs_by_queue(a,G)
    q = new Queue
    q.push(a)
    visited[a] = true
    while (q.size > 0)
        u = q.front
        q.pop
        for b in G.adj(u)
            if visited[b] == false
                visited[b] = true
                q.push(b)
end
```

BFS with Distance
```cpp
def bfs_by_queue(a,G)
    q = new Queue
    q.push(a)
    dist[a] = 0
    // dist[x] = distance
    // minimum number of edges
    // we need to go through in the shortest path
    // from u to x
    while (q.size > 0)
        u = q.front
        q.pop
        for b in G.adj(u)
            if dist[b] == -1
                dist[b] = dist[u] + 1
                q.push(b)
end
```

- Order of nodes: *Distance* from the starting position
- Breadth First Search is used to find a *shortest path* on an **unweighted graph**

**Compare**
- DFS tries to go as deep as possible
- BFS tries to cover nodes of the same distance
- Memory Usage
  - At worse, both may require up to O(N) nodes to be stored in the stack/queue
    - A line graph for DFS
    - A star graph for BFS
  - In practice, a k-ary tree with depth d is very common
    - DFS use k * d, because it must remember all children of each unfinished visiting node.
    - BFS use k^d^ , because it has to remember all nodes of the same depth


### CC - Connected Component
Graph Partitioning

- **undirected** graph
- equivalent relation
  - path a &rarr; b = b &rarr; a
  - path a &rarr; b & b &rarr; c = a &rarr; c
- group nodes
  - according to equivalent relation
  - Each group is called *connected component*

CC using DFS
```cpp
def dfs_cc(a,G,visited)
    visited[a] = cc_num
    for b in G.adj(a)
        if visited[b] == 0
            dfs(b,G,visited)
end

def cc(G)
    cc_num = 0
    visited[] = [0,...]
    for every u in G
        if visited[u] == 0
            cc_num += 1
            dfs_cc(u,G,visited)
end
```

**Time Complexity**: O(n+e)

### Detecting a Cycle
Another application of {B,D}FS
- This method works in *directed* graph as well.

```cpp
def dfs_cd(a,G,visited,parent)
    visited[a] = true
    for b in G.adj(a)
        if visited[b] == 0
            dfs(b,G,visited,a)
        else if b != parent
            return true
    return false
end

def circuit_detect(G)
    visited[] = [false,...]
    for every u in V
        if visited[u] == false
            if dfs_cd(u,G,visited,-1)
                return true
    return false
end
```
**Time Complexity**: O(n+e)

### Topological Sorting
Ordering of nodes

- Dependency; task might need another task to finish first
- These dependencies can be modelled as a **directed** graph
  - *node* is a task
  - *directed edge* from A to B means that B depends on A to finished first.
- **DAG** - Directed Acyclic Graph
  - *directed* graph **without** a *cycle*
  - because cycle is deadlock
  - **must** be nodes with *in-degree = 0*
  - remove these nodes(in-degree = 0) and looking for any other nodes that has 0 in-degree

#### Kahn’s Algorithm
In actual implementation, we can **count the in-degree** instead of *remove edge*

```cpp
def topo_sort(G)
    ans = []
    q = new Queue
    let Z be any node in G.V that has zero in-degree
    for each z in Z
        q.push(z)
    while q is not empty
        u = q.front
        q.pop
        ans.push_back(u)
        for v in G.adj(u)
            remove edge (u,v) from G.E
            if v has zero in-degree
                q.push(v)
    if G.E is not empty
       return “error”
    return ans
end
```

**Time Complexity**: O(n+e)

## Minimum Spanning Tree

- Spanning Tree: graph that is connected (only **one** connected component)
- **Undirected** graph
- Minimum Spanning Tree: sum of the weighted of its edges is minimum
- MST should not have a cycle
- Tree
  - **n** nodes, **n-1** edges
  - **connected** graph having n – 1 edge
  - tree is the smallest structure that is connected

### Kruskal’s Algorithm

> Select the minimal **edge** of all edges that does *not create a cycle*

```cpp
def kruskal(G,w)
    ds = new DisjointSet
    ds.makeset(n)
    X = [] //X is the answer
    Sort the edges G.E by weight w
    for each edge (u,v) in G.E (in increasing order of weight)
        if ds.findset(u) != ds.findset(v)
            X.add(u,v) // add (u,v) to the answer
            ds.union(u,v)
    return X
end
```

**Time Complexity**: O( e (lg e) + e (lg n) )
e (lg e): From sorting of e edges
e (lg n): e iterations of 3 findset

**Disjoint Set Data Structure**
- Operation
  - makeset(n)
    - create n sets for element 1..x, each set contain each element
  - findset(x)
    - return the ID of a set where x is a member If x and y are in the same set, findset(x) must be equal to findset(y)
  - union(x,y)
    - union the set findset(x) with the set findset(y)

### Prim’s Algorithm

> Select the minimal **node & edge** of all edges that *connects to the original graph*

- Start with a single node (any node). This is our **partial MST**. We will expand this partial MST until it is the final MST of the graph
- We expand the partial MST by repeatedly adding one node and one edge to this tree, we stop when we have n nodes (and n-1 edges)
  - At each iteration, we maintain a list of connectible nodes which are nodes that can be added to our partial MST by adding just one edge.
  - We select the node with minimum cost of including that node to the tree.
  - When a node is added, we must update the list (and cost) of connectible nodes

```cpp
def prim(G,w)
    for u in G.V
        cost[u] = ∞
        prev[u] = -1
        taken[u] = false
    S = new Set
    Pick any initial node u1
    S.insert( (0,u1) )
    while S is not empty
        (c,u) = S.min
        S.delete_min
        taken[u] = true
        for v in G.adj(u)
            if cost[v] > w(u,v) && taken[v] == false
                // change the value of v to the new cost[v]
                S.remove_if_exist( (cost[v],v) )
                cost[v] = w(u,v)
                prev[v] = u
                S.insert( (cost[v],v) )
            end
        end
    end
end
```
Better implementation Use (min) priority queue
Must support decrease: Fibonacci Heap, Can do top and decrease in O(1) pop is O(lg n)
```cpp
def prim(G,w)
    for u in G.V
        cost[u] = ∞
        prev[u] = -1
    Pick any initial node u0
    cost[u0] = 0
    // H is a heap, using cost[] as keys, sort from min to max
    H = new priority_queue of all nodes in G.V
    while H is not empty
        u = H.top // pick nodes x with minimal cost[x]
        H.pop
        for v in G.adj(u)
            if cost[v] > w(u,v)
                cost[v] = w(u,v)
                prev[v] = u
                // change the value of v to the new cost[v]
                H.decrease(v,cost[v])
            end
        end
    end
end
```

**Time Complexity**: O( n (lg n) + e (lg n) )
n (lg n): from delete min n nodes
e (lg n): e times of remove and insert of nodes

## Shortest Path

**Single Source Shortest Path Problem**:\
Given a graph G with a starting node s, find the shortest path from s to every node in the graph

### Dijkstra’s Algorithm

> Dealing with **undirected & directed** graph but **no negative** edge

BFS & Alarm Clock

- Use set to store alarm of each node.
- The next alarm goes off at the minimum value in the set
- Adjust alarm by remove and re-insert alarm of that node
```cpp
def dijkstra(G,w,s)
    for u in G.V
        dist[u] = ∞
        prev[u] = -1
    end
    S = new Set
    S.insert( (0,s) )
    while S is not empty
        (T,u) = S.min
        for v in G.adj(u)
            if dist[v] > T + w(u,v)
                // change the value of v to the new cost[v]
                S.remove_if_exist( (dist[v],v) )
                dist[v] = T + w(u,v)
                prev[v] = u
                S.insert( (dist[v],v) )
            end
        end
    end
    return dist
end
```


**Time Complexity**: O( (n+e) lg n ) = O( n (lg n) + e (lg n) )

**Directed Graph and Negative Edges**
- **No** shortest path = **undirected** + **negative**
- For directed graph, negative edges are possible if they **do not** make a *negative cycle*

### Bellman-Ford Algorithm

> Dealing with **directed** graph with **negative** edge

```cpp
def bellman_ford(G, w, s)
    for u in G.V
        dist[u] = ∞
        prev[u] = -1
    end
    dist[s] = 0
    for i from 1 to n – 1
        for all edges (a,b) in G.E
            if dist[b] > dist[a] + w(a,b)
                dist[b] = dist[a] + w(a,b)
                prev[b] = a
            end
        end
    end
    for all edges (a,b) in G.E
        if dist[b] > dist[a] + w(a,b)
            return “negative cycle”
    return dist
end
```
**Time Complextity**: O(ne)
Comparing to Dijkstra’s: O(e lg n)\
Bellman-Ford is slower but can work with negative edge

### Floyd-Warshall
Shortest path between every pair of nodes

```cpp
def floyd_warshall(G,w)
    for i = 1 to n
        for j = 1 to n
            dist[i][j] = w(i,j)
    for k = 1 to n
        for i = 1 to n
            for j = 1 to n
                dist[i][j] = min (dist[i][j],
                                  dist[i][k] + dist[k][j])
    // Detect Negative Cycle
    for i = 1 to n
        if dist[i][i] < 0
            return “negative cycle”
    return dist
end
```

**Time Complexity**: O(n^3^)
- Dijkstra every vertex: O(n (e lg n) )
- Bellman-Ford every vertex: O(n (e n) )
  - For dense graph, May choose Floyd-Warshall over Bellman-Ford