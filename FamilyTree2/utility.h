#include <vector>
#include <string>
// class not used due to compile error
std::vector<std::string> splitString(const std::string& s) {

    std::vector<std::string> v;
    std::size_t curr_idx = 0;
    std::size_t idx = std::string::npos;
    do {
        idx = s.find(",", curr_idx);
        std::string token = s.substr(curr_idx, idx-curr_idx);
        v.push_back(token);
        curr_idx = idx+1;
    } while (idx != std::string::npos);

    return v;
}
