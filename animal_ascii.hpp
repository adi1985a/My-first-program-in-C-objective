#pragma once
#include <iostream>
#include <string>
#include <map>

inline void displayAsciiArt(const std::string& type) {
    static const std::map<std::string, std::string> asciiArt = {
        {"welcome", R"(
    /\___/\
   (  o o  )
   (  =^=  ) WELCOME TO THE ANIMAL KINGDOM!
    (---)  
        )"},
        {"cat", R"(
     /\___/\
    (  o o  )
    (  =^=  )
     (---)  
        )"},
        {"coyote", R"(
     /\___/\
    (  o o  )
   --\   /--
     |__|
        )"},
        {"cow", R"(
       /(__)\
      (o o  )
     /------\
    / |    | \
   *  ||--||  *
        )"}
    };

    auto it = asciiArt.find(type);
    if (it != asciiArt.end()) {
        std::cout << it->second << std::endl;
    }
}
