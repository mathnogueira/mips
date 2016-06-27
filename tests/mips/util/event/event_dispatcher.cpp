#include <mips/util/event/event_dispatcher.hpp>
#include <mips/util/event/event_listener.hpp>
#include <mips/util/event/event.hpp>
#include <gtest/gtest.h>

using namespace MIPS;

// Objeto despachante falso
class MockDispatcher : public EventDispatcher {

public:

	void doSomething() {
		Event event(REGISTER_UPDATE, NULL, false);
		this->dispatch(event);
	}

	void doOtherthing() {
		Event event(TEST, NULL, false);
		this->dispatch(event);
	}
};

// Ouvinte falso
class MockListener : public EventListener {

public:

	// inteiro que será modificado.
	int integer;

	MockListener() {
		integer = 0;
	}

	void notify(Event &event) {
		if (event.event_type == REGISTER_UPDATE)
			integer += 1;
		else
			integer -= 1;
	}

};

TEST(EventDispatcher, dispatch) {
	MockListener listener;
	MockDispatcher dispatcher;
	dispatcher.addEventListener(&listener, REGISTER_UPDATE);
	dispatcher.addEventListener(&listener, TEST);
	ASSERT_EQ(listener.integer, 0);
	dispatcher.doSomething();
	ASSERT_EQ(listener.integer, 1);
	dispatcher.doSomething();
	ASSERT_EQ(listener.integer, 2);
	dispatcher.doOtherthing();
	ASSERT_EQ(listener.integer, 1);

}
