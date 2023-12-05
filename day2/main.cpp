#include <fstream>
#include <iostream>
#include <string>
// #include <tuple>
using namespace std;

int partOne(string fileName);
int partOneNotWorking(string fileName);
int partTwo(string fileName);
int main() {
  //   const int test = partOne("test.txt");
  //   cout << test << endl;
  //   const int res = partOne("input.txt");
  //   cout << res << endl;
  const int test2 = partTwo("test.txt");
  cout << test2 << endl;
  const int res2 = partTwo("input.txt");
  cout << res2 << endl;
}

int partOneNotWorking(string fileName) {
  //  only 12 red cubes, 13 green cubes, and 14 blue cubes

  ifstream fin;
  string line;
  fin.open(fileName);

  // result declaration
  int lineIDSum = 0;

  while (getline(fin, line)) {
    // cubes in the line counter.
    int redCubes = 0, greenCubes = 0, blueCubes = 0;
    // bool that checks if the line id has been found
    bool foundLineID = false;
    bool tooManyCubes = false;
    int lineID = 0;

    for (size_t i = 0; i < line.length(); i++) {
      // taking the line ID
      if (!foundLineID && isdigit(line[i])) {
        // flagging that we are past the line id.
        foundLineID = true;
        string stringLineID = "";

        while (line[i] != ':') {

          // appending char to stringLineID.
          stringLineID += line[i];
          i++;
        }
        // skipping to the cell after ":".
        i++;
        // converting stringLineID to int.
        lineID = stoi(stringLineID);
      }

      if (foundLineID && isdigit(line[i])) {

        // cube to check.
        string cubeNumStr = "";
        int cubeNum = 0;
        // tuple<int, string> currentCube;
        while (isdigit(line[i])) {
          cubeNumStr += line[i];
          i++;
        }
        i++; // getting to the color.

        cubeNum = stoi(cubeNumStr);
        // load cube numbers based on the color.

        switch (line[i]) {
        case 'r': {
          redCubes += cubeNum;
          // 13 cubes max
          if (redCubes > 13) {
            tooManyCubes = true;
          }
          break;
        }
        case 'g': {
          greenCubes += cubeNum;
          // 14 cubes max
          if (greenCubes > 14) {
            tooManyCubes = true;
          }
          break;
        }
        case 'b': {
          blueCubes += cubeNum;
          // 15 cubes max
          if (blueCubes > 15) {
            tooManyCubes = true;
          }
          break;
        }
        default:
          break;
        }
      }
    }
    if (tooManyCubes == false) {
      lineIDSum += lineID;
    }
  }
  return lineIDSum;
}

int partOne(string fileName) {
  //  only 12 red cubes, 13 green cubes, and 14 blue cubes

  ifstream fin;
  string line;
  fin.open(fileName);

  // result declaration
  int lineIDSum = 0;

  while (getline(fin, line)) {
    // bool that checks if the line id has been found
    bool foundLineID = false;
    bool tooManyCubes = false;
    int lineID = 0;

    for (size_t i = 0; i < line.length(); i++) {
      // taking the line ID
      if (!foundLineID && isdigit(line[i])) {
        // flagging that we are past the line id.
        foundLineID = true;
        string stringLineID = "";

        while (line[i] != ':') {

          // appending char to stringLineID.
          stringLineID += line[i];
          i++;
        }
        // skipping to the cell after ":".
        i++;
        // converting stringLineID to int.
        lineID = stoi(stringLineID);
      }

      if (foundLineID && isdigit(line[i])) {

        // cube to check.
        string cubeNumStr = "";
        int cubeNum = 0;
        // tuple<int, string> currentCube;
        while (isdigit(line[i])) {
          cubeNumStr += line[i];
          i++;
        }
        i++; // getting to the color.

        cubeNum = stoi(cubeNumStr);
        // load cube numbers based on the color.

        switch (line[i]) {
        case 'r': {
          // 13 cubes max
          if (cubeNum > 12) {
            tooManyCubes = true;
          }
          break;
        }
        case 'g': {
          // 14 cubes max
          if (cubeNum > 13) {
            tooManyCubes = true;
          }
          break;
        }
        case 'b': {
          // 15 cubes max
          if (cubeNum > 14) {
            tooManyCubes = true;
          }
          break;
        }
        default:
          break;
        }
      }
    }
    if (tooManyCubes == false) {
      // cout << "line: " << lineID << endl;
      lineIDSum += lineID;
    }
  }
  return lineIDSum;
}

int partTwo(string fileName) {
  //  only 12 red cubes, 13 green cubes, and 14 blue cubes

  ifstream fin;
  string line;
  fin.open(fileName);

  // result declaration
  int sumOfTheProducts = 0;

  while (getline(fin, line)) {
    // bool that checks if the line id has been found
    bool foundLineID = false;
    bool tooManyCubes = false;
    int lineID = 0;

    int maxRed = 0, maxGreen = 0, maxBlue = 0;
    for (size_t i = 0; i < line.length(); i++) {

      // taking the line ID
      if (!foundLineID && isdigit(line[i])) {
        // flagging that we are past the line id.
        foundLineID = true;
        string stringLineID = "";

        while (line[i] != ':') {

          // appending char to stringLineID.
          stringLineID += line[i];
          i++;
        }
        // skipping to the cell after ":".
        i++;
        // converting stringLineID to int.
        lineID = stoi(stringLineID);
      }

      if (foundLineID && isdigit(line[i])) {

        // cube to check.
        string cubeNumStr = "";
        int cubeNum = 0;
        // tuple<int, string> currentCube;
        while (isdigit(line[i])) {
          cubeNumStr += line[i];
          i++;
        }
        i++; // getting to the color.

        cubeNum = stoi(cubeNumStr);
        // load cube numbers based on the color.

        switch (line[i]) {
        case 'r': {
          if (maxRed < cubeNum) {
            maxRed = cubeNum;
          }
          break;
        }
        case 'g': {
          if (maxGreen < cubeNum) {
            maxGreen = cubeNum;
          }
          break;
        }
        case 'b': {
          if (maxBlue < cubeNum) {
            maxBlue = cubeNum;
          }
          break;
        }
        default:
          break;
        }
      }
    }
    // product of the cubes in the bag
    int product = maxRed * maxGreen * maxBlue;
    sumOfTheProducts += product;
  }
  return sumOfTheProducts;
}