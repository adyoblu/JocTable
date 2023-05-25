using namespace System;

public ref class User {
public:
	int id;
	String^ name;
	String^ email;
	String^ address;
	String^ phone;
	String^ password;

	User() {
		id = 0;
		name = "1";
		email = "2";
		address = "3";
		phone = "4";
		password = "5";
	}

};