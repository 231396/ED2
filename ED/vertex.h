#pragma once

#include <string>

class Vertex {
private:
	std::string name;

public:
	Vertex(std::string name = "") {
		this->name = name;
	}
	//~Vertex();
	std::string getName() const {
		return name;
	}
	std::string toString() const {
		return name;
	}

	bool operator==(Vertex& rhs) {
		return this->name == rhs.name;
	}
	bool operator==(const Vertex& rhs) const {
		return this->name == rhs.name;
	}
	bool operator!=(Vertex& rhs) {
		return this->name != rhs.name;
	}
	bool operator!=(const Vertex& rhs) const {
		return this->name != rhs.name;
	}
};

