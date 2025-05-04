#include <iostream>
#include <fstream>

// Builds the GitHub API URL for the given username
std::string url_builder(const std::string& username) {
    return "https://api.github.com/users/" + username + "/events";
}

// Downloads the GitHub events JSON using curl and saves it to the specified file
bool download_events(const std::string& url, const std::string& outfile) {
    std::string cmd = "curl -s -A \"Mozilla/5.0\" \"" + url + "\" -o " + outfile;
    return std::system(cmd.c_str()) == 0;
}

// Parses the downloaded JSON file and prints out the event types
void print_events(const std::string& json_path) {
    std::ifstream in(json_path);
    if (!in) {
        std::cerr << "Error: can’t open " << json_path << "\n";
        return;
    }

    std::string line;
    while (std::getline(in, line)) {
        // Look for lines containing "type": to identify event types
        auto pos = line.find("\"type\":");
        if (pos != std::string::npos) {
            // Move past the key to get the actual event type string
            pos = line.find('"', pos + 6) + 1;
            auto end = line.find('"', pos);
            std::string ev_type = line.substr(pos, end - pos);
            std::cout << "- " << ev_type << '\n';
        }
    }
}

int main(int argc, char* argv[]) {
    // Check that exactly one argument (the GitHub username) is provided
    if (argc != 2) {
        std::cerr << "Usage: github-activity <username>\n";
        return 1;
    }

    std::string username = argv[1];
    std::string url = url_builder(username);

    // Save location for downloaded JSON (temporary file)
    std::string save_loco = "/tmp/github_events.json";

    // Download data from GitHub API
    if (!download_events(url, save_loco)) {
        std::cerr << "GitHub request failed (network? bad username?).\n";
        return 1;
    }

    // Parse and display event types
    print_events(save_loco);

    // Clean up: delete the downloaded JSON file
    remove(save_loco.c_str());

    return 0;
}