#pragma once
using namespace System;

public ref class User {
public:
	int id;
	String^ name;
	String^ email;
	String^ address;
	String^ phone;
	String^ password;
	User() : id(0), name(""), email(""), address(""), phone(""), password("") {

	}
};