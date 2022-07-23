#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> tokenise(std::string csvLine, char separator) {
  std::vector<std::string> tokens;
  signed int start, end;
  start = csvLine.find_first_not_of(separator, 0); // first position after 0
  std::string token;
  do {
    end = csvLine.find_first_of(separator, start); // first separator after
                                                   // start
    if (start == csvLine.length() || start == end)
      break;

    if (end >= 0) {
      token = csvLine.substr(start, end - start);
    }

    else
      token = csvLine.substr(start, csvLine.length() - start);

    tokens.push_back(token);
    start = end + 1;
  }

  while (end != std::string::npos);

  return tokens;
}

int main(void) {
  std::vector<std::string> tokens;
  std::string csvFile = ",abcd,defg,ijkl,";
  tokens = tokenise(csvFile, ',');
  for (int i = 0; i < tokens.size(); ++i) {
    std::cout << "the token is: " << tokens.at(i) << std::endl;
  }
  return 0;
}