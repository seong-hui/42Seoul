#include "Replacer.hpp"

Replacer::Replacer(const std::string& filename, const std::string& s1, const std::string& s2) 
: filename(filename), s1(s1), s2(s2){}

Replacer::~Replacer(void){}

std::string Replacer::replaceString(const std::string& line) const{
    std::string modifiedLine = line;
    std::string::size_type pos = 0;
    while(1){
        pos = modifiedLine.find(s1, pos);
        if(pos == std::string::npos) break;
        modifiedLine.erase(pos, s1.length());
        modifiedLine.insert(pos, s2);
        pos += s2.length();
    }
    return modifiedLine;
}

int Replacer::processFile(){
    std::ifstream inputFile(filename);
    if(!inputFile){
        std::cerr << "[ERROR] Input file Error" << std::endl;
        return 1;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename);
    if(!outputFile){
        std::cerr << "[ERROR] Output file Error" << std::endl;
        return 1;
    }

    std::string line;
    while(std::getline(inputFile, line)){
        std::string replaceLine = replaceString(line);
        outputFile << replaceLine << '\n';
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
