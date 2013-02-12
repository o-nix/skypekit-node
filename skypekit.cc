#include "stdafx.h"
#include "Skype.h"


void Init(v8::Handle<v8::Object> target) {
	o_nix::Skype::Init(target);
}

NODE_MODULE(skypekit, Init)