/**
 * @file   Record.h
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Header file for the Record class, which provides file handling capabilities.
 *
 * This file contains the definition of the Record class, which includes methods for opening, closing,
 * reading, and writing files, as well as stream operators for file input/output operations.
 */
#ifndef RECORD_H
#define RECORD_H

#include <fstream>
#include <string>


class Record {
private:
    std::fstream file;  ///< File stream object to handle file operations
    std::string fileName;  ///< The name of the file

public:
    Record();
    explicit Record(const std::string& _fileName);
    ~Record();

    bool openFile();
    bool closeFile();
    void setFileName(const std::string& filename);
    std::string readLine();
    bool writeLine(const std::string& line);

    Record& operator<<(const std::string& line);
    Record& operator>>(std::string& line);
};

#endif // RECORD_H

