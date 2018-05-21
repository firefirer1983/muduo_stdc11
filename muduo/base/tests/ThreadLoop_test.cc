#include <muduo/base/ThreadPool.h>
#include <muduo/base/CountDownLatch.h>
#include <muduo/base/CurrentThread.h>
#include <muduo/base/Thread.h>
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <sys/types.h>
#include <sys/syscall.h>

#include <functional>
#include <stdio.h>
#include <unistd.h> // usleep
using muduo::net::EventLoop;
void print()
{
  printf("tid=%d\n", muduo::CurrentThread::tid());
}

int main()
{
	EventLoop *pLoop = new EventLoop();
	muduo::Thread::ThreadFunc func = std::bind(&EventLoop::loop, pLoop);
	muduo::Thread th1(func, "th1");
	printf("main thead id:%ld\n",::syscall(SYS_gettid));
  pLoop->runInLoop(std::bind(&print));
	th1.join();
}
