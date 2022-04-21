#pragma once

class IFunction
{
public:
	virtual float GetYByX(float x) const = 0;
	virtual ~IFunction() = default;
};
