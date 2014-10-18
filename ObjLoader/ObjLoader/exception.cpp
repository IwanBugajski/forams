#include "exception.h"

Exception::Exception(string m){
    this->message = m;
}

string Exception::getMessage(){
    return this->message;
}
