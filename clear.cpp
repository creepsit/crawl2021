#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "token.h"

void process(std::string& line) {
    line.erase(line.length() - 2, 2);
    std::vector<std::string> tokens = tokenize(line, ",");
    std::vector<std::string> tokens_;
    for (int i = 2; i < 14; i++) {
        std::vector<std::string> temp = tokenize(tokens[i], ":");
        i == 2 ? tokens_.push_back(temp[2]) : tokens_.push_back(temp[1]);
    }
    for (int i = 0; i < 12; i++) {
        if (tokens_[i][0] == '"') {
            tokens_[i].erase(0, 1);
            tokens_[i].erase(tokens_[i].length() - 1, 1);
        }
    }
    line = "";
    for (int i = 0; i < 12; i++) {
        i == 11 ? line += tokens_[i] : line += tokens_[i] + ",";
    }
}

int main() {
    std::fstream fileclone("textclone.txt");
    std::fstream fileclear("b.txt", std::ios::app);
    std::string diem[34480] = {""};
    for (int i = 0; i < 34480; i++) {
        getline(fileclone, diem[i]);
        if(i <= 8719) {
            diem[i].erase(0, 2);
            diem[i].erase(diem[i].length() - 1, 1);
        }
        process(diem[i]);
    }
    for (int i = 0; i < 34480; i++) {
        i == 34479 ? fileclear << diem[i] : fileclear << diem[i] + "\n";
    }

    return 0;
}