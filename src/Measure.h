#pragma once
class Measure
{
public:
	Measure(void* _rm);
	~Measure();

	void* rm;
	void* skin;
private:
};