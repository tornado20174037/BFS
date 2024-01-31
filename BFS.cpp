#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

// Function to build the graph
unordered_map<string, vector<string>> buildGraph(const unordered_set<string>& wordList) {
    unordered_map<string, vector<string>> graph;

    // Traverse the word list
    for (const string& word : wordList) {
        // Replace each character of each word with a wildcard to create edges in the graph
        for (int i = 0; i < word.size(); ++i) {
            string temp = word;
            temp[i] = '*';
            graph[temp].push_back(word);
        }
    }

    return graph;
}

// Function for BFS to find shortest paths
vector<vector<string>> findLadders(string startWord, string endWord, unordered_set<string> wordList) {
    vector<vector<string>> result;  // Store the final result
    unordered_map<string, vector<string>> graph = buildGraph(wordList);  // Build the graph

    queue<vector<string>> q;
    q.push({startWord});  // Initialize the queue with the starting path containing the starting word

    unordered_map<string, int> distances;  // Store the distance from the startWord to each word
    distances[startWord] = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        unordered_set<string> visitedThisLevel;  // Avoid visiting words from the same level to prevent cycles

        for (int i = 0; i < levelSize; ++i) {
            vector<string> currentPath = q.front();
            q.pop();

            string currentWord = currentPath.back();
            cout << "Current Word: " << currentWord << " at distance " << distances[currentWord] << endl;

            for (int j = 0; j < currentWord.size(); ++j) {
                string temp = currentWord;
                temp[j] = '*';  // Replace the j-th character of the current word with a wildcard

                if (graph.find(temp) != graph.end()) {
                    for (const string& neighbor : graph[temp]) {
                        if (neighbor == endWord) {
                            // Found the target word, add the path to the result
                            currentPath.push_back(endWord);
                            result.push_back(currentPath);
                            cout << "Found the target word: " << endWord << ". Path added." << endl;
                        } else if (distances.find(neighbor) == distances.end() || distances[neighbor] == distances[currentWord] + 1) {
                            // Neighbor word has not been visited or is a shorter path, update the distance and enqueue
                            distances[neighbor] = distances[currentWord] + 1;
                            vector<string> newPath = currentPath;
                            newPath.push_back(neighbor);
                            q.push(newPath);
                            cout << "Enqueued: " << neighbor << " at distance " << distances[neighbor] << endl;
                        } else {
                            // Neighbor word has been visited or is not the shortest path, skip it
                            cout << "Skipped: " << neighbor << " (already visited or not the shortest path)" << endl;
                        }
                    }
                }
            }
            visitedThisLevel.insert(currentWord);
        }

        // Remove words visited at this level to avoid cycles
        for (const string& word : visitedThisLevel) {
            wordList.erase(word);
        }
    }

    return result;
}

int main() {
    string startWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> result = findLadders(startWord, endWord, wordList);

    // Print the result
    for (const auto& path : result) {
        cout << "Shortest Path: ";
        for (const string& word : path) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
