#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for exit

void replace(std::string filename, std::string s1, std::string s2) {
    std::ifstream ifs(filename.c_str());
    if (!ifs.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        std::exit(1);
    }

    std::string content;
    // Read file char by char to preserve exact formatting
    char c;
    while (ifs.get(c)) {
        content += c;
    }
    ifs.close();

    if (s1.empty()) {
        // If s1 is empty, we do nothing as we can't replace "nothing"
    } else {
        size_t pos = 0;
        while ((pos = content.find(s1, pos)) != std::string::npos) {
            content.erase(pos, s1.length());
            content.insert(pos, s2);
            pos += s2.length();
        }
    }

    std::string outFilename = filename + ".replace";
    std::ofstream ofs(outFilename.c_str());
    if (!ofs.is_open()) {
        std::cerr << "Error: could not create file " << outFilename << std::endl;
        std::exit(1);
    }
    ofs << content;
    ofs.close();
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./sed_is_for_losers <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    
    replace(argv[1], argv[2], argv[3]);
    return (0);
}
