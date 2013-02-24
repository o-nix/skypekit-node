#pragma once
#include "stdafx.hh"


namespace o_nix {
	class Skype;

	class Account : public ::Account {
		protected:
			o_nix::Skype* _skype;

		public:
			Account(unsigned int oid, SERootObject* p_root);
			virtual ~Account();

			typedef DRef<o_nix::Account, ::Account> Ref;
			typedef DRefs<o_nix::Account, ::Account> Refs;

			void SetSkype(o_nix::Skype* skype);

			void OnChange(int prop);
	};
}
