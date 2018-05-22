AR          = ar
AR_FLAGS    = crs

CXX			= g++
CXXFLAGS	= -std=c++11 -ggdb3 -Wall -Werror
CXX_MACRO	=
RANLIB		= ranlib

BASE_DIR    = .

LIB_DIR		= $(BASE_DIR)/build/lib

TARGET	    = libmuduo.a

INC_DIR		= .
CXX_INC_FLAGS	= $(foreach path, $(INC_DIR), -I$(path))

SRC_DIR		= muduo/net
SRC_DIR		+= muduo/base
SRC_DIR		+= muduo/net/poller

SRC_CC		= $(foreach path, $(SRC_DIR), $(wildcard $(path)/*.cc))
SRC_H		= $(foreach path, $(SRC_DIR), $(wildcard $(path)/*.h))

OBJS		= $(patsubst %.cc,%.o,$(SRC_CC))
all: debug release $(TARGET)

debug release : dir $(OBJS) 

%.o:%.cc $(SRC_H)
	$(CXX) -c -o $@ $(filter-out %.h,$^) $(CXXFLAGS) $(CXX_INC_FLAGS)

$(TARGET):$(OBJS)
	$(AR) $(AR_FLAGS) $(LIB_DIR)/$@ $^
	$(RANLIB) $(LIB_DIR)/$@
	
dir:
	@-mkdir -p $(LIB_DIR)

clean:
	rm $(OBJS)
	rm -rf $(LIB_DIR)


