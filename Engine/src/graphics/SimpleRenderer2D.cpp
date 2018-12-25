#include "SimpleRenderer2D.h"

void Kinemo::SimpleRenderer2D::Submit(Renderable2D* renderable)
{
	m_Queue.push(renderable);
}

void Kinemo::SimpleRenderer2D::Flush()
{
	for (int i = 0; i < m_Queue.size(); i++)
	{
		m_Queue.front()->Draw();
		m_Queue.pop();
	}
}
