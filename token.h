#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> tokenize (std::string s, std::string del = " "){
    //Used for testcase tokenizer, students don't need to take care of this function.
    std::vector<std::string> res;
    int start = 0;
    int end = (int)s.find(del);
    while (end != -1) {
        res.push_back(s.substr(start, end - start));
        start = (int)end + (int)del.size();
        end = (int)s.find(del, start);
    }
    res.push_back(s.substr(start, end - start));
    return res;
}