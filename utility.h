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

// int debug_num = 0;
class Prime {
    public:
        Prime() {
            this->primes = iVec {2,3,5,7,11};
            this->threshold = 11;
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
        iVec::const_iterator get_pos(int threshold) {
            if (threshold > this->threshold) {
                this->update(threshold);
            }
            return std::upper_bound(primes.cbegin(), primes.cend(), threshold);
        }
        int nth_prime(int n) {
            auto threshold = n;
            while (n > primes.size()) {
                if (threshold < this->threshold) {}
                threshold *= 3;
                // cout << "will update. current size is " << primes.size() << ", threshold is " << threshold << '\n';
                this->update(threshold);
            }
            // printf("primes.size() = %zu\n", primes.size());
            return primes[n-1];
        }
        iVec getall() { return this->primes; }
    private:
        iVec primes;
        int threshold;
        void update(int threshold) {
            this->primes.reserve(1.25506 * threshold / log(threshold) );
            // printf("debug_num = %d\n", ++debug_num);
            auto pos = this->get_pos(sqrt(threshold));
            // cout << "threshold = " << threshold << ", pos is nth: " << pos - primes.cbegin() << '\n';
            auto is_prime = [this, pos](int val) {
                for (auto it = primes.cbegin(); it != pos; ++it) {
                    if (val % (*it) == 0)
                        return false;
                }
                return true;
            };
            auto candidate = this->threshold + (this->threshold + 1) % 2;
            for(; candidate <= threshold; candidate += 2) {
                if (is_prime(candidate))
                    this->primes.push_back(candidate);
            }
            this->threshold = threshold;
        }
};
