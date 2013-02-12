#pragma once
#include "stdafx.h"

namespace o_nix {
	class Skype : public node::ObjectWrap {
		public:
			Skype();
			virtual ~Skype();

			::Skype _skype;

			static v8::Handle<v8::Value> New(const v8::Arguments& args);
			static void Init(v8::Handle<v8::Object> target);
	};
}