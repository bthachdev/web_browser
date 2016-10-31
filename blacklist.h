#ifndef BLACK_LIST_H
#define BLACK_LIST_H
#include <string>
#include <vector>

class BlackList {
public:
	BlackList(std::string path);
	void loadList();
	bool isInBlackList(std::string address);
	
private:
	std::string exe_path;
	std::vector<std::string> black_list;
};

#endif
