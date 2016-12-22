#include "utility.h"

// template <typename ValType, ValType base>
class Int {
    public:
    typedef int ValType;
    typedef long long ProdType;
    Int (ValType x) :  value {x} {
        if(x > Int::BASE) {
            this->value[0] %= Int::BASE;
            this->value.push_back(x / Int::BASE);
        }
    }
    Int () : Int(0) {
    }
    Int (string x) {
        value = rebase(x);
    }
    Int (const Int& x) : value{x.value} {} // TODO 
    // Int (vector<ValType> x) : value{x} {}   // TODO, disable this? since this should only be allowed for immediate implementer.
    Int (vector<ValType> x, bool validity_check=true) : value{x} {}  // TODO, default argument issue. http://stackoverflow.com/a/20771474/3625404
    const vector<ValType> & data() const { return this->value; }
    size_t dlen() const { return this->value.size(); }
    Int pow(int exponent);
    static Int pow(int base, int exponent);  // TODO, how to effectively forbid negative input?
    void operator*=(Int::ValType rhs);
    friend Int operator+(const Int& lhs, const Int& rhs);
    friend Int operator*(const Int& lhs, const Int& rhs);   // TODO, may overflow if lhs.value.size() is too large. -- how large? what is the possibility of overflow in real application?
    // Int operator*=(Int::ValType rhs);
    friend std::ostream& operator<<(std::ostream& os, const Int& obj);
    private:
    static constexpr ValType BASE = 1000000000;     // BASE + BASE do not overflow ValType.
    static constexpr ValType kdigits = 9;
    static constexpr ValType VAL_MAX = INT_MAX;
    vector<ValType> value;
    ValType digits_to_int (const char* p, const char* pend, int base) {
        // caution, **NO** error handling. 
        // assert(p < pend) // TODO, fix same place in 13.cpp, currently misspelled as 11.cpp.
        ValType res = 0;
        for(; p != pend; ++p) {
            res = res * base + (*p - '0');
        }
        return res;
    }
    vector<ValType> rebase(string num) {
        // cout << "num = " << num << '\n';
        vector<ValType> res;
        auto pbegin = num.c_str();
        auto pright = const_cast<char*>(pbegin) + num.size();
        auto pleft = const_cast<char*>(pright) - kdigits;
        // auto pright = const_cast<char*>(pbegin) + kdigits;
        // cout << pleft << ' ' <<  pright << ' ' << pend << '\n';
        for (; pleft >= pbegin; pleft -= kdigits, pright -= kdigits) {
            res.push_back(digits_to_int(pleft, pright, 10));
            // cin.get();
        }
        if (pbegin < pright) { // TODO, fix same place in 13.cpp, currently misspelled as 11.cpp.
            res.push_back(digits_to_int(pbegin, pright, 10));
        }
        return res;
    }
};
Int Int::pow(int exponent) {
    return Int(*this);
}
Int Int::pow(int base, int exponent) {
    Int::ValType new_base = base, k_base = 1;
    for(; (Int::ProdType)new_base * base < Int::BASE; new_base *= base) {
        ++k_base;
    }
    auto res = Int(std::pow(base, exponent % k_base));
    // cout << "res is: " << res;
    // printf("base = %d, exponent = %d\n", base, exponent);
    exponent /= k_base;
    // printf("new_base = %d, exponent = %d\n", new_base, exponent);
    // auto base_Int = Int(new_base);
    for(; exponent > 0; --exponent) {
        // cout << "res is: " << res;
        // auto tmp = res * base_Int;
        // printf("outside mul, res here: ");
        // cout << tmp;
        // wait();
        res *= new_base;
    }
    return res;
}
std::ostream& operator<<(std::ostream& os, const Int& obj) {
    // TODO, remove access to data() to improve encapsulation.
    // auto it = obj.value.begin();
    // for (; it + 1 < obj.value.end(); ++it) {
    //     printf("%09d ", *it); // TODO, fix this, since Int::ValType is not guaranteed to be int. Or rather reuse to_string method?  Or is operator<< indeed 'to_string' when used with sstream? http://stackoverflow.com/questions/1549930/c-equivalent-of-java-tostring
    // }
    // printf("%d\n", *it);
    char *output = new char[Int::kdigits * obj.value.size()];
    auto p = output;
    auto it = obj.value.rbegin();
    int n_char =  sprintf(p, "%d", *it);
    if (n_char <= 0) {
        std::cerr << "something wrong. terminated.";
        exit(1);
    }
    p += n_char;
    for (++it; it != obj.value.rend(); ++it) {
        sprintf(p, "%09d", *it);
        p += Int::kdigits;
    }
    // auto sum_digits = [](const char *num) -> int {
    //     int res = 0;
    //     for (; *num; ++num) {
    //         res += (*num) - '0';
    //     }
    //     return res;
    // };
    // cout << sum_digits(output) << '\n';
    // std::ofstream out("/home/Dell/code/qeatzy/project_euler/tmpc");
    // out << output;
    os << output << '\n';
    return os;
}
Int operator+(const Int& lhs, const Int& rhs) {
    // auto llen = lhs.dlen(), rlen = lhs.dlen();
    auto rlen = rhs.dlen();
    // assert(llen < rlen);
    // TODO 
    auto res = vector<Int::ValType>(rlen);
    std::transform(lhs.value.begin(), lhs.value.end(), rhs.value.begin(), res.begin(), [](Int::ValType x, Int::ValType y) { return x+y; });
    Int::ValType carry=0;
    std::for_each(res.begin(), res.end(), [&carry](Int::ValType & x) { x += carry; carry = x / Int::BASE; x %= Int::BASE; });
    // std::for_each(res.begin(), res.end(), [](Int::ValType & x) { x /= 4;});
    if (carry > 0) { res.push_back(carry); }
    // for(auto
    return Int(res);
}
Int operator*(const Int& lhs, const Int& rhs) {
    // b := Int:BASE, m = lhs.value.size(), n = rhs.value.size(), 
    // lhs = x0, ..., x{m-1}
    // rhs = y0, ..., y{n-1}
    // assert m>n
    // for k in [0,n), sum((y{k} * lhs) << k) == result.
    // TODO, should be parallel or not, that is possibly parallel sum a collection of
    // vectors vs only use two vectors and just add the newly computed to result
    // candidate, or put it another way, which way should we choose, in the tradeoff of
    // parallel but more allocation vs less allocation but no parallel. -- note, their is
    // two step of aggregation, what we are talking is the second, the first one could always be parallelized.
    // FFT? Strassen’s Matrix Multiplication? could be applied if m != n?
    // http://www.geeksforgeeks.org/multiply-two-polynomials-2/
    // http://www.cs.cmu.edu/afs/cs/academic/class/15451-s10/www/lectures/lect0423.txt
    // The idea of using 3 multiplications instead of 4 is used in large-integer multiplications. A similar idea is the basis of the classic Str assen matr ix multiplication algor ithm (CLRS, Chapter 28).  http://www.cse.ust.hk/~dekai/271/notes/L03/L03.pdf
    // search for "large-integer multiplications"
    // my idea: prod as 2 digit(on base) sum, thus if ValType be int, ProdType be llong,
    // thus can handle pow(Int::BASE, Int::BASE) product without ever consider carry, thus
    // could be easily parallelized. further more, locally, faster algorithm such as
    // Karatsuba algorithm could be used, but under this context, is the boost obvious?
    auto llen = lhs.dlen(), rlen = rhs.dlen();
    vector<Int::ProdType> res(llen + rlen);
    // assert(llen < rlen);
    auto pres = res.begin();
    // int tmp_num = 0;
    // 192697801 952228884 666154138 860192608 588445951 749658170 748568225 596231121 747048255 283962789 974429070 092304182 403176631 673114324 098246982 999999999
    // 192697801 952228884 666154138 860192608 588445951 749658170 748568225 596231121 747048255 283962789 974429070 092304182 403176631 673114324 098246982 999999999   in python 
    for (auto rit=rhs.value.begin(); rit < rhs.value.end(); ++rit) {
        auto p = pres++;
        for (auto lit=lhs.value.begin(); lit < lhs.value.end(); ++lit) {
            Int::ProdType prod = (Int::ProdType)(*rit) * (*lit);
            // printf("prod = %lld, tmp_num = %d\n", prod, tmp_num++);
            // wait();
            // cout << prod << ' ';
            p[0] += prod % Int::BASE;
            p[1] += prod / Int::BASE;
            p++;
        }
    }
    // printf("llen = %d, rlen = %d\n", llen, rlen);
    // printf("inside mul, res here: "); print(res);
    vector<Int::ValType> final_res;
    final_res.reserve(res.size());
    auto p = res.begin();
    for (; p+1 < res.end(); ++p) {
        p[1] += p[0] / Int::BASE;
        final_res.push_back(p[0] % Int::BASE);
    }
    final_res.push_back(p[0] % Int::BASE);
    if (p[0] / Int::BASE > 0) {
        final_res.push_back(p[0] / Int::BASE);
    }
    return Int(final_res);
}
void Int::operator*=(Int::ValType rhs) {
    auto p = this->value.begin();
    Int::ProdType prod = 0;  // as both carry and prod
    for(; p+1 < this->value.end(); ++p) {
        // cout << "enter loop\n";
        prod += (Int::ProdType) p[0] * rhs;
        p[0] = prod % Int::BASE;
        prod /= Int::BASE;
    }
    prod += (Int::ProdType) p[0] * rhs;
    // cout << "prod = " << prod << '\n';
    // cout << "before update, p[0] = " << p[0] << '\n';
    p[0] = prod % Int::BASE;
    // cout << "after update, p[0] = " << p[0] << '\n';
    // cout << "this->value = "; print(this->value);
    if (prod > Int::BASE) {
        this->value.push_back(prod / Int::BASE);
    }
    // return (*this);
}
// template int foo<int, llong, 2>(int x);
// template int foo<int, 2>(int x);

int main() {
    // 989824698 698246999 982469824 824698246 246982469 469824698 98246982 999999999 1
    // 989824698 698246999 982469824 824698246 246982469 469824698 098246982 999999999 1  in python
    // auto a = Int(), b = Int(2123456789), c = Int("999999999549123491234912349123491234912349123491234912349123499994912349"), d=c;
    // cout << a << b << c << d << c+d << (c*d) * (c*d);
    // auto x = Int(33);
    // x *= 33;
    // cout << x;
    // auto ctime = std::time(nullptr);
    // cout << ctime << '\n';
    auto start = std::chrono::high_resolution_clock::now();
    cout << Int::pow(2,10000);
    // cout << Int::pow(11,1000000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << diff.count() << " s\n";
    // auto elapsed = std::time(nullptr) - ctime;
    // cout << "elapsed = " << elapsed << '\n';
    // cout << Int::pow(11,1000000);
    // 994912349 349123499 491234912 912349123 123491234 234912349 349123491 12
    // 989824698 698246999 982469824 824698246 246982469 469824698 698246982 24
    // 989824698 698246999 982469824 824698246 246982469 469824698 698246982 24 python
}


// how can I fix below code? (same error message if explicit instantiation line been commented out.)
//
//     #include <iostream>
//
//     template <typename ValType, ValType base>
//     ValType foo(ValType x) {
//         return x+base;
//     }
//
//     template int foo<int, 2>(int x);
//
//     int main() {
//         std::cout << foo(3);
//     }
//
//
// The error message as below,
// error: no matching function for call to ‘foo(int)’
// note: candidate: template<class ValType, ValType base> ValType foo(ValType)
// note:   template argument deduction/substitution failed:
// note:   couldn't deduce template parameter ‘base’
//
// How to explicitly instantiate a template function with both type and value parameter?
//
// C++ templates


