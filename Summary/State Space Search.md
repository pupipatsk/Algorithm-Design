# State Space Search
Next level brute force
- Brute force
  - *defining* the state space
  - how to *enumerate* members of the subspace
- State Space Search: consider two more aspects of search space
  - Which **order** should we enumerate the member (BFS and DFS topics)
  - Can we **reduce** the size of the search space (Backtracking and Branch-and- Bound)
- Search Tree

## Overview
- Basics
  - Candidate solution
  - Set of all candidate solutions
  - How to generates
  - How to check
- State Space Tree Traversing
  - What is search tree
  - Partial solutions
  - DFS
  - BFS
- State Space Tree Optimization
  - Backtracking
  - Branch and Bound
    - Least-Cost Search / Best First Search

### State Space Tree
- A tree that represents how we generates each member of the search space
- State type
  - Initial state: our stating points
  - Partial state: not a full candidate solution but parts of it
    - consider these partial state,\
    *pruning*: reduce the number of candidate solutions to be considered.
  - Candidate solution: full solution where it can be solely determined whether it satisfies the constraint

DFS and BFS Algorithm but on the state space tree
- DFS
  - Stack-based
  - Use less space
  - Might loops forever if solution set is infinite
- BFS
  - Queue-based
  - Use **large space**
  - Found solution nearest to the root node in the search tree

### Backtracking
Technique to reduce enumeration

- should not generate states that will never produce a solution.
- Backtracking using the information of a partial state (part of solution that have been generated) to determine weather the state can lead to a candidate solution that satisfies the constrains.
  - If it cannot, just stop.

### Branch-and-Bound
Backtracking for Constraint Optimization Problem (COP)

- B&B and backtracking both consider partial state and try to stop the partial state
from generating more state
  - **Backtracking** considers the **known part** of the partial
  - **B&B** considers the **unknown part** (step that we have not performed yet) by trying to determine best estimation of the unknown and decide weather we should search further down this step.
  - B&B uses a **bounding heuristic** to estimate the best possible outcome of the unknown part.
- B&B stops a partial state when its *prediction* is less than the *current best* score (from any evaluated candidate solution)

#### Bounding Heuristic
- function that take a partial state as an input and produce a prediction an objective function of the state.
- The goal of bounding heuristic is to predict the possible value of an
objective function from incomplete information (partial state)
  - The bounding heuristic MUST NOT be underestimate
  - The bounding heuristic CAN BE overestimate
  - The bounding heuristic SHOULD BE fast, we trade of accuracy for time.

**Summary**
- Key
  - Never underestimate!!!
  - Future cost can be overestimate
  - Bounding heuristic is optimistic
- Maximization problem (finding highest value solution)
  - Bound must be higher than (or equal to) the real value (**upper bound**)
  - Good bound ➔ lowest value that is >= the real value
- Minimization problem (finding lowest value solution)
  - Bound must be lower than (or equal to) the real value (**lower bound**)
  - Good bound ➔ highest value that is <= the real value