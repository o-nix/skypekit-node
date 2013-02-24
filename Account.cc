#include "Account.hh"
#include "Skype.hh"


o_nix::Account::Account(unsigned int oid, SERootObject* p_root) : ::Account(oid, p_root) {
}

o_nix::Account::~Account() {
}

void o_nix::Account::SetSkype(o_nix::Skype *skype) {
	_skype = skype;
}

void o_nix::Account::OnChange(int prop) {
	cout << "Account property change " << prop << endl;

	if (prop == Account::P_STATUS) {
		Account::STATUS loginStatus;

		this->GetPropStatus(loginStatus);

		if (loginStatus == Account::LOGGED_IN) {
			_skype->OnLoggedIn(this);
		}
		else if (loginStatus == Account::LOGGED_OUT) {
			// Account can proceed to LOGGED_OUT not only on because of intentional logout.
			// This state is also reached by failure conditions, such as invalid password, etc.
			Account::LOGOUTREASON logoutReason;
			GetPropLogoutreason(logoutReason);

			_skype->OnLoggedOut(this, (const char*) tostring(logoutReason));
		}
	}
}
