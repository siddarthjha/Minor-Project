# Minor-Project
My first project undertaking in C language

TOPIC: **Comparitive analysis of Un-informed Search Algorithms**


Implementation of 
1. DFS
2. BFS
3. DLS
4. IDDFS,
all these algorithms in C language and their comparison with respect to time and space complexity.

## State Space Search
Set of all possible states for a given problem is known as state space of the problem.

There are two types of search:
1. **Un-informed Search**
2. **Informed Search**

### Un-informed Search
These are such problems where we don't know any domain specific information. So we have to search without any additional knowledge of the target state. Hit and trial method.

### Informed Search
In this type of problems we have prior knowledge of our target state like functions to guide the search proceedures. So we will be able to get to the target state.

**Note:** Knowledge in the previous context means "**Derived from experience,Stores experience and change the search rules further**"".

For Searching, We need
1. Initial state description of problem.
2. Set of legal operators[Conditions].
3. Final (or) goal state.

* Go through the following links for understanding of the following algorithms.

1. [**DFS**](https://www.javatpoint.com/depth-first-search-algorithm)<br>
2. [**BFS**](https://www.javatpoint.com/breadth-first-search-algorithm)<br>
3. [**DLS**](https://www.javatpoint.com/ai-uninformed-search-algorithms)<br>
4. [**IDDFS**](http://theoryofprogramming.com/2018/01/14/iterative-deepening-depth-first-search-iddfs/)<br>

We have entered the following data: 65,24,78,70,96,22,39,12,23,5,15,3,10,100,85.
<br>
![image](https://github.com/siddarthjha/Minor-Project/blob/master/Image/data1.PNG)<br>
Now, we will perform search of a particular value with all four of the algorithms.
<br>
![BFS](https://github.com/siddarthjha/Minor-Project/blob/master/Image/ot1.PNG)<br>
The time taken to find (96) is 35.8 sec with BFS Algorithm.<br>
![DFS](https://github.com/siddarthjha/Minor-Project/blob/master/Image/ot2.PNG)<br>
The time taken to find(96) is 30.98 sec with DFS Algorithm.<br>
![DLS](https://github.com/siddarthjha/Minor-Project/blob/master/Image/ot1.3.PNG)<br>
The time taken to find(96) is 34.41 sec with DLS Algorithm.<br>
![DFS](https://github.com/siddarthjha/Minor-Project/blob/master/Image/ot1.4.PNG)<br>
The time taken to find(96) is 27.42 sec with IDDFS Algorithm.<br>
Alright, By seeing the different time taken by different algorithms you can see the optimized algorithm, but it's not necessary that IDDFS algorithm will give you the optimized result always.<br>
1. This was applied for large datasets where there may be infinite long trees and take a lot of time to traverse in such cases IDDFS algorithm will give you the best result.

