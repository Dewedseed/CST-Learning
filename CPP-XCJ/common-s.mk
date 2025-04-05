# Common compile command for single file

# 定义编译器
CXX = g++

# 定义编译器选项（例如开启调试信息、优化级别等）
CXXFLAGS = -Wall -O2

# 定义目标文件
OBJECTS = $(TARGET).o

# 默认目标
all: $(TARGET)

# 构建目标可执行文件
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 构建目标文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(TARGET) $(OBJECTS)

# 设置默认目标
.PHONY: all clean
