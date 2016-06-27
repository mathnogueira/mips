/**
 * \file event_listener.hpp
 *
 * Arquivo contendo a classe abstrata a qual deve ser pai de todos os objetos
 * que devem ouvir um evento de outro objeto.
 */
#pragma once

#include <mips/util/event/event.hpp>

namespace MIPS {

/**
 * Classe abstrata que permite um objeto ouvir eventos vindos de outra classe.
 *
 * \author Matheus Nogueira
 */
class EventListener {

public:

	/**
	 * Função utilizada para notificar o objeto que algum evento o qual ele está
	 * esperando, ocorreu.
	 *
	 * \param event evento que ocorreu.
	 */
	virtual void notify(Event &event);

};

}; // namespace
