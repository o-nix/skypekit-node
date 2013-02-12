#include "Skype.h"


o_nix::Skype::Skype() {
}


o_nix::Skype::~Skype() {
}

void o_nix::Skype::Init(v8::Handle<v8::Object> target) {
	// Prepare constructor template
	v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(New);

	tpl->SetClassName(v8::String::NewSymbol("Skype"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	// tpl->PrototypeTemplate()->Set(String::NewSymbol("plusOne"), FunctionTemplate::New(PlusOne)->GetFunction());

	v8::Persistent<v8::Function> constructor = v8::Persistent<v8::Function>::New(tpl->GetFunction());
	target->Set(v8::String::NewSymbol("Skype"), constructor);
}

v8::Handle<v8::Value> o_nix::Skype::New(const v8::Arguments& args) {
	v8::HandleScope scope;

	Skype* obj = new Skype();
	obj->Wrap(args.This());

	return args.This();
}