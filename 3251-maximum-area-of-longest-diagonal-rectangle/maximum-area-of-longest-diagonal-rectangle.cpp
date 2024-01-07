class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        int n = dim.size();
        double dig = 0.0;
        int area = 0;
        for(int i = 0; i < n; i++){  // finding the max diagonal of the rect
            double t = sqrt((dim[i][0]*dim[i][0]*1.0) + (dim[i][1] * dim[i][1]*1.0));
            int ar = dim[i][0] * dim[i][1];
            if(double(t*1.0) >= double(dig*1.0)){
                dig = t;
            }
        }
        
        for(int i = 0; i < n; i++){   //getting the max area for the max dig value.
            double t = sqrt((dim[i][0]*dim[i][0]*1.0) + (dim[i][1] * dim[i][1]*1.0));
            if(t == dig){
                area = max(area, dim[i][0] * dim[i][1]);
            }
        }
        
        return area;
    }
};