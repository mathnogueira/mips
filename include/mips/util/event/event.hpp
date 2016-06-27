/**
 * \file event.hpp
 *
 * Arquivo contendo um evento base que é despachavel pelo despachante de
 * eventos do emulador de MIPS.
 *
 */
#pragma once

namespace MIPS {

/**
 * Enum utilizado para listar todos os tipos de eventos suportados pelo
 * emulador MIPS.
 *
 */
enum EventType {
	REGISTER_UPDATE, 	///< Indica que um registrador foi alterado.
	TEST,
};

/**
 * Classe responsável por representar um evento que pode ser despachado
 * pelo despachante de eventos do emulador.
 *
 * \author Matheus Nogueira
 */
class Event {

public:

	/**
	 * Cria um novo evento.
	 *
	 * \param type tipo do evento
	 * \param data dados associados ao evento. Esses dados associados devem
	 *        ser alocados de forma dinâmica pelo programador, utilizando a
	 *        função malloc. O despachante de eventos é responsável por
	 *        destruir esses dados após seu uso caso a flag autodestroy seja
	 *        ativada.
	 * \param autodestroy indica que os dados do evento devem ser destruídos
	 *        após que o evento seja despachado para todos seus ouvintes.
	 */
	Event(EventType type, void *data, bool autodestroy = false);

	/**
	 * Destroi o evento e os dados relacionados ao mesmo.
	 */
	virtual ~Event();

	/**
	 * Verifica se o evento deve se auto destruir.
	 *
	 * \return true se o evento deve se auto destruir.
	 */
	bool shouldDestroy();

	/**
	 * Tipo de evento.
	 */
	const EventType event_type;

	/**
	 * Ponteiro para os dados do evento.
	 */
	void *data_ptr;

private:

	/**
	 * Indicador de auto destruição
	 */
	const bool autodestroy_;
};

} // namespace
