#pragma once
#include <iostream>
#include <string>
#include "Exception.h"
using namespace std;
class ClienteDuplicadoException : public Exception {
public:
	ClienteDuplicadoException(string si) :Exception("error cliente registrado") {
	};

};