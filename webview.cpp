#include "webview.h"

WebView::~WebView() {
	//~ delete view;
}

void WebView::hide() {
	cout << "hide";
	VBox::hide();
}

void WebView::load_uri(string uri) {
	string final_uri;
	if (uri.find("http") > 0)
		final_uri = "http://";
	final_uri.append(uri);
		
	webkit_web_view_load_uri(view, final_uri.c_str());
}

WebView::WebView() {
	view = WEBKIT_WEB_VIEW(webkit_web_view_new());
	Widget* widget = manage(Glib::wrap(GTK_WIDGET(view)));
	pack_start(*widget, PACK_EXPAND_WIDGET);
}


