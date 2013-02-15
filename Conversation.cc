#include "Conversation.hh"

o_nix::Conversation::Conversation(unsigned int oid, SERootObject *root) : ::Conversation(oid, root) {
}

o_nix::Conversation::~Conversation() {
}

void o_nix::Conversation::OnMessage(const MessageRef &message) {
}
