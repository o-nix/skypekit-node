#include "Skype.hh"
#include "Account.hh"
#include "Conversation.hh"

const v8::Persistent<v8::String> o_nix::Skype::LOGIN_EVENT_NAME = NODE_PSYMBOL("login");
const v8::Persistent<v8::String> o_nix::Skype::EMIT_NAME = NODE_PSYMBOL("emit");

o_nix::Skype::Skype() {
}

o_nix::Skype::~Skype() {
}

void o_nix::Skype::Init(v8::Handle<v8::Object> target) {
	// Prepare constructor template
	v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(New);
	v8::Local<v8::ObjectTemplate> instance = tpl->InstanceTemplate();

	tpl->SetClassName(v8::String::NewSymbol("Skype"));
	instance->SetInternalFieldCount(1);

	v8::Persistent<v8::Function> constructor = v8::Persistent<v8::Function>::New(tpl->GetFunction());
	target->Set(v8::String::NewSymbol("Skype"), constructor);

	node::SetMethod(instance, "setKey", SetKey);
	node::SetMethod(instance, "setLogin", SetLogin);
	node::SetMethod(instance, "setPassword", SetPassword);
	node::SetMethod(instance, "login", Login);
}

::Account *o_nix::Skype::newAccount(int oid) {
	cout << "Creating a new Account..." << endl;

	o_nix::Account* acc = new o_nix::Account(oid, this);
	acc->SetSkype(this);

	return acc;
}

::Conversation *o_nix::Skype::newConversation(int oid) {
	cout << "New Conversation object created." << endl;

	return new o_nix::Conversation(oid, this);
}

v8::Handle<v8::Value> o_nix::Skype::New(const v8::Arguments& args) {
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

v8::Handle<v8::Value> o_nix::Skype::FillInbox(const v8::Arguments &args) {
	Skype* skype = node::ObjectWrap::Unwrap<o_nix::Skype>(args.This());

	return v8::Undefined();
}

v8::Handle<v8::Value> o_nix::Skype::Login(const v8::Arguments& args) {
	Skype* skype = node::ObjectWrap::Unwrap<o_nix::Skype>(args.This());

	cout << "Starting skype..." << endl;

	cout << "Login is " << skype->_login.c_str() << endl;
	cout << "Password is " << skype->_password.c_str() << endl;

	skype->init(skype->_key.c_str(), "127.0.0.1", 8963, "streamlog.txt");
	skype->start();

	cout << "Skype is started." << endl;

	if (skype->GetAccount(skype->_login.c_str(), skype->_account)) {
		cout << "Skype account obtained. Logging in..." << endl;

		skype->_account->LoginWithPassword(skype->_password.c_str());
	}

	return v8::Undefined();
}

void o_nix::Skype::OnLoggedIn_(uv_async_t *handle, int status) {
	v8::HandleScope scope;

	pair<o_nix::Skype*, o_nix::Account*>* data = reinterpret_cast< pair<o_nix::Skype*, o_nix::Account*>* > (handle->data);
	o_nix::Skype* skype = data->first;

	cout << "Getting skype conversations list..." << endl;

	skype->GetConversationList(skype->_conversations, Conversation::INBOX_CONVERSATIONS);
	fetch(skype->_conversations);

	v8::Handle<v8::Value> argv[1] = {
		LOGIN_EVENT_NAME
	};

	node::MakeCallback(skype->handle_, EMIT_NAME, 1, argv);

	v8::Local<v8::Function> emitHandler = v8::Local<v8::Function>::Cast(skype->handle_->Get(EMIT_NAME));
	emitHandler->Call(skype->handle_, 1, argv);

	uv_close((uv_handle_t*) handle, NULL);
	delete data, handle;
}

void o_nix::Skype::OnLoggedIn(o_nix::Account* account) {
	cout << "Logged in!" << endl;

	uv_async_t* async = new uv_async_t();
	async->data = new pair<o_nix::Skype*, o_nix::Account*> (this, account);

	uv_async_init(uv_default_loop(), async, OnLoggedIn_);
	uv_async_send(async);
}

void o_nix::Skype::OnLoggedOut(const o_nix::Account *account, const char *reason) {
	cout << "Logged out. Reason: " << reason;
}
