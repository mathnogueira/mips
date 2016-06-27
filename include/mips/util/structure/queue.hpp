/**
 * \file queue.h
 *
 * Arquivo contendo a implementação de uma fila encadeada.
 */
#pragma once

#include <cstdlib>

namespace MIPS {

/**
 * Fila genérica que utiliza template para auxiliar em seu reuso.
 *
 * \param Matheus Nogueira
 */
template <typename T>
class Queue {

public:

	/**
	 * Nó da fila.
	 */
	struct Node {
		T content;
		struct Node* next;
	};

	/**
	 * Cria uma nova fila encadeada.
	 */
	Queue() {
		head_ = NULL;
		size_ = 0;
	}

	/**
	 * Destroi a fila e todos os seus elementos.
	 */
	~Queue() {
		struct Node* aux;
		if (head_ != NULL) {
			do {
				aux = head_->next;
				delete head_;
				head_ = aux;
			} while (aux != NULL);
		}
	}

	/**
	 * Adiciona um elemento à fila.
	 *
	 * \param elem elemento que será inserido na fila.
	 */
	void push(T &elem) {
		struct Node* node = new struct Node;
		node->content = elem;
		node->next = NULL;
		if (head_ == NULL) {
			head_ = node;
			size_ = 1;
			return;
		}
		struct Node* aux = head_;
		for (; aux->next != NULL; aux = aux->next);
		aux->next = node;
		++size_;
	}

	/**
	 * Retira um elemento da fila.
	 *
	 * \return elemento no inicio da fila.
	 */
	T pop() {
		struct Node* aux = head_;
		head_ = head_->next;
		T content = aux->content;
		delete aux;
		--size_;
		return content;
	}

	/**
	 * Recupera o elemento que está na posição especificada da fila.
	 *
	 * \param pos posição do elemento na fila.
	 * \return elemento na posição especificada.
	 */
	T get(size_t pos) {
		struct Node* aux = head_;
		for (unsigned int i = 0; i < pos && aux->next != NULL; aux = aux->next, ++i);
		return aux->content;
	}

	/**
	 * Retorna o tamanho da fila.
	 *
	 * \return tamanho atual da fila.
	 */
	size_t size() {
		return size_;
	}

private:

	/**
	 * Cabeça da fila.
	 */
	struct Node *head_;

	/**
	 * Tamanho da fila.
	 */
	size_t size_;

};

} // namespace
