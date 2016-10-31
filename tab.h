#ifndef TAB_H
#define TAB_H

#include "header.h"

class Tab : public HBox {
public:
	Tab();
	~Tab();
	
	void set_label(string);
	void set_id(int _id) { id = _id; }
	int get_id() { return id; }
	
protected:
	Label label;
	Button x;
	//~ Label x;
	int id;
};

#endif
