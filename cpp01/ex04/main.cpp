#include <iostream>
#include <string>
#include <fstream>

int main (int argc, char **argv){
    if (argc != 4){
        std::cerr << "Invalid number of arguments\nTry ./replace <filename> <string 1> <string 2>" << std::endl;
        return 1;
    }
    /* else if(std::string(argv[1]).empty() || std::string(argv[2]).empty() || std::string(argv[3]).empty()){
        std::cerr << "Arguments can't be empty";
        return 1;
    } */

    std::string filename = argv[1];
    std::string str_out = argv[2];
    std::string str_in = argv[3];
    if(filename.empty() || str_out.empty() || str_in.empty()){
        std::cerr << "Arguments can't be empty" << std::endl;
        return 1;
    }

    std::ifstream file;
    file.open(filename.c_str()); //std::ios::in  by default (Open for reading)
    if (!file.is_open()){
        std::cerr << "File error, failed open to read" << std::endl;
        return 1;
    }

    std::string file_replace = filename.append(".replace");
    std::ofstream file2;
    file2.open(file_replace.c_str()); //std::ios::out  by default (Open for writing)
    if (!file2.is_open()){
        std::cerr << "File error, failed open to write" << std::endl;
        return 1;
    }

    std::string txt;
    while (getline(file, txt)){
        size_t i = txt.find(str_out);    // Find the position of the substring, returns npos if it didn't find

        while (i != std::string::npos){  // Check if substring was found
            txt.erase(i, str_out.size());
            txt.insert(i, str_in);
            i = txt.find(str_out, i + str_in.size());
        }
        file2 << txt << std::endl;
    }
    file.close();
    file2.close();

    return 0;
}