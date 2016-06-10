#include <mips/util/event/event.hpp>
#include <cstdlib>

using namespace MIPS;

Event::Event(EventType type, void *data, bool autodestroy) :
	event_type(type),
	data_ptr(data),
	autodestroy_(autodestroy) {}

Event::~Event() {
	if (autodestroy_)
		free(data_ptr);
}

bool Event::shouldDestroy() {
	return autodestroy_;
}
