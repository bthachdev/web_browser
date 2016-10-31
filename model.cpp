#include "model.h"

ModelColumns::ModelColumns() {
	add(column_title);
	add(column_address);
}

AddressModelColumn::AddressModelColumn() {
	add(column_name);
	add(column_address);
}
