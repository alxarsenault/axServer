CC = clang++
CC_FLAGS = -std=c++11

PYTHON_INCLUDE = -I/System/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7 
#-I/System/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7
 #-fno-strict-aliasing -fno-common -dynamic -arch x86_64 -arch i386 -g -Os -pipe -fno-common -fno-strict-aliasing -fwrapv -DENABLE_DTRACE -DMACOSX -DNDEBUG -Wall -Wstrict-prototypes -Wshorten-64-to-32 -DNDEBUG -g -fwrapv -Os -Wall -Wstrict-prototypes -DENABLE_DTRACE

# Genrate with python-config --ldflags
PYTHON_LIB_INCLUDE = -L/System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/config 
PYTHON_LIB = -ldl -framework CoreFoundation -lpython2.7

LIB_SOURCE = connection_manager.cpp connection.cpp request_handler.cpp request_parser.cpp server.cpp axHtml.cpp axWebUtils.cpp axWebApp.cpp axPython.cpp
INCLUDE_SRC = -I/usr/local/include/ $(PYTHON_INCLUDE) -I../include/
INCLUDE_LIB = -L/usr/local/lib/ -L../lib/ $(PYTHON_LIB_INCLUDE)
# all:
# 	$(CC) $(PYTHON_INCLUDE) $(PYTHON_LIB)  python.cpp -o call

LIB = -lboost_system -lboost_filesystem -lpthread $(PYTHON_LIB)

# lib:
# 	$(CC) $(CC_FLAGS) $(INCLUDE_SRC) $(INCLUDE_LIB) $(LIB) -c $(LIB_SOURCE)
# 	ar rcs libaxServer.a $(LIB_SOURCE:.cpp=.o)

all: 
	$(CC) $(CC_FLAGS) $(INCLUDE_SRC) $(INCLUDE_LIB) $(LIB) -laxServer main.cpp -o main

lib: 
	make -C ../
	$(CC) $(CC_FLAGS) $(INCLUDE_SRC) $(INCLUDE_LIB) $(LIB) -laxServer main.cpp -o main
	./main