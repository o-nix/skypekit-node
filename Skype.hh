#pragma once
#include "Base.hh"
#include "Account.hh"
#include "Conversation.hh"


namespace o_nix {
	class Skype : public Base, public node::ObjectWrap, public ::Skype {
		protected:
			Skype();
			virtual ~Skype();

			Account::Ref _account;
			o_nix::Conversation::Refs _conversations;
			string _key;
			string _login;
			string _password;

			static const v8::Persistent<v8::String> EMIT_NAME;
			static const v8::Persistent<v8::String> LOGIN_EVENT_NAME;

			static void OnLoggedIn_(uv_async_t* handle, int status);

		public:
			static v8::Handle<v8::Value> New(const v8::Arguments& args);
			static void Init(v8::Handle<v8::Object> target);
			static v8::Handle<v8::Value> SetKey(const v8::Arguments &args);
			static v8::Handle<v8::Value> SetLogin(const v8::Arguments &args);
			static v8::Handle<v8::Value> SetPassword(const v8::Arguments &args);
			static v8::Handle<v8::Value> FillInbox(const v8::Arguments &args);
			static v8::Handle<v8::Value> Login(const v8::Arguments &args);

			void OnLoggedIn(o_nix::Account* account);
			void OnLoggedOut(const o_nix::Account* account, const char* reason);

			::Account* newAccount(int oid);
			::Conversation* newConversation(int oid);
	};
}
