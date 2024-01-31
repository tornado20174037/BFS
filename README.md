# BFS
LeetCode 126: Word Ladder II Solution

Solution
Starting from the initial word. 
Find all the words in the dictionary that can take one step(Change one letter a time) and put them in the queue.
Then traverse the queue until the target word is found. 
Return all shortest paths: Add an array during BFS and store the words passed through each layer. Once the target word is found, trace back the entire array to get the answer.

Note that all words in the dictionary can only be used once, otherwise there may be a loop and it will be an infinite loop. 
