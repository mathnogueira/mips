#include <mips/util/event/event_dispatcher.hpp>

using namespace MIPS;

EventDispatcher::EventDispatcher() {}

EventDispatcher::~EventDispatcher() {}

void EventDispatcher::dispatch(Event &event) {}

Queue<int>* EventDispatcher::getListeners(EventType type) {
	return NULL;
}
