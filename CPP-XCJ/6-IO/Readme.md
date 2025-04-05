# IO

CPP输入输出

## console

- `ostream`
  - `cout` 缓冲 `STDOUT:1`
  - `cerr` 错误 `STDERR:2`
  - 无格式输出
  - 重定向到文件
    - `exe > all.txt`
    - `exe 1>file.out 2>file.err`
    - `exe > all.txt 2>&1`
- `istream`
  - `cin`
  - `getline` 单行输入
  - `get` 单字符输入
  - 格式化输入和错误处理 `rdstate`

## string

- 原型
  - `stringstream`
  - `istringstream`
  - `ostringstream`
- 基础用法
  - 字符串拼接
- 格式化输入
- 按行读取

## file

- `fstream`
  - ASCII
  - Binary
- 打开关闭文件
  - `ifstream f`
  - 文件打开模式
    - `app / binary / in / out / trunc / ate`
    - 对二进制文件不加 `binary` 可能由于 `\r\n` 处理导致文件损坏
    - 默认清空文件内容
  - 文件状态
    - 与 `cin / cout` 相同
  - 缓存用 string 相对复杂
- 文件读写
  - 读写方法
    - 格式化读写 / `read / write`
  - 读写位置
    - `beg / end / cur / seekg / seekp`
- 输入缓冲区与关联数据源同步
  - `sync() / flush`
