#ifndef ARGHANDLER_HPP
#define ARGHANDLER_HPP

#include <iostream>
#include <string>

int ArgHandler(int argc, char* argv[]) {

  if(argc < 1) {
    return -1;
  }

  else if(argc > 4) {
    throw std::runtime_error("Too many arguments!");
  }

  else if(std::string(argv[1]) == "--help") {
    std::cout
        << "---Help menu---\n"
        << "\n"
        << "--help  Shows this menu\n"
        << "-C <iterations> <threads>\n"
        << "iterations  The amount of times the program is going to be ran.\n"
        << "-1 for the maximum integer\n"
        << "0 for infinite\n"
        << "threads  The amount of threads the program will create.\n"
        << "-1 for the maximum integer\n\n";
    return 0;
  }

  else if(std::string(argv[1]) == "-C") {
    return 1;
  }

  else {
    throw std::runtime_error("Invalid arguments");
  }

  return 0;

}

#endif