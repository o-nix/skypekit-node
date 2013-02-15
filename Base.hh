#pragma once
#include "stdafx.hh"

namespace o_nix {
	class Base
	{
		public:
			Base();

			static string toUtf8(const v8::Local<v8::Value>& param);

		protected:
			// TODO: Base* GetThis(const v8::Arguments& args);

	};
}
