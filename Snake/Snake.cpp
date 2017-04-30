#include "Snake.h"
#include "SnakeWindow.h"

Snake::Snake(Vector2d position)
	: head(position)
{
	direction = EAST;
	sections.push_front(Vector2d(head.x, head.y));
	size_t snakeLength = 3;
	for (size_t i = 1; i <= snakeLength; i++)
	{
		sections.push_back(Vector2d(head.x - i, head.y));
	}
}

void Snake::Move(double deltaTime)
{
	MoveOneStep();
	sections.pop_back();
}

void Snake::MoveOneStep()
{
	switch (direction)
	{
	case NORTH:
		head.y -= 1;
		break;
	case SOUTH:
		head.y += 1;
		break;
	case EAST:
		head.x += 1;
		break;
	case WEST:
		head.x -= 1;
		break;
	default:
		std::cout << "Received unknown direction:" << direction << std::endl;
	}
	sections.push_front(Vector2d(head.x, head.y));
}

void Snake::MoveBy(double deltaPosition)
{
	sections.push_front(Vector2d(head.x + deltaPosition, head.y + deltaPosition));
}

void Snake::Draw(const SnakeWindow& windowRef)const
{
	for (Vector2d v : sections)
	{
		windowRef.DrawTileAt(v.ToVector2i());
	}
}

void Snake::IncreaseLengthBy1()
{
	MoveOneStep();
}

bool Snake::IsOnSnake(Vector2i pos) const
{
	for (Vector2d v : sections)
	{
		if (v.ToVector2i().Equals(pos))
		{
			return true;
		}
	}
    return false;
}

void Snake::SetDirection(DIRECTION value)
{
	if (((direction == NORTH || direction == SOUTH) && (value == EAST || value == WEST)) || 
		((direction == EAST || direction == WEST) && (value == NORTH || value == SOUTH)))
	{
		direction = value;
	}
}

bool Snake::IsRollOver() const
{
	for (size_t i = 1; i < sections.size(); i++)
	{
		if (sections[i].ToVector2i().Equals(head.ToVector2i()))
		{
			return true;
		}
	}
    return false;
}

Vector2d Snake::GetPosition() const
{
    return head;
}