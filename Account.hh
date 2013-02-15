#pragma once
#include "stdafx.hh"

namespace o_nix {
	class Account : public ::Account {
		public:
			Account(unsigned int oid, SERootObject* p_root);
			virtual ~Account();

			typedef DRef<o_nix::Account, ::Account> Ref;
			typedef DRefs<o_nix::Account, ::Account> Refs;

			void OnChange(int prop);
	};
}
