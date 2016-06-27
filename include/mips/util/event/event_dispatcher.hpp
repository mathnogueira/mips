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
#include <mips/util/event/event_listener.hpp>
#include <mips/util/event/event.hpp>
#include <vector>

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

	/**
	 * Adiciona um ouvinte de eventos nesse despachante.
	 *
	 * \param listener ouvinte de eventos
	 * \param event tipo de evento que o ouvinte irá escutar.
	 */
	void addEventListener(EventListener *listener, EventType event);

protected:

	/**
	 * Classe responsável por representar um tipo de evento ligado a uma
	 * fila de ouvintes que devem ser notificados.
	 */
	struct ListenerMap {
		EventType type;						///< Tipo de evento
		Queue<EventListener*> *listeners; 	///< Fila de ouvintes
	};

private:

	/**
	 * Lista de ouvintes de eventos.
	 */
	std::vector<ListenerMap> listeners;

	/**
	 * Retorna a fila que está armazenando os ouvintes de um determinado tipo de evento.
	 *
	 * \param event tipo de evento
	 * \return ponteiro para a fila de ouvintes
	 */
	Queue<EventListener*>* getListeners(EventType event);

};

} // namespace
