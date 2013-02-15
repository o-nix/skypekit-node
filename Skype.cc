#include "Skype.hh"
#include "Account.hh"
#include "Conversation.hh"


o_nix::Skype::Skype() {
}


o_nix::Skype::~Skype() {
}

void o_nix::Skype::Init(v8::Handle<v8::Object> target) {
	// Prepare constructor template
	v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(New);

	tpl->SetClassName(v8::String::NewSymbol("Skype"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	v8::Persistent<v8::Function> constructor = v8::Persistent<v8::Function>::New(tpl->GetFunction());
	target->Set(v8::String::NewSymbol("Skype"), constructor);

	tpl->InstanceTemplate()->Set(v8::String::NewSymbol("setKey"), v8::FunctionTemplate::New(SetKey)->GetFunction());
	tpl->InstanceTemplate()->Set(v8::String::NewSymbol("setLogin"), v8::FunctionTemplate::New(SetLogin)->GetFunction());
	tpl->InstanceTemplate()->Set(v8::String::NewSymbol("setPassword"), v8::FunctionTemplate::New(SetPassword)->GetFunction());
	tpl->InstanceTemplate()->Set(v8::String::NewSymbol("login"), v8::FunctionTemplate::New(Login)->GetFunction());
}

Account *o_nix::Skype::newAccount(int oid) {
	cout << "Creating a new Account..." << endl;
	return new o_nix::Account(oid, this);
}

Conversation *o_nix::Skype::newConversation(int oid) {
	return new o_nix::Conversation((unsigned int) oid, this);
}

v8::Handle<v8::Value> o_nix::Skype::New(const v8::Arguments& args) {
	// v8::HandleScope scope;

	o_nix::Skype* skype = new o_nix::Skype();
	skype->Wrap(args.This());

	return args.This();
}

v8::Handle<v8::Value> o_nix::Skype::SetKey(const v8::Arguments& args) {
	Skype* skype = node::ObjectWrap::Unwrap<o_nix::Skype>(args.This());

	skype->_key = Base::toUtf8(args[0]);

	return v8::Undefined();
}

v8::Handle<v8::Value> o_nix::Skype::SetLogin(const v8::Arguments& args) {
	Skype* skype = node::ObjectWrap::Unwrap<o_nix::Skype>(args.This());

	skype->_login = Base::toUtf8(args[0]);

	return v8::Undefined();
}

v8::Handle<v8::Value> o_nix::Skype::SetPassword(const v8::Arguments& args) {
	Skype* skype = node::ObjectWrap::Unwrap<o_nix::Skype>(args.This());

	skype->_password = Base::toUtf8(args[0]);

	return v8::Undefined();
}

v8::Handle<v8::Value> o_nix::Skype::Login(const v8::Arguments& args) {
	Skype* skype = node::ObjectWrap::Unwrap<o_nix::Skype>(args.This());

	cout << "Starting skype..." << endl;

	cout << "Key is " << skype->_key.c_str() << endl;
	cout << "Login is " << skype->_login.c_str() << endl;
	cout << "Password is " << skype->_password.c_str() << endl;

	skype->init(skype->_key.c_str(), "127.0.0.1", 8963, "streamlog.txt");
	skype->start();

	cout << "Skype is started." << endl;

	Account::Ref account;

	if (skype->GetAccount(skype->_login.c_str(), account)) {
		cout << "Skype account obtained. Logging in..." << endl;

		account->LoginWithPassword(skype->_password.c_str());
	}

	return v8::Undefined();
}
