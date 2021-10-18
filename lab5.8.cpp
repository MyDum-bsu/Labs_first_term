#include <fstream>
#include <string>

void ReInitInput(std::ifstream &fin, const std::string &path) {
    fin.close();
    fin.open(path);
}

void RoundSquareBrackets(std::ifstream &fin, std::ofstream &out, char begin, char end) {
    std::string str;
    while (getline(fin, str)) {
        int st_pos = str.find(begin, 0);
        int end_pos = str.rfind(end, str.length());
        if (st_pos + end_pos > 1 && st_pos + 1 < end_pos) {
            out << str << std::endl;
        }
    }
}

int main() {
    std::ifstream fin("File.txt");
    if (!fin.is_open())
        throw std::runtime_error("File couldn't be open");
    std::ofstream outR("RoundBrackets.txt");
    std::ofstream outSq("SquareBrackets.txt");
    RoundSquareBrackets(fin, outR, '(', ')');
    ReInitInput(fin, "File.txt");
    RoundSquareBrackets(fin, outSq, '[', ']');
    outR.close();
    outSq.close();
    fin.close();
    return 0;
}