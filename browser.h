#ifndef BROWSER_H
#define BROWSER_H

#include "header.h"
#include "webview.h"
#include "model.h"
#include "blacklist.h"
#include <map>

class Browser : public Window {
public:
	Browser(ustring path);
	~Browser();
	
	void on_notebook_switch_page(Gtk::Widget*, guint);
	void on_sidebook_switch_page(Gtk::Widget*, guint);
	
	bool load_website(ustring, WebKitWebView*);
	bool load_search_website(ustring, WebKitWebView*);
	
	bool on_key_press(GdkEventKey*);
	bool on_key_release(GdkEventKey*);
	
	void on_enter_address();
	void set_address(ustring);
	void set_tab_label(Widget&, ustring);
	void set_tab_label(WebKitWebView*, ustring);
	
	void create_new_tab(ustring,bool);
	void clone_current_tab(bool);
	void delete_current_tab();
	
	int get_current_tab();
	void jump_to_last_tab();
	
	void on_back();
	void on_next();
	
	void check_address_bookmark(ustring);
	void on_save_bookmark();
	
	void on_show_history();
	void on_show_bookmark();
	
	void save_history(ustring, ustring);
	void save_bookmark(ustring, ustring);
	
	void load_history(ustring, ustring);
	void load_bookmark(ustring, ustring);
	
	void add_bookmark_tree(ustring, ustring, bool);
	void add_history_tree(ustring, ustring, bool);
	
	void on_history_tree_focus();
	void on_bookmark_tree_focus();
	
	void on_history_tree_selected(const TreeModel::iterator&);
	void on_bookmark_tree_selected(const TreeModel::iterator&);
	
	Notebook& get_notebook() { return notebook; }
	void toogle_side_bar(int);
	
	int run_sql(ustring, int(*func)(void*, int, char**, char**));
	
	void on_bookmark_tree_double_click(const TreeModel::Path&, TreeViewColumn*);
	void on_history_tree_double_click(const TreeModel::Path&, TreeViewColumn*);
	
	void toogle_search_box();
	
	WebKitWebView* create_new_webview();
	void make_fullscreen();
	void make_unfullscreen();
	
	WebKitWebView* get_webview_from_current_tab();
	
	void on_search_text();
	void on_search_next();
	void on_search_previous();
	void on_search_finish();
	
	void on_reload_site();
	
	void add_address_store(ustring, ustring);
	
	WebKitWebContext* get_web_context(bool is_private = false);
	
	void delete_history();
	void delete_bookmark();
	
	bool checkBlackListAddress(std::string);
	
protected:

	ustring exe_path;
	bool is_fullscreen;
	bool is_none_tab;

	VBox main_box;
	HBox menu_box;
	HBox browser_box;
	HBox search_box;
	
	VBox browser_box_side_bar;
	
	TreeView history_tree;
	TreeView bookmark_tree;
	Glib::RefPtr<ListStore> history_store;
	Glib::RefPtr<ListStore> bookmark_store;
	ModelColumns tree_model;
	
	ScrolledWindow bookmark_scroll;
	ScrolledWindow history_scroll;
	
	Entry address_bar;
	Notebook notebook;
	Notebook sidebook;
	
	Button back_button;
	Button next_button;
	Button history_button;
	Button bookmark_button;
	Button save_bookmark_button;
	Button reload_button;
	
	Label close_side_bar;
	bool showing_side_bar;
	
	/* search box */
	Label search_title;
	Entry search_box_text;
	Button search_box_up_button;
	Button search_box_down_button;
	Button search_box_highlight_button;
	Label search_box_matches;
	Button search_box_close_button;
	bool showing_search_box;
	
	vector<WebKitWebView*> webviews;
	WebKitWebsiteDataManager* web_data_manager;
	WebKitWebContext* web_context;
	//~ WebKitWebContext* web_context_second;
	//~ WebKitWebContext* web_context_private;
	int switch_context;
	//~ vector<WebKitWebContext*> list_context;
	
	// history, bookmark
	deque<tuple<ustring, ustring>> list_history;
	//~ deque<tuple<ustring, ustring>> list_bookmark;
	std::map<ustring, ustring> list_bookmark;
	vector<ustring> list_address_selected;
	
	//~ Clipboard clipboard;
	//~ c = Gtk.Clipboard.get(Gdk.SELECTION_PRIMARY)
	//~ print c.wait_for_text()
	
	// entry completetion
	void on_completion_action_activated(int index);
	bool on_completion_match(const Glib::ustring& key, const Gtk::TreeModel::const_iterator& iter);
	
	typedef std::map<int, Glib::ustring> action_map;
	action_map completion_action;
	Glib::RefPtr<TreeStore> address_store;
	
	Glib::RefPtr<EntryCompletion> address_completion;
	AddressModelColumn address_model_column;
	
	BlackList blacklist;
};

// icon: ♡	♥	❤	▲	▼	✖	↻
// PACK_SHRINK, PACK_EXPAND_WIDGET, PACK_EXPAND_PADDING
#endif
