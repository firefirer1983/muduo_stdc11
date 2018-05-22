
#include <muduo/base/CountDownLatch.h>
#include <muduo/base/CurrentThread.h>
#include <muduo/base/Thread.h>
#include <muduo/base/ThreadPool.h>
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/EventLoopThread.h>
#include <muduo/net/EventLoopThreadPool.h>
#include <sys/types.h>
#include <sys/syscall.h>

#include <functional>
#include <stdio.h>
#include <unistd.h> // usleep

#include <gtest/gtest.h>

using namespace muduo;
using namespace muduo::net;

class GTest : public ::testing::Test {
protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
  }
};

//typedef std::function<void ()> functor;

void msg(const char *s)
{
  printf("tid:%ld => %s\n",::syscall(SYS_gettid), s);
}

EventLoop *pLoop;
MutexLock mutex;
Condition thr_ready(mutex);

void thread_func() {
  
  pLoop = new EventLoop();
  {
    MutexLockGuard lock(mutex);
    thr_ready.notify();
  }
  printf("%s tid:%ld\n", __FUNCTION__, ::syscall(SYS_gettid));
  pLoop->runInLoop(std::bind(msg, "Hello World"));
  while(1) {
  	pLoop->loop();
  }
}

TEST_F(GTest, Thread_Test) {
  Thread th1(std::bind(thread_func), "Thread_Test::th1");
  th1.start();
  {
    MutexLockGuard lock(mutex);
    while (pLoop == NULL)
    {
      thr_ready.wait();
    }
  }

  printf("%s tid:%ld\n", __FUNCTION__, ::syscall(SYS_gettid));
  pLoop->runInLoop(std::bind(msg, "Hello World"));
//  pLoop->quit();
//  th1.join();
}

TEST_F(GTest, EventLoopThread_Test) {
  EventLoopThread elTh1;
  EventLoop *ploop = elTh1.startLoop();
  printf("%s tid:%ld\n", __FUNCTION__, ::syscall(SYS_gettid));
  ploop->runInLoop(std::bind(msg, "Hello World"));
}

TEST_F(GTest, EventLoopThreadPool_Test) {
  EventLoop loop;
  EventLoopThreadPool pool(&loop, "pool");
  ThreadPool tpool("tpool");
  pool.setThreadNum(5); // 3 threads in pool
  pool.start();
  printf("%s tid:%ld\n", __FUNCTION__, ::syscall(SYS_gettid));
//  pool.getNextLoop()->runInLoop(std::bind(msg, "Hello World 1"));
//  pool.getNextLoop()->runInLoop(std::bind(msg, "Hello World 2"));
//  pool.getNextLoop()->runInLoop(std::bind(msg, "Hello World 3"));
//  pool.getNextLoop()->runInLoop(std::bind(msg, "Hello World 4"));
//  pool.getNextLoop()->runInLoop(std::bind(msg, "Hello World 5"));
  tpool.run(std::bind(msg, "Hello World 1"));
  tpool.run(std::bind(msg, "Hello World 2"));
  tpool.run(std::bind(msg, "Hello World 3"));
  tpool.run(std::bind(msg, "Hello World 4"));
  tpool.run(std::bind(msg, "Hello World 5"));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

