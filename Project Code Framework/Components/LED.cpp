#include "LED.h"

/* Constructor */
LED::LED(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

/* Sets the status of the input pin number n (0-indexed) */
void LED::setInputPinStatus(int n, STATUS s) {
	m_InputPins[n-1].setStatus(s);
}

/* Returns the status of the input pin number n (0-indexed) */
int LED::GetInputPinStatus(int n) {
	return m_InputPins[n-1].getStatus();
}

/* Returns the status of the output pin */
int LED::GetOutPinStatus() {
	return -1;
}

/* Calculates the output of the LED */
void LED::Operate() {
	return;
}

/* Draws the LED */
void LED::Draw(Output* pOut) {
	pOut->DrawLED(m_GfxInfo);
}