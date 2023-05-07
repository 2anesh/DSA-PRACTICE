class Solution {
public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    vector<int> answer, tmp = {INT_MAX};
    
    for(auto &x : obstacles){
      int id = upper_bound(tmp.begin(),tmp.end(),x) - tmp.begin();
      if(id == tmp.size()) id--;
      
      if(tmp[id] > x) tmp[id] = x;
      else{
        id++;
        if(id == tmp.size()) tmp.push_back(x);
        else if(tmp[id] > x) tmp[id] = x;
      }
      answer.push_back(id+1);
    }
    
    return answer;
  }
};
