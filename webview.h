#ifndef WEBVIEW_H
#define WEBVIEW_H

#include "header.h"

class WebView : public VBox {
public:
	WebView();
	~WebView();
	
	void load_uri(string uri);
	void hide();
	
	WebKitWebView* get_webview() { return view; }
	void set_id(int _id) { id = _id; }
	int get_id() { return id; }
	
protected:
	WebKitWebView* view;
	int id;
};

#endif
