#include "Pin.h"

Pin::Pin()
{

	m_Status = UNASSIGNED;	//Default Status is UNASSIGNED
	Connected = false;

}

void Pin::setStatus(STATUS r_Status)
{
	m_Status = r_Status;
}

STATUS Pin::getStatus()
{
	return m_Status;
}

bool Pin::getConnected()
{
	return Connected;
}

void Pin::setConnected(bool c)
{
	Connected = c;
}

