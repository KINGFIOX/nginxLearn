# chap6 - 业务逻辑

## chap6 - 01 - 多线程

一个进程跑起来之后，就自动启动了一个“主线程”

涉及到业务逻辑层面，这就要用到多线程处理，所谓的业务逻辑：充值，抽卡，战斗！

充值：需要本服务器 和 专门的充值服务器通讯，一般需要数秒到数十秒的通讯事件。
此时我们必须采用多线程处理方式; 一个线程因为充值被卡住，还有其他线程可以提供给其他玩家及时的服务。

所以，我们服务器端在处理【用户需求】的时候，一般都会启动几十甚至上百个线程来处理，
以保证用户的需求能够得到及时处理。

主线程：从消息队列中用 inMsgRecvQueue()仍完整包，那么一堆线程就要从这个消息队列中取走这个包，所以必须要互斥。

1. posix: 可移植操作系统接口（portable operating system interface of unix）
2. posix 线程：是 posix 的线程标准：他定义了创建和操纵线程的一套 api(application programming interface)
3.