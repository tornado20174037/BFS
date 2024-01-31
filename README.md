# BFS
LeetCode 126: Word Ladder II Solution


![image](https://github.com/tornado20174037/BFS/assets/38320598/0ca05b84-3a2b-46d8-a18c-d2d3f108842e)

![image](https://github.com/tornado20174037/BFS/assets/38320598/cc0e1e13-368b-43af-be61-15b29028122d)

Solution

Starting from the initial word. 
  Find all the words in the dictionary that can take one step(Change one letter a time) and put them in the queue.
  Then traverse the queue until the target word is found. 
  Return all shortest paths: Add an array during BFS and store the words passed through each layer. Once the target word is found, trace back the entire array to get the answer.
  Note that all words in the dictionary can only be used once, otherwise there may be a loop and it will be an infinite loop. 
