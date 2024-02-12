#include <fstream>
#include <iostream>
#include <string>

std::string replace(const std::string &source, const std::string &from,
                    const std::string &to) {
  std::string newString;
  newString.reserve(source.length());
  size_t lastPos = 0;
  size_t findPos;
  while ((findPos = source.find(from, lastPos)) != std::string::npos) {
    newString.append(source, lastPos, findPos - lastPos);
    newString += to;
    lastPos = findPos + from.length();
  }
  newString += source.substr(lastPos);
  return newString;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
    return 1;
  }
  std::ifstream inputFile(argv[1]);
  if (!inputFile) {
    std::cerr << "Failed to open " << argv[1] << std::endl;
    return 1;
  }
  std::string content((std::istreambuf_iterator<char>(inputFile)),
                      std::istreambuf_iterator<char>());
  std::ofstream outputFile((std::string(argv[1]) + ".replace").c_str());
  if (!outputFile) {
    std::cerr << "Failed to create output file." << std::endl;
    return 1;
  }
  outputFile << replace(content, argv[2], argv[3]);
  return 0;
}
