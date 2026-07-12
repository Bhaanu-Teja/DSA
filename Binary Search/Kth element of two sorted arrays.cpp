class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int a1 = a.size();
        int b1 = b.size();
        int c1 = a1 + b1;
        int j = 0;
        int l = 0;
        vector<int>c;
        for(int i = 0; i<c1; i++){
            if(c.size() == k) return c[k-1];
            if(j >= a1){
                c.push_back(b[l]);
                l++;
            }
            else if(l >= b1){
                c.push_back(a[l]);
                l++;
            }
            else if(a[j]<b[l]){
                c.push_back(a[j]);
                j++;
            }
            else{
                c.push_back(b[l]);
                l++;
            }
        }
        return c[k-1];
  }
};
