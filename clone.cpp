#include <iostream>
#include <fstream>
#include <string>
#include "cmd.h"
int main() {

    std::fstream res("a.txt", std::ios::app);
    for (int i = 29034400; i < 29034481; i++) {
        std::string sbd = std::to_string(i);
        std::string url_ = "https://dantri.com.vn/thpt/3/0/99/" + sbd + "/2021/0.25/search-gradle.htm";
        std::string text = Command::exec("curl " + url_).output;
        res << "\n" << text;
    }
    res.close();
}