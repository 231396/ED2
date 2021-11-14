#pragma once

#include <iostream>

class Vertex {
	private:
		std::string nome;
	public:
		Vertex() {
			this->nome = "";
		}
		Vertex(std::string nome) {
			this->nome = nome;
		}
		std::string getNome() const {
			return nome;
		}
};
