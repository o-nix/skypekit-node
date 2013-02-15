#include "Account.hh"


o_nix::Account::Account(unsigned int oid, SERootObject* p_root) : ::Account(oid, p_root) {
}


o_nix::Account::~Account() {
}

void o_nix::Account::OnChange(int prop) {
	cout << "Account property change " << prop << endl;
}
