class ProductOfNumbers {
    vector<int> prefix{1};  

public:
    void add(int num) {
        if (num == 0)
            prefix = {1};  
        else
            prefix.push_back(prefix.back() * num);
    }

    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) 
            return 0;
        return prefix[n - 1] / prefix[n - 1 - k];
    }
};