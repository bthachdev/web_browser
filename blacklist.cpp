#include "blacklist.h"
#include <fstream>
#include <iostream>

BlackList::BlackList(std::string path) 
	: exe_path(path)
{
	loadList();
}
	
void BlackList::loadList() {
	std::ifstream file(exe_path + "/blacklist");	
	std::string line;
	
	if (file.is_open()) {
		while(getline(file, line)) {
			black_list.push_back(line);
			std::cout << line << "\n";
		}
		file.close();
	}
}

bool BlackList::isInBlackList(std::string address) {
	for(auto& blackUri : black_list) {
		if(address.find(blackUri) != std::string::npos) {
			return true;
		}
	}
	return false;
}
