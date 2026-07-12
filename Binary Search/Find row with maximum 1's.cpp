class Solution {
  public:   
  int rowWithMax1s(vector < vector < int >> & mat) {
    int index = -1;
    int max_cnt = -1;
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i<n;i++){
        int cnt_row = 0;
        for(int j = 0; j<m;j++){
            cnt_row += mat[i][j];
        }
        if(cnt_row > max_cnt){
            max_cnt = cnt_row;
            index = i;
        }
    }
    if(max_cnt == 0) return -1;
    return index;
  }
};
