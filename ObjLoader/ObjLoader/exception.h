#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
using namespace std;

class Exception{
protected:
    string message;
public:
    Exception(string m = "");
    string getMessage();
};

class FileNotFoundException : public Exception{
public:
    FileNotFoundException(string m = "") : Exception(m) {}
};

class IndexOutOfBoundsException : public Exception{
public:
    IndexOutOfBoundsException(string m = "") : Exception(m) {}
};

class InvalidFileFormatException : public Exception{
public:
    InvalidFileFormatException(string m = "") : Exception(m) {}
};

#endif // EXCEPTION_H
