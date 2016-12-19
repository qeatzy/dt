typedef std::vector<int> iVec;

using std::cout;

template <typename T>
void print(std::vector<T> vec) {
    // for(T x: vec) { std::cout << x << ' '; }
    for(auto it = vec.begin(); it != vec.end(); ++it) { std::cout << *it << ' '; }
    std::cout << std::endl;
}

iVec range(int start, int stop, int step) {
    /* generate a sequence.
     * step must **NOT** be zero.
     * TODO: refactor to generic to allow double parameters. Or restrict range to int, use
     * linspace for double instead?
     */
    // static_assert(step != 0, "step must **NOT** be zero.");
    auto cmp = (step>0) ? [](int left, int right) { return left < right; }
                        : [](int left, int right) { return left > right; };
    iVec res;
    while(cmp(start, stop)) {
        res.push_back(start);
        start += step;
    }
    return res;
}
iVec range(int start) {
    return range(0, start, 1);
}
iVec range(int start, int stop) {
    return range(start, stop, 1);
}

class Prime {
    public:
        Prime() {
            this->primes = iVec {2,3,5,7};
            this->threshold = 10;
        }
        Prime(int threshold) {
            Prime();
            if (threshold > this->threshold)
                this->update(threshold);
        }
        iVec operator()(int threshold) {
            if (threshold > this->threshold) {
                this->update(threshold);
            }
            // TODO(efficiency): is this copy approach good enough, could a non-writable view be returned instead?
            return iVec(primes.begin(), std::upper_bound(primes.begin(), primes.end(), threshold));
        }
    private:
        iVec primes;
        int threshold;
        void update(int threshold) {
            auto small_primes = this->operator()(sqrt(threshold));
            auto is_prime = [&small_primes](int val) {
                for (auto x: small_primes) 
                    if (val%x == 0)
                        return false;
                return true;
            };
            auto candidate = this->threshold;
            while(++candidate <= threshold) {
                if (is_prime(candidate))
                    this->primes.push_back(candidate);
            }
            this->threshold = threshold;
        }
};

