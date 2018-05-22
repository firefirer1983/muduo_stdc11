# makefile for muduo/net/tests

.SUFFIXES: .sh .h .c .cc .cpp

AR          = ar
AR_FLAGS    = crs

CXX			= g++
CXXFLAGS	= -std=c++11 -ggdb3 -Wall -Werror
CXX_MACRO	=

BASE_DIR    = ../../..
INC_DIR		= $(BASE_DIR)
SRC_DIR		= ./
OBJ_DIR		= obj
BIN_DIR		= bin

MUDUO_INC   = -I$(INC_DIR)
MUDUO_LIB   = -L$(BASE_DIR)/build/lib/ -lmuduo

GTEST_INC   = -I$(BASE_DIR)/googletest/googletest/include
GTEST_LIB   = -L$(BASE_DIR)/googletest/build/googlemock/gtest/ -lgtest

ZLIB_LIB	= -lz
PTHREAD_LIB = -lpthread

INC			= $(MUDUO_INC) $(GTEST_INC) $(ZLIB_INC)
LIB			= $(MUDUO_LIB) $(GTEST_LIB) $(PTHREAD_LIB) $(ZLIB_LIB)

BIN			= Channel_test \
 EventLoopThread_unittest EventLoop_unittest TcpClient_reg1 TcpClient_reg2 \
 TcpClient_reg3 TimerQueue_unittest InetAddress_unittest Buffer_unittest \
 ZlibStream_unittest ThreadLoop_test

all: debug release # strip

debug release gprof: dir $(addprefix $(BIN_DIR)/,$(BIN))


#@ do not outoupt this command - ingnore its error and continue to make
dir:

	@-mkdir -p $(OBJ_DIR)
	@-mkdir -p $(BIN_DIR)

$(OBJ_DIR)/%.o:$(BASE_DIR)/muduo/base/%.cc
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $(INC) -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $(INC) -c $<

$(BIN_DIR)/Channel_test:$(addprefix $(OBJ_DIR)/, Channel_test.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

$(BIN_DIR)/EchoClient_unittest:$(addprefix $(OBJ_DIR)/, EchoClient_unittest.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

$(BIN_DIR)/EchoServer_unittest:$(addprefix $(OBJ_DIR)/, EchoServer_unittest.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

$(BIN_DIR)/EventLoopThreadPool_unittest:$(addprefix $(OBJ_DIR)/, EventLoopThreadPool_unittest.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

$(BIN_DIR)/EventLoopThread_unittest:$(addprefix $(OBJ_DIR)/, EventLoopThread_unittest.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

$(BIN_DIR)/EventLoop_unittest:$(addprefix $(OBJ_DIR)/, EventLoop_unittest.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

$(BIN_DIR)/TcpClient_reg1:$(addprefix $(OBJ_DIR)/, TcpClient_reg1.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

$(BIN_DIR)/TcpClient_reg2:$(addprefix $(OBJ_DIR)/, TcpClient_reg2.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

$(BIN_DIR)/TcpClient_reg3:$(addprefix $(OBJ_DIR)/, TcpClient_reg3.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

$(BIN_DIR)/TimerQueue_unittest:$(addprefix $(OBJ_DIR)/, TimerQueue_unittest.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

$(BIN_DIR)/InetAddress_unittest:$(addprefix $(OBJ_DIR)/, InetAddress_unittest.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

$(BIN_DIR)/Buffer_unittest:$(addprefix $(OBJ_DIR)/, Buffer_unittest.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

$(BIN_DIR)/ZlibStream_unittest:$(addprefix $(OBJ_DIR)/, ZlibStream_unittest.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)

$(BIN_DIR)/ThreadLoop_test:$(addprefix $(OBJ_DIR)/, ThreadLoop_test.o)
	$(CXX) $(CXXFLAGS) $(CXX_MACRO) -o $@ $^ $(LIB)	
	
strip:
	strip $(addprefix $(BIN_DIR)/,$(BIN))

clean:
	rm -rf  $(OBJ_DIR)
	rm -rf  $(BIN_DIR)

