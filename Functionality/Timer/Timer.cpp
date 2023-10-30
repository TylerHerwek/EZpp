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

using std::string;
static const string add0(const Uint16 num) {
	string n;
	if(num < 10) {
		n.push_back('0');
		n.push_back(num + '0');
	} else {
		n = std::to_string(num);
	}
	return n;
}; 

string EZ::Timer::ToString(const Time time, const TIME depth) {
	int seconds = -1;
	int minutes = -1;
	int hours = -1;

	switch (depth) {
	case HOUR:
		hours = time.Hours;
		minutes = time.Minutes;
		seconds = time.Seconds;
		break;
	case MINUTE:
		minutes = time.Minutes + (time.Hours * 60);
		seconds = time.Seconds;
		break;
	case SECOND:
		seconds = time.Seconds + (time.Minutes * 60) + (time.Hours * 3600);
		break;
	}

	string end = {};
	if(hours != -1) end += add0(hours) + ":";
	if(minutes != -1) end += add0(minutes) + ":";
	if(seconds != -1) end += add0(seconds);
	return end;
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
