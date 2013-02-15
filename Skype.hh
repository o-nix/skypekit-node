#pragma once
#include "Base.hh"

namespace o_nix {
	class Skype : public Base, public node::ObjectWrap, public ::Skype {
		protected:
			Skype();
			virtual ~Skype();

			Conversation::Refs _conversations;
			string _key;
			string _login;
			string _password;

		public:
			static v8::Handle<v8::Value> New(const v8::Arguments& args);
			static void Init(v8::Handle<v8::Object> target);
			static v8::Handle<v8::Value> SetKey(const v8::Arguments &args);
			static v8::Handle<v8::Value> SetLogin(const v8::Arguments &args);
			static v8::Handle<v8::Value> SetPassword(const v8::Arguments &args);
			static v8::Handle<v8::Value> Login(const v8::Arguments &args);

			Account* newAccount(int oid);
			Conversation* newConversation(int oid);
	};
}
