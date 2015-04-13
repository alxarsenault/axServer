CC = clang++
CC_FLAGS = -std=c++11

OBJDIR = build
SRC_DIR = source
INCLUDE_DIR = include

PYTHON_INCLUDE = -I/System/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7 
#-I/System/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7
 #-fno-strict-aliasing -fno-common -dynamic -arch x86_64 -arch i386 -g -Os -pipe -fno-common -fno-strict-aliasing -fwrapv -DENABLE_DTRACE -DMACOSX -DNDEBUG -Wall -Wstrict-prototypes -Wshorten-64-to-32 -DNDEBUG -g -fwrapv -Os -Wall -Wstrict-prototypes -DENABLE_DTRACE

# Genrate with python-config --ldflags
PYTHON_LIB_INCLUDE = -L/System/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/config 
# PYTHON_LIB = -ldl -framework CoreFoundation -lpython2.7

# LIB_SOURCE = connection_manager.cpp connection.cpp request_handler.cpp request_parser.cpp server.cpp axHtml.cpp axWebUtils.cpp axWebApp.cpp axPython.cpp
INCLUDE_SRC = -I $(INCLUDE_DIR) -I/usr/local/include/ $(PYTHON_INCLUDE)
# INCLUDE_LIB = -L/usr/local/lib/ -L. $(PYTHON_LIB_INCLUDE)
# all:
# 	$(CC) $(PYTHON_INCLUDE) $(PYTHON_LIB)  python.cpp -o call

# LIB = -lboost_system -lboost_filesystem -lpthread $(PYTHON_LIB)

red = \033[0;31m
green = \033[0;32m
NC = \033[0m # No Color


# SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# OBJS = $(SRCS:.cpp=.o)

# all: $(OBJS)

# %.o: %.cpp
# 	@echo $<
	#$(CC) $(CC_FLAGS) $(INCLUDE_SRC) $< -c 
	#echo $<


CPP_FILES := $(wildcard source/*.cpp)
OBJ_FILES := $(addprefix build/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := 
# CC_FLAGS := 

all: $(OBJ_FILES)
	ar rcs lib/libaxServer.a $(OBJ_FILES)
	@echo  "${green} ----------------------------------------- ${NC}" 
	@echo  "${green} Creating lib/libaxServer.a ${NC}" 
   # g++ $(LD_FLAGS) -o $@ $^


build/%.o: source/%.cpp
	$(CC) $(CC_FLAGS) $(INCLUDE_SRC) -c -o $@ $<
	@echo  "${green} Build : $< to $@ ${NC}" 


clean: 
	rm -f $(OBJ_FILES)
	rm -f lib/libaxServer.a




