#pragma once
#include "stdafx.hh"

namespace o_nix {
	class Conversation : public ::Conversation
	{
		public:
            Conversation(unsigned int oid, SERootObject* root);
            virtual ~Conversation();

			typedef DRef<Conversation, ::Conversation> Ref;
			typedef DRefs<Conversation, ::Conversation> Refs;

			void OnMessage(const MessageRef & message);
    };
}
