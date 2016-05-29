#include <mips/util/filter/space_filter.hpp>
#include <algorithm>

using namespace MIPS;

std::string SpaceFilter::filter(std::string& input) {
	std::string output;
	output = this->removeTabs(input);
	output = this->trim(output);
	return output;
}

std::string SpaceFilter::removeTabs(std::string& input) {
	if (input.size() > 0)
		input.erase(std::remove(input.begin(), input.end(), '\t'), input.end());
	return input;
}

std::string SpaceFilter::trim(std::string& input) {
	if (input.size() > 0) {
		size_t first = input.find_first_not_of(' ');
	    size_t last = input.find_last_not_of(' ');
	    input = input.substr(first, (last-first+1));
	}
	return input;
}
