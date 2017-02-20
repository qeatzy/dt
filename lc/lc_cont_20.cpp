#include "utility.h"

// https://leetcode.com/contest/leetcode-weekly-contest-20/problems/beautiful-arrangement/
    int countArrangement(int N) {
        if (N < 1) return 0;
        std::set<std::pair<int,int>> vk;
        for (int i = 1; i <= N; ++i) {
            int cnt = 0;
            for (int j = 1; j <= N; ++j) { cnt += (i%j==0) || (j%i==0); }
            vk.insert(std::make_pair(cnt, i));
        }
        // for (auto x: vk) {
        //     cout << ".first = " << x.first << ", .second = " << x.second << endl;
        // }
        // wait("after print vk");
        // std::vector<int> A, B = rrange(1,N);
        std::vector<int> A;
        int cnt = 0;
        for (auto x: vk) {
            A.push_back(x.second);
        }
        // print(A,"A");
        auto B = A;
        // print(B,"B");
        // wait("before trim_tree\n");
        std::function<void(int)> trim_tree;
        trim_tree = [&trim_tree,&cnt,&A,&B,N](int i) {
            auto a = A[i];
            auto is_ok = [](int a, int b) {
                // cout << "a = " << a << ", b = " << b << endl;
                return (a % b == 0) || (b % a == 0);
            };
                // cout << "i = " << i << ", N = " << N << endl;
                // wait("begin trim");
            if (i == N-1) {
                // if (is_ok(a,B[i])) {
                //     print(B,"B");
                // }
                cnt += is_ok(a,B[i]);
                return;
            }
                // wait("begin loop");
            for (auto j = i; j < N; ++j) {
                if (is_ok(a,B[j])) {
                    // cout << "i = " << i << ", j = " << j << ", a = " << a << ", b = " << B[j] << endl;
                    // wait();
                    std::swap(B[i],B[j]);
                    trim_tree(i+1);
                    std::swap(B[i],B[j]); // TODO why restore is needed?? delete this line lead to wrong result.
                }
            }
        };
        trim_tree(0);
        // cout << "cnt = " << cnt << endl;
        return cnt;
    }
namespace test {
    void countArrangement() {
        for (auto i: rrange(1,20)) {  // 864.843 sec for 30, 0.179141 sec for 20. 
        // for (auto i: {5}) {
            auto cnt = ::countArrangement(i);
            cout << "cnt[" << i << "] == " << cnt << endl;
        }
    }
}

// https://leetcode.com/contest/leetcode-weekly-contest-20/problems/detect-capital/
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() < 2) return true;
        auto p = word.begin();
        if (isupper(*p)) {
            ++p;
        }
        for (const auto t = isupper(*p); ++p < word.end() && t == isupper(*p);){
        }
        return p == word.end();
    }
};

// template <typename Iterator, typename T = typename std::iterator_traits<Iterator>::value_type,
//          typename R, typename Monad = std::function<R(T)> >  // can't deduce R
//          // template<typename R, typename ... > class Monad >   // no outer R, only inner R
//          // template<typename ... > class Monad, typename R = typename Monad::result_type >
//          // template<typename ... > class Monad, typename R >
//          // template<typename ... > class Monad >
// // auto makeSet(Iterator first, Iterator last, Monad<R,T> f) -> std::set<typename Monad<R,T>::result_type> {
// // auto makeSet(Iterator first, Iterator last, Monad<...> f) -> std::set<typename Monad<...>::result_type> {
// std::set<R> makeSet(Iterator first, Iterator last, Monad f) {
//     std::set<R> res;
//     for (; first != last; ++first) res.insert(f(*first));
//     return res;
// }

// template <
//   class Iterator,
//   class UnaryFunction
// >
// auto makeSet(Iterator first, Iterator last, UnaryFunction f) -> std::set<decltype(f(*first))>
// {
//   std::set<decltype(f(*first))> res;
//   for (; first != last; ++first) res.insert(f(*first));
//   return res;
// }

// (commented code are some other *failed* attempt).
template <typename Iterator, typename Lambda>
auto makeSet(Iterator first, Iterator last, Lambda &&f) {

    typedef typename std::remove_reference<decltype(first->first)>::type const_first_t;

    typedef typename std::remove_const<const_first_t>::type first_t;

    typedef typename std::remove_reference<decltype(first->second)>::type second_t;

    typedef std::pair<first_t, second_t> R;


    std::set<R> res;

    for (; first != last; ++first) res.insert(f(*first));
    return res;
}

namespace test {
    void map() {
        std::map<int,int> kv;
        for (auto i: rrange(1,10)) {
            kv[i] = i % 7;
            // kv[i % 7] = i;
        }
        for (auto it = kv.begin(); it != kv.end(); ++it) {
            cout << "kv[" << it->first << "] == " << it->second << endl;
        }
        auto vk = ::makeSet(kv.begin(), kv.end(), [](std::pair<int,int> x) -> auto { return std::make_pair(x.second, x.first); });
        for (auto x: vk) {
            cout << ".first = " << x.first << ", .second = " << x.second << endl;
        }
        // print(kv);
    }
}

int main() {
    test::init();
    auto t = Timer();
    // test::map();
    test::countArrangement();
    t.show();
}

