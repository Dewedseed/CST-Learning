# Requirement

创建 `StringVector` 类满足以下要求

1. 用智能指针存放数据
   - 存放数据 `unique_ptr<string[]> strs_;`
   - 定义 `strs_ = make_unique<stirng>();`
   - 重载访问方式 `strs_[10]`
2. 设计接口
   - 构造创建控件 `StringVector(int size = 100)`
   - 插入数据/右值引用 `void Push(const string& s)`
   - 数据访问 `const string &operator[](int index)`
   - 获取数组大小 `int size()`
   - 获取容量大小 `int Capacity()`
