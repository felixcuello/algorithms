class Solution {
public:
  string reversePrefix(string word, char ch) {
    // busco el indice
    int idx = 0;
    bool found = false;
    for(; word[idx]!=ch && idx < word.size(); idx++);
    
    // edge case, la letra no está
    if(idx == word.size())
      return word;
    
    // hago un swap con dos punteros hasta que se cruzan
    for(int i=0; i<idx;) {
      char t = word[i];
      word[i] = word[idx];
      word[idx] = t;
      i++;
      idx--;
    }
    
    // devuelvo el string resultante
    return word;
  }
};
