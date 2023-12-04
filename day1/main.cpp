#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int partOne(string fileName);
int partTwo(string fileName);
int main() {
  const int test = partOne("test.txt");
  cout << test << endl;

  const int res = partOne("input.txt");
  cout << res << endl;

  const int test2 = partTwo("test2.txt");
  cout << test2 << endl;

  const int res2 = partTwo("input.txt");
  cout << res2 << endl;
}

int partOne(string fileName) {

  ifstream fin;
  string line;
  fin.open(fileName);
  int total = 0;

  while (getline(fin, line)) {

    string doubleDigitStr = "";
    string firstDigit;
    string lastDigit;

    // iterate through every char of the line.
    for (size_t i = 0; i < line.length(); i++) {
      if (isdigit(line[i]) && doubleDigitStr.length() == 0) {
        // if that's the first digit save it.
        firstDigit = line[i];
        doubleDigitStr = doubleDigitStr.append(firstDigit);

      } else if (isdigit(line[i])) {
        // if there is already a first digit, save the current last digit.
        lastDigit = line[i];
      }
    }

    if (lastDigit.length() == 0) {
      // if there is just one digit, append it again.
      doubleDigitStr = doubleDigitStr.append(firstDigit);
    } else {
      // if there is a last digit saved, append it next to the first digit.
      doubleDigitStr = doubleDigitStr.append(lastDigit);
    }
    // summation of the new line value.
    total += stoi(doubleDigitStr);
  }
  return total;
}

int partTwo(string fileName) {

  // map of number literals
  std::map<std::string, std::string> Numbers;

  Numbers["one"] = "1";
  Numbers["two"] = "2";
  Numbers["three"] = "3";
  Numbers["four"] = "4";
  Numbers["five"] = "5";
  Numbers["six"] = "6";
  Numbers["seven"] = "7";
  Numbers["eight"] = "8";
  Numbers["nine"] = "9";

  ifstream fin;
  string line;
  fin.open(fileName);
  int total = 0;

  while (getline(fin, line)) {

    string doubleDigitStr = "";
    string firstDigit;
    string lastDigit;

    string literalDigit = "-1";

    // iterate through every char of the line.
    for (size_t i = 0; i < line.length(); i++) {

      if (isdigit(line[i]) && doubleDigitStr.length() == 0) {
        // if that's the first digit save it.
        firstDigit = line[i];
        doubleDigitStr = doubleDigitStr.append(firstDigit);

      } else if (isdigit(line[i])) {
        // if there is already a first digit, save the current last digit.
        lastDigit = line[i];
      }

      // PART 2 CHECKS (literal digits)

      // if there are enough possible characters that it could be a literal
      // number, create a substring of it.
      if (line.length() - i > 2) {

        // declaring 3 booleans that check if one of the 3 substrings are
        // literal numbers (contained in the Number map)
        bool isthreeWordNum, isfourWordNum, isfiveWordNum;

        // take all the possible substrings (numbers can be length 3, 4 or 5)
        string threeWord = line.substr(i, 3);
        auto it3 = Numbers.find(threeWord);
        isthreeWordNum = (it3 != Numbers.end());
        // cout << "string 3 part: " << threeWord << endl;
        string fourWord = line.substr(i, 4);
        auto it4 = Numbers.find(fourWord);
        isfourWordNum = (it4 != Numbers.end());
        // cout << "string 4 part: " << fourWord << endl;
        string fiveWord = line.substr(i, 5);
        auto it5 = Numbers.find(fiveWord);
        isfiveWordNum = (it5 != Numbers.end());
        // cout << "string 5 part: " << fiveWord << endl;

        // resetting literalDigit.
        literalDigit = "-1";

        // checking if a literal number has been found, saving it's int value
        // inside literalDigit.
        if (isthreeWordNum) {
          literalDigit = it3->second;
        } else if (isfourWordNum) {
          literalDigit = it4->second;
        } else if (isfiveWordNum) {
          literalDigit = it5->second;
        }
        // cout << "literal digit: " << literalDigit << endl;

        // if there is a literal digit and it's the first digit overall, save
        // it inside firstDigit.
        if (literalDigit != "-1" && doubleDigitStr.length() == 0) {

          firstDigit = literalDigit;
          // also appending it to doubleDigitStr.
          doubleDigitStr = doubleDigitStr.append(firstDigit);
        } else if (literalDigit != "-1") {

          // if there was already a digit inside doubldDigitStr, save the
          // literal digit inside lastDigit.
          lastDigit = literalDigit;
        }
      }
    }
    if (lastDigit.length() == 0) {
      // if there is just one digit, append it again.
      doubleDigitStr = doubleDigitStr.append(firstDigit);
    } else {
      // if there is a last digit saved, append it next to the first digit.
      doubleDigitStr = doubleDigitStr.append(lastDigit);
    }
    // summation of the new line value.
    total += stoi(doubleDigitStr);
  }
  return total;
}