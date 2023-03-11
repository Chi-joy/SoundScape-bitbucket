
/* -------------------
SHUBH FAGERIA
FEBRUARY 7, 2023
CS3307
Assignment 1
--------------------*/
#include <fstream>
#include <iostream>

#include "request.h"
int main(int argc, char * argv[])
{
  // std::string authCode = argv[1];
  //
  int i = 0;


  std::string authCode;
  std::string fileLine;
    // Create and open a text file
   std::ifstream MyReadFile("../loginAuth/authCode.txt");
  while (getline (MyReadFile, fileLine)) {
  // Output the text from the file
    i++;
    std::cout << i;
    std::cout << " is this working??????????????";
    if (fileLine.length() > 1) {
      authCode = fileLine;
      std::cout << authCode;
    }

    
  }

  initRequest(authCode);

  // Close the file
  MyReadFile.close();
  return 0;
}


