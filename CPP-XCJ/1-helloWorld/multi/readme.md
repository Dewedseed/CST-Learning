# Project Compile

- 多文件全局变量声明与定义
- 多文件函数声明与定义
- 预处理宏

## head file

- 后缀 `.h` `.hpp`
- 声明
  - 全局变量 `extern 类型 变量名`，不建议定义
  - 函数
    - 基本形式 + 默认参数
    - 混合编程 `extern "C" {}`
  - 类
- 不包含
  - 函数定义
  - 全局变量定义
  - `using namespace`
- 声明不占用内存空间

## source file

- 后缀 `.c` `.cpp`
- 定义
  - 函数
  - 全局变量
  - 类

## preprocess

预处理宏 `#pragma once`

- 保证单个 cpp 中只会引用一次
- 支持 msvc gcc clang

类似的可以使用如下结构 (全兼容)

```cpp
#ifndef NAME_H
#define NAME_H

#endif
```

效率上而言预处理宏效率更高，因为编译时不进入文件
