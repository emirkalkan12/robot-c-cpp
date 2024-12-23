#include "record.h"
#include <iostream>

Record::Record() = default;

Record::Record(const std::string& _fileName) : fileName(_fileName) {}

Record::~Record() {
    if (file.is_open()) {
        file.close();
        if (file.fail()) {
            std::cerr << "Failed to close the file: " << fileName << std::endl;
        }
    }
}

bool Record::openFile() {
    if (!file.is_open()) {
        file.open(fileName, std::ios::in | std::ios::out | std::ios::app);
    }
    return file.is_open();
}

bool Record::closeFile() {
    if (file.is_open()) {
        file.close();
        return !file.fail();
    }
    return false;
}

void Record::setFileName(const std::string& filename) {
    if (file.is_open()) {
        file.close();
    }
    fileName = filename;
}

std::string Record::readLine() {
    std::string line;
    if (file.is_open() && std::getline(file, line)) {
        return line;
    }
    return "";
}

bool Record::writeLine(const std::string& line) {
    if (file.is_open()) {
        file << line << "\n";
        file.flush();
        return !file.fail();
    }
    return false;
}

Record& Record::operator<<(const std::string& line) {
    if (file.is_open()) {
        file << line << "\n";
        file.flush();
    }
    return *this;
}

Record& Record::operator>>(std::string& line) {
    if (file.is_open() && std::getline(file, line)) {
        // Successfully read a line.
    }
    else {
        line.clear();
    }
    return *this;
}
