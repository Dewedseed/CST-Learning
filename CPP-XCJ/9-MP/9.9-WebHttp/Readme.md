# Requriement

Web 服务器-Http 协议处理模块

- 并发消息处理模块 MsgServer
  - 多线程处理业务
  - 一个对象对应一个线程
- 消息注册
  - MAP: 消息类型, 函数指针
- 消息接收
  - 接收函数 + 消息缓存 (queue)
- 消息转发线程
  - 线程函数 启动/停止/等待
  - 读取来源
  - 转发函数
  - 转发函数存储
- Http 派生类 (具体业务)
  - 注册函数
  - 测试使用
