#include <mips/util/file_reader.hpp>
#include <string>
#include <iostream>

using namespace MIPS;

FileReader::FileReader(const char* filename) {
	this->filter = NULL;
	this->readFile(filename);
}

FileReader::FileReader(const char* filename, Filter& filter) {
	this->filter = &filter;
	this->readFile(filename);
}

FileReader::~FileReader() {
	unsigned long size = this->buffer.size();
	for (unsigned long i = 0; i < size; ++i) {
		delete[] this->buffer.at(i);
	}
}

char* FileReader::next() {
	if (this->currentLine < this->buffer.size())
		return this->buffer.at(this->currentLine++);
	return NULL;
}

void FileReader::rewind() {
	this->currentLine = 0;
}

void FileReader::readFile(const char *filename) {
	file.open(filename);
	std::string line;
	while (std::getline(file, line)) {
		if (this->filter)
			line = filter->filter(line);
		if (line.size() == 0)
			continue;
		char *lBuffer = new char[line.size()];
		line.copy(lBuffer, line.size(), 0);
		this->buffer.push_back(lBuffer);
	}
	this->currentLine = 0;
}
