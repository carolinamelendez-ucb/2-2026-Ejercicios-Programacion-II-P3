#pragma once
#include <iostream>
#include <string>
#include "Exception.h"
using namespace std;
class Clientenoencontrado : public Exception {
public:
	Clientenoencontrado(string si) :Exception("error cliente registrado") {

	}

};