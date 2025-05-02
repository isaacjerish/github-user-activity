#include <iostream>


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: github-activity <username>\n";
        return 1;
    }
    return 0;
}