#pragma once
#include <SDL2/SDL_stdinc.h>
#include "string"

namespace EZ::Timer {

struct Time {
	Uint8 Seconds;
	Uint8 Minutes;
	Uint16 Hours;
};

Time Compile(const Uint16 seconds);

enum TIME { SECOND, MINUTE, HOUR };
std::string ToString(const Time time, const TIME depth);

class Timer {
public:
	Timer(const Uint8 frameRate);

	Uint16 Seconds;

	void Update();
	bool Elased;

protected:
	virtual void _update();
	const Uint8 _frameRate;
	Uint8 _elapsed;
};

class CountDown : public Timer {
public:
	CountDown(const Uint8 frameRate, const Uint16 start);

	bool Finish() const;
	void Reset();

private:
	void _update() override;

	bool _finished;
	const Uint16 _start;
};

};
