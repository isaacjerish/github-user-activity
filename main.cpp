#include <iostream>
#include <fstream>
std::string url_builder(const std::string& username) {
    return "https://api.github.com/users/" + username + "/events";
}
bool download_events(const std::string& url, const std::string& outfile) {
    std::string cmd ="curl -s -A \"Mozilla/5.0\" \"" + url + "\" -o " + outfile;
    return std::system(cmd.c_str()) == 0;
}
void print_events(const std::string& json_path) {
    std::ifstream in(json_path);
    if (!in) {
        std::cerr << "Error: can’t open " << json_path << "\n";
        return;
    }
    std::string line;
    while (std::getline(in, line)) {
        auto pos = line.find("\"type\":");
        if (pos != std::string::npos) {
            pos = line.find('"', pos + 6) + 1;
            auto end = line.find('"', pos);
            std::string ev_type = line.substr(pos, end - pos);
            std::cout << "- " << ev_type << '\n';
        }
    }
}
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: github-activity <username>\n";
        return 1;
    }
    std::string username = argv[1];
    std::string url = url_builder(username);
    std::string save_loco = "/tmp/github_events.json";
    if (!download_events(url, save_loco)) {
        std::cerr << "GitHub request failed (network? bad username?).\n";
        return 1;
    }

    print_events(save_loco);
    remove(save_loco.c_str());
    return 0;
}