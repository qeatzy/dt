#include "utility.h"
// Names scores
// https://projecteuler.net/problem=22
// For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
// What is the total of all the name scores in the file?
// wget https://projecteuler.net/project/resources/p022_names.txt
// 871198282

std::vector<std::string> read_words(std::string filename) {
    std::ifstream ifs(filename);
    std::stringstream ss;
    ss << ifs.rdbuf();
    std::regex non_letter_regex(R"([,"]+)");
    std::string new_buffer = std::regex_replace(ss.str(), non_letter_regex, " ");
    // ss.rdbuf()->pubsetbuf(new_buffer);
    ss.str(new_buffer);
    std::vector<std::string> words;
    for (std::string word; ss >> word; ) {
        words.push_back(word);
    }
    return words;
}

int main() {
    std::string filename = "p022_names.txt";
    std::vector<std::string> words = read_words(filename);
    // cout << words.size();
    std::sort(words.begin(), words.end());
    long long total_score = 0;
    for (int pos = 0; (size_t)pos < words.size(); ++pos) {
        int score = 0;
        for (auto c: words[pos]) {
            score += c - 'A' + 1;
        }
        if (words[pos] == "COLIN") { cout << pos << " score= " << score << endl; }
        total_score += (pos+1) * score;
    }
    cout << total_score;
}
