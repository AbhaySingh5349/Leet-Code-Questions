Question Link: https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers {
public:
    
    vector<int> p;
    int idx;
    
    ProductOfNumbers() {
        p.push_back(1);
        idx=-1;
    }
    
    void add(int num) {
        if(num==0 || p.back()==0){
            if(num==0) idx=p.size();
            p.push_back(num);
        }else{
            p.push_back(p.back()*num);
        }
    }
    
    int getProduct(int k) {
        int limit=p.size()-k;
        if(idx>=limit) return 0;
        
        if(p[limit-1]==0) return p.back(); // to avoid divide by zero
        
        return (p.back()/p[limit-1]);
    }
};
