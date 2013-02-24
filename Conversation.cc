#include "Conversation.hh"

o_nix::Conversation::Conversation(unsigned int oid, SERootObject *root) : ::Conversation(oid, root) {
}

o_nix::Conversation::~Conversation() {
}

void o_nix::Conversation::OnMessage(const MessageRef &message) {
	Message::TYPE messageType;
	message->GetPropType(messageType);

	if (messageType == Message::POSTED_TEXT) {
		SEIntList propIds;
		SEIntDict propValues;
		propIds.append(Message::P_AUTHOR);
		propIds.append(Message::P_BODY_XML);
		propValues = message->GetProps(propIds);

		//if (propValues[0] != myAccountName) {
		printf("<%s> %s\n", (const char*)propValues[0], (const char*)propValues[1]);

		//Message::Ref reply;
		//this->PostText("This is an automated reply.", reply, false);
		//}
	}
}

void o_nix::Conversation::SetSkype(o_nix::Skype *skype) {
	_skype = skype;
}
