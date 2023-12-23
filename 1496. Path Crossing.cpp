class Solution {
public:
    bool isPathCrossing(string path) {
        int n=path.length();
        set<pair<int, int>>st;
        st.insert({0, 0});
        int ix=0, iy=0;
        for(int i=0; i<n; i++){
            int dx=0;
            int dy=0;
            char ch=path[i];
            if(ch=='N'){
                dy=1;
            }else if(ch=='S'){
                dy=-1;
            }else if(ch=='E'){
                dx=1;
            }else dx=-1;
            ix+=dx;
            iy+=dy;
            if(st.find({ix, iy})!=st.end()) return 1;
            st.insert({ix, iy});
        }
        return 0;
    }
};
