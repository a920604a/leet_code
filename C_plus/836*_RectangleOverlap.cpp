class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //  加等號 是因為To be clear, two rectangles that only touch at the corner or edges do not overlap.
        if(rec1[2] <= rec2[0] ) return false;
        if(rec1[0] >= rec2[2]) return false;
        if(rec1[1] >= rec2[3] ) return false;
        if(rec1[3] <= rec2[1]) return false;
        return true;
    }
};