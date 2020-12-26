#include "Gate.h"
 
 
Gate::Gate(Output* pOut, const GraphicsInfo& gfxInfo) {
	SetGraphicsInfo(pOut, gfxInfo);
}
 
 
void Gate::SetGraphicsInfo(Output* pOut, const GraphicsInfo& gfxInfo) {
 
 
	mGfxInfo = gfxInfo;
	pOut->MarkPinArea(mGfxInfo, PinType::GATE, this); //an Output function
}
 
 
int Gate::GetInputPinIndex(int x, int y) {
	return 0;
}
 
 
void Gate::GetInputPinCoordinates(int& x, int& y, int n) {
	x = mGfxInfo.x1 - UI.Margin;
	y = mGfxInfo.y1 + UI.Margin + UI.Offset * n;
}
 
 
void Gate::GetOutputPinCoordinates(int& x, int& y) {
	x = mGfxInfo.x2 + UI.Margin;
	y = mGfxInfo.y1 + (mGfxInfo.y2 - mGfxInfo.y1) / 2;
}
 
 
Gate::~Gate() {
 
}
