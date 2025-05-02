#include <iostream>
std::string url_builder(const std::string& username) {
    return "https://api.github.com/users/" + username + "/events";
}
bool download_events(const std::string& url, const std::string& outfile) {
    std::string cmd ="curl -s -A \"Mozilla/5.0\" \"" + url + "\" -o " + outfile;
    return std::system(cmd.c_str()) == 0;
}
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: github-activity <username>\n";
        return 1;
    }
    return 0;
}