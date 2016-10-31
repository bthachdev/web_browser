#ifndef MODEL_H
#define MODEL_H
#include "header.h"

class ModelColumns : public TreeModelColumnRecord {
public:
	ModelColumns();
	
	TreeModelColumn<Glib::ustring> column_title;
	TreeModelColumn<Glib::ustring> column_address;
};

class AddressModelColumn : public TreeModelColumnRecord {
public:
	AddressModelColumn();
	
	TreeModelColumn<Glib::ustring> column_name;
	TreeModelColumn<Glib::ustring> column_address;
};

#endif
