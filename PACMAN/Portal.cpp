#include "Portal.h"

Portal::Portal()
{
    SetVisible(true);
	SetColor(FL_YELLOW);
}

void Portal::OnCollision(const GameObject* other)
{
    //Do nothing!
}