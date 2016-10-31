#include "tab.h"

void Tab::set_label(string name) {
	label.set_label(name);
}

Tab::~Tab() {
	
}

Tab::Tab() {	
	set_border_width(2);
	
	label.set_text("New Tab");
	x.set_label("x");
	//~ x.set_text("x");
	
	pack_start(label, PACK_SHRINK, 4);
	pack_start(x, PACK_SHRINK, 4);
}
