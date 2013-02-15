#include "Base.hh"

o_nix::Base::Base() {
}


string o_nix::Base::toUtf8(const v8::Local<v8::Value> &param) {
	v8::String::Utf8Value value(param);

	return string(*value);
}
