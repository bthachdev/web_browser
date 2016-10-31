// trim function
ustring trim(ustring& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    
    if (first == std::string::npos || last == std::string::npos) // not found
		return str;
		
    return str.substr(first, (last-first+1));
}

// limit length of string
ustring limit(string str, int len) {
	
	if (str.size() < len) return str;
	
	int charsread = 0;
	string result;
	char c;
	while(charsread < len) {
		c = str.at(charsread);
		
		result += c;
		charsread++;
	}
	return result;
}
