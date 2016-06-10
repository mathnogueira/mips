/**
 * \file event_dispatcher.hpp
 *
 * Arquivo contendo o despachante de eventos utilizado por diversos
 * componentes do núcleo do emulador MIPS. Esse despachante é responsável
 * por criar uma interface de despache de eventos para outros componentes,
 * dessa forma, um componente pode comunicar com outro componente usando
 * troca de mensagens, onde estas são transmitidas via eventos.
 *
 */
#pragma once

#include <mips/util/structure/queue.hpp>
#include <mips/util/event/event.hpp>

namespace MIPS {

/**
 * Classe responsável por permitir que componentes do emulador possam
 * se comunicar por troca de mensagens transmitidas por eventos.
 *
 * \author Matheus Nogueira
 */
class EventDispatcher {

public:

	/**
	 * Cria um novo despachante de eventos.
	 */
	EventDispatcher();

	/**
	 * Destroi o despachante de eventos.
	 */
	~EventDispatcher();

	/**
	 * Despacha um evento para todos os seus ouvintes. Caso o evento esteja
	 * marcado com a flag autodestroy, o evento será destruido logo após a
	 * chamada desse método.
	 *
	 * \param event evento a ser despachado.
	 */
	void dispatch(Event &event);

private:

	/**
	 * Busca a fila de ouvintes para um determinado tipo de evento.
	 *
	 * \param type tipo de evento a ser procurado.
	 * \return fila de ouvintes para o determinado evento.
	 */
	Queue<int>* getListeners(EventType type);

};

} // namespace
