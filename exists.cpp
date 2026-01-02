#include "SocialNetwork.h"

bool SocialNetwork::exists(int id) const {
    return adj.find(id) != adj.end();
}
