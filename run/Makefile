CC = g++
# C++ 컴파일러 옵션
CFLAGS = -g -Wall
# 링커 옵션
LDFLAGS =
# 소스 파일 디렉토리
SRC_DIR = .
# 오브젝트 파일 디렉토리
OBJ_DIR = .
# 생성하고자 하는 실행 파일 이름
TARGET = 9093
# Make 할 소스 파일들
# wildcard 로 SRC_DIR 에서 *.c 로 된 파일들 목록을 뽑아낸 뒤에
# notdir 로 파일 이름만 뽑아낸다.
# (e.g SRCS 는 foo.cc bar.cc main.cc 가 된다.)
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))

OBJS = $(SRCS:.c=.o)

# OBJS 안의 object 파일들 이름 앞에 $(OBJ_DIR)/ 을 붙인다.
OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))
DEPS = $(OBJECTS:.o=.d)

all: 9093

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@ -MD $(LDFLAGS)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

.PHONY: clean all
clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)

-include $(DEPS)