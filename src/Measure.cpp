#include "Measure.h"
#include "..\rmapi\RainmeterAPI.h"

Measure::Measure(void* _rm) :
	rm(_rm),
	skin(RmGetSkin(_rm))
{
}

Measure::~Measure()
{
}
