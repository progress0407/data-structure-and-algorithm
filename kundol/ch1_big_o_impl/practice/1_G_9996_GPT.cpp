#include <iostream>
#include <regex>
#include <string>

// Function to convert pattern to regex
std::string convertPatternToRegex(const std::string& pattern) {
    std::string regexPattern;
    for (char c : pattern) {
        if (c == '*') {
            regexPattern += ".*";
        } else {
            regexPattern += c;
        }
    }
    return regexPattern;
}

int main() {
    int n;
    std::string pattern;
    std::cin >> n;
    std::cin >> pattern;

    std::string regexPattern = convertPatternToRegex(pattern);
    std::regex reg(regexPattern);

    for (int i = 0; i < n; i++) {
        std::string filename;
        std::cin >> filename;
        if (std::regex_match(filename, reg)) {
            std::cout << "DA" << std::endl;
        } else {
            std::cout << "NE" << std::endl;
        }
    }

    return 0;
}
