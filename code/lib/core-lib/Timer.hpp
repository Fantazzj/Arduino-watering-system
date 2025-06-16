#ifndef TIMER_HPP
#define TIMER_HPP

class Timer {
private:
public:
	virtual ~Timer();
	virtual void wait(unsigned long t) = 0;
	virtual unsigned long millis() = 0;

protected:
};

#endif//TIMER_HPP
