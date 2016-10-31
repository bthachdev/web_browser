CC=g++ -Wall
CLANG = clang++ -std=c++14 -O3
CCACHE=ccache
GTK=`pkg-config gtk+-3.0 --cflags`
GTKMM=`pkg-config gtkmm-3.0 --cflags --libs`
WEBKITGTK=`pkg-config webkit2gtk-4.0 --cflags --libs`
#~ SQLITE=`pkg-config sqlite3 --cflags --libs` 
SQLITE=-lsqlite3
FILESYS=-lstdc++fs
BOOST=-lboost_filesystem -lboost_system

SRC=main.cpp browser.cpp model.cpp blacklist.cpp
OBJ=$(SRC:.cpp=.o)

EXE=main

# 'game' executable
all: $(EXE)

$(EXE) : $(OBJ)
	$(CCACHE) $(CLANG) $(OBJ) -o $@ $(WEBKITGTK) $(GTKMM) $(GTK) $(SQLITE) $(FILESYS) 
	
.cpp.o:
	$(CCACHE) $(CLANG) -c $< -o $@ $(WEBKITGTK) $(GTKMM) $(GTK) $(SQLITE) $(FILESYS)
	
clean:
	rm *.o $(EXE)
	
