#include <fstream>
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
  std::string line;
  std::ifstream csvFile{"20200317.csv"}; // an object of input filestream class
  if (csvFile.is_open()) {
    std::cout << "file open. " << std::endl;

    // getline returns a bool
    while (std::getline(csvFile,
                        line)) // from csvfile into a line (local variable)
    {
      tokens = tokenise(line, ',');
      if (tokens.size() != 5) {
        std::cout << "wrong input. " << std::endl;
      } else {
        try {
          double price = std::stod(tokens[3]);
          double amount = std::stod(tokens[4]);
          std::cout << "price: " << price << "amount: " << amount << std::endl;
        } catch (const std::exception &e) {
          std::cout << "couldn't convert to double. " << std::endl;
          continue;
        }
        // for (std::string &token : tokens) {
        //   std::cout << "the token is: " << token << std::endl;
        // }
      }
    } // end of while
    csvFile.close();
  } else {
    std::cout << "unable to open file. " << std::endl;
  }
  // tokens=tokenise(csvFile, ',');
  // for(int i=0; i<tokens.size();++i)
  // {
  //     std::cout<<"the token is: "<<tokens.at(i)<<std::endl;
  // }
  return 0;
}