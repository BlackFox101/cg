#pragma once
#include <optional>
#include <vector>

struct Letter
{
	char letter;
	std::optional<std::vector<size_t>> position;
};
