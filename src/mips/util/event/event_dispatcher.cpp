#include <mips/util/event/event_dispatcher.hpp>

using namespace MIPS;

EventDispatcher::EventDispatcher() {}

EventDispatcher::~EventDispatcher() {}

void EventDispatcher::dispatch(Event &event) {
	Queue<EventListener*> *queue = getListeners(event.event_type);
	if (queue != NULL) {
		for (unsigned int i = 0; i < queue->size(); ++i) {
			queue->get(i)->notify(event);
		}
	}
}

void EventDispatcher::addEventListener(EventListener *listener, EventType event) {
	// Verifica se existe esse tipo de evento
	Queue<EventListener*> *queue = getListeners(event);
	if (queue == NULL) {
		// Não existe esse tipo de evento ainda, então cria.
		queue = new Queue<EventListener*>;
		ListenerMap map = { event, queue };
		listeners.push_back(map);
	}
	// Adiciona o ouvinte à fila
	queue->push(listener);
}

Queue<EventListener*>* EventDispatcher::getListeners(EventType event) {
	for (unsigned int i = 0; i < listeners.size(); ++i) {
		ListenerMap &map = listeners.at(i);
		if (map.type == event)
			return map.listeners;
	}
	return NULL;
}
