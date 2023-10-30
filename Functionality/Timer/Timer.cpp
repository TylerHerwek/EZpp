#include "Timer.hpp"
#include "../SDL/SDL.hpp"
using namespace EZ::Timer;

Time EZ::Timer::Compile(const Uint16 seconds) {
	Time time;
	time.Seconds = seconds % 60;
	time.Minutes = seconds / 60;
	time.Hours = seconds / 3600;
	return time;
};

Timer::Timer(const Uint8 framerate)
	: _frameRate(framerate)
	, _elapsed(0)
	, Seconds(0)
	, Elased(false)
{
	print("framerate is " << (int)_frameRate);
};

void Timer::Update() {
	_elapsed++;
	Elased = false;
	if(_elapsed != _frameRate) return;

	_elapsed = 0;
	Elased = true;
	_update();
};

void Timer::_update() {
	Seconds++;
};

CountDown::CountDown(const Uint8 framerate, const Uint16 start)
	: Timer(framerate)
	, _finished(false)
	, _start(start)
{
	Reset();
};

void CountDown::_update() {
	if(Seconds > 0) {
		_elapsed = 0;
		Seconds--;
	} else {
		_finished = false;
	}
};

bool CountDown::Finish() const {
	return _finished;
};

void CountDown::Reset() {
	Seconds = _start;
};
