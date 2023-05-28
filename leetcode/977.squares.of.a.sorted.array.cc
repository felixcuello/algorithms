class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    int p=0; // positive pointer
    int ns = nums.size();
    vector<int> ans;
    
    for(; p<ns && nums[p]<0; p++);
    int n=p-1; // negative pointer
    
    while(n>=0 || p<ns) {
      int n2,p2;
      if(n >= 0) n2 = nums[n]*nums[n];
      if(p < ns) p2 = nums[p]*nums[p];
      
      if(n>=0 && p<ns) {
        if(n2 < p2) {
          ans.push_back(n2);
          n--;
        } else {
          ans.push_back(p2);
          p++;
        }
      } else if(n >= 0) {
        ans.push_back(n2);
        n--;
      } else if(p < ns) {
        ans.push_back(p2);
        p++;
      }
    }
    
    return ans;
  }
};

/*

Ideas:
-> La propiedad de los números negativos es que  a^2 == (-a)^2   \/ a Real

=>  Sabiendo que están ordenados
=>  Basta con encontrar el primer número positivo en el array y usar dos punteros para ir agregando a la respuesta
    Ejemplo:
    
      -2 -1 1 4
            p
          n

       voy moviendo p hacia la derecha y n hacia la izquierda conforme nums[p]^2 > nums[n]^2  (o viceversa)
*/
