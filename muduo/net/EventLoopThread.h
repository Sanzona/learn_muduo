#ifndef MUDUO_NET_EVENTLOOPTHREAD
#define MUDUO_NET_EVENTLOOPTHREAD
#include "muduo/base/Condition.h"
#include "muduo/base/Mutex.h"
#include "muduo/base/Thread.h"

namespace muduo
{
namespace net
{
class EventLoop;
class EventLoopThread : noncopyable
{
public:
	typedef std::function<void(EventLoop*)> ThreadInitCallback;
	EventLoopThread(const ThreadInitCallback& cb = ThreadInitCallback(), const string&name = string());
	~EventLoopThread();
	EventLoop* startLoop();

private:
	void threadFunc();
	EventLoop* loop_;
	bool exiting_;
	Thread thread_;
	MutexLock mutex_;
	Condition cond_;
	ThreadInitCallback callback_;
}; // class EventLoopThread

} // namespace net

} // namespace muduo

#endif // MUDUO_NET_EVENTLOOPTHREAD
