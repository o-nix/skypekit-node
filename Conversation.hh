#pragma once
#include "stdafx.hh"

namespace o_nix {
	class Skype;

	class Conversation : public ::Conversation {
		private:
			o_nix::Skype* _skype;

		public:
			Conversation(unsigned int oid, SERootObject* root);
			virtual ~Conversation();

			typedef DRef<o_nix::Conversation, ::Conversation> Ref;
			typedef DRefs<o_nix::Conversation, ::Conversation> Refs;

			void OnMessage(const MessageRef & message);

			void SetSkype(o_nix::Skype *skype);
	};
}
