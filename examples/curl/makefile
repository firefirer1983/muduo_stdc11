# makefile for muduo/net/tests

.SUFFIXES: .sh .h .c .cc .cpp

AR          = ar
AR_FLAGS    = crs

CXX			= g++
CXXFLAGS	= -std=c++11 -ggdb3 -Wall -Werror
CXX_MACRO	=

BASE_DIR    = ../../
INC_DIR		= $(BASE_DIR)
SRC_DIR		= ./
OBJ_DIR		= obj
LIB_DIR		= lib
BIN_DIR		= bin
MUDUOLIB    = libmuduo.a

MUDUO_INC   = -I$(INC_DIR)
MUDUO_LIB   = -L$(BASE_DIR)/build/lib/ -lmuduo -lpthread

GTEST_INC   = -I$(BASE_DIR)/muduo/other/
GTEST_LIB   = -L$(BASE_DIR)/muduo/other/gtest/lib/ -lgtest

ZLIB_INC    = -I$(BASE_DIR)/muduo/other/zlib/inc
ZLIB_LIB    = -L$(BASE_DIR)/muduo/other/zlib/lib -lz

CURL_LIB    = -lcurl

INC			= $(MUDUO_INC) $(GTEST_INC) $(ZLIB_INC)
LIB			= $(MUDUO_LIB) $(GTEST_LIB) $(ZLIB_LIB) $(CURL_LIB)

BIN			= download

all: debug release # strip

debug release gprof: dir $(addprefix $(BIN_DIR)/,$(BIN))


#@ do not outoupt this command - ingnore its error and continue to make
dir:
	@-mkdir -p $(INC_DIR)
	@-mkdir -p $(SRC_DIR)
	@-mkdir -p $(OBJ_DIR)
	@-mkdir -p $(LIB_DIR)
	@-mkdir -p $(BIN_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $(INC) -c $<

$(BIN_DIR)/download:$(addprefix $(OBJ_DIR)/, download.o Curl.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

strip:
	strip $(addprefix $(BIN_DIR)/,$(BIN))

clean:
	rm -rf  $(OBJ_DIR)
	rm -rf  $(LIB_DIR)
	rm -rf  $(BIN_DIR)

