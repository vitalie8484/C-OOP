#include "GameObject.h"

#include "GameWindow.h"

using namespace std;

GameObject::GameObject():
color(FL_BLACK),
visible(true)
{
}

bool GameObject::Collides(const GameObject* other) const
{
    return other != nullptr && other->GetPosition().Equals(position);
}

void GameObject::Draw(const GameWindow& windowRef) const
{
    if(IsVisible())
    {
       windowRef.DrawTileAt(position, color);
    }
}