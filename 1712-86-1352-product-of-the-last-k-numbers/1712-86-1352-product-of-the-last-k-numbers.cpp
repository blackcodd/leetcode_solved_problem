class ProductOfNumbers {
public:
    vector<long long> prefix;
    int ind_of_0 = -1;

    ProductOfNumbers() {
        prefix.push_back(1); 
    }

    void add(int num) {
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
            ind_of_0 = prefix.size() - 1; 
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) {
            return 0;
        }
        return prefix.back() / prefix[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */