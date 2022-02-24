#pragma once
#include <optional>

struct Letter
{
	char letter;
	std::optional<size_t> position;
};
