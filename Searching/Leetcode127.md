## Leetcode 127 - Word Ladder

Given two words beginWord and endWord, and a dictionary wordList, return the length of the shortest transformation sequence from beginWord to endWord, such that:

- Only one letter can be changed at a time.
- Each transformed word must exist in the word list.
Return 0 if there is no such transformation sequence.

Example 1:
```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
```

Example 2:
```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
```

Constraints:
```
1 <= beginWord.length <= 100
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the strings in wordList are unique.
```

### C++
```c++
class Solution {
private:
    bool connect(const string &that, const string &other) {
        int distinct = 0;
        for(int i = 0; i < that.length(); i++) {
            if(that[i] != other[i]) {
                distinct ++;
            }
        }
        return distinct == 1;
    }
    
    void build_graph(string &beginWord, vector<string>& wordList, map<string, vector<string>> &graph) {
        wordList.push_back(beginWord);
        for(int i = 0; i < wordList.size(); i++) {
            graph[wordList[i]] = vector<string>();
        }
        for(int i = 0; i < wordList.size(); i++) {
            for(int j = i+1; j < wordList.size(); j++) {
                if(connect(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }
    
    int BFS(string &beginWord, string &endWord, map<string, vector<string>> &graph) {
        queue<pair<string, int>> Q;
        set<string> visit;
        Q.push(make_pair(beginWord, 1));
        visit.insert(beginWord);
        
        while(!Q.empty()) {
            string node = Q.front().first;
            int step = Q.front().second;
            Q.pop();
            if(node==endWord) {
                return step;
            }
            const vector<string> &neighbors = graph[node];
            for(int i = 0; i < neighbors.size(); i++) {
                if(visit.find(neighbors[i]) == visit.end()) {
                    Q.push(make_pair(neighbors[i], step+1));
                    visit.insert(neighbors[i]);
                }
            }
        }
        
        return 0;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> graph;
        build_graph(beginWord, wordList, graph);
        return BFS(beginWord, endWord, graph);
    }
};
```

### Java
```java
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        Map<String, List<String>> graph = new HashMap<>();
        build_graph(beginWord, wordList, graph);
        
        return BFS(beginWord, endWord, graph);  
    }
    
    Integer BFS(String beginWord, String endWord, Map<String, List<String>> graph) {
        
        HashSet<String> visited = new HashSet<>();
        Queue<QEntity> q = new LinkedList<>();
        q.offer(new QEntity(beginWord, 1));
        visited.add(beginWord);
        
        while(!q.isEmpty()) {
            
            String word = q.peek().getWord();
            int step = q.peek().getStep();
            q.poll();
            
            
            if(word.equals(endWord)) {
                return step;
            }
            
            List<String> neighbors = graph.get(word);
            
            for(int i = 0; i < neighbors.size(); i++) {
                if(!visited.contains(neighbors.get(i))) {
                    q.offer(new QEntity(neighbors.get(i), step+1));
                    visited.add(neighbors.get(i));
                }
            }
        }
        
        return 0;
    }
    
    Boolean connect(String that, String other) {
        int num = 0;
        for(int i = 0; i < that.length(); i++) {
            if(that.charAt(i) != other.charAt(i)) {
                num ++;
            }
        }
        return num==1;
    }
    
    void build_graph(String beginWord, List<String> wordList, Map<String, List<String>> graph) {
        wordList.add(beginWord);
        
        for(int i = 0; i < wordList.size(); i++) {            
            graph.put(wordList.get(i), new ArrayList<String>());
        }
        
        for(int i = 0; i < wordList.size(); i++) {
            for(int j = i+1; j < wordList.size(); j++) {
                if(connect(wordList.get(i), wordList.get(j))) {
                    graph.get(wordList.get(i)).add(wordList.get(j));
                    graph.get(wordList.get(j)).add(wordList.get(i));
                }
            }
        }
    }
    
    
    class QEntity {
        String word;
        Integer step;
        public QEntity(String word, Integer step) {
            this.word = word;
            this.step = step;
        }
        String getWord() {
            return this.word;
        }
        Integer getStep() {
            return this.step;
        }
    }
}
```
