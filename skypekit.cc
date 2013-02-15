#include "stdafx.hh"
#include "Skype.hh"


void Init(v8::Handle<v8::Object> target) {
	o_nix::Skype::Init(target);
}

NODE_MODULE(skypekit, Init)
