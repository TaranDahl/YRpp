#pragma once

#include <DisplayClass.h>
#include <Audio.h>

struct RadarTrackingStruct;

class NOVTABLE RadarClass : public DisplayClass
{
public:
	//WIP: RadarClass::RTacticalClass goes HERE

	//Static
	DEFINE_REFERENCE(RadarClass, Instance, 0x87F7E8u)

	//Destructor
	virtual ~RadarClass() RX;

	//MapClass
	virtual void CreateEmptyMap(const RectangleStruct& pMapRect, bool reuse, char nLevel, bool bUnk2) override
		{ JMP_THIS(0x653F50); }

	virtual void SetVisibleRect(const RectangleStruct& mapRect) override
		{ JMP_THIS(0x654490); }

	//DisplayClass

	//RadarClass
	virtual void DisposeOfArt() RX;
	virtual void* vt_entry_CC(void* out_pUnk, Point2D* pPoint) R0;
	virtual void vt_entry_D0(DWORD dwUnk) RX;
	virtual void Init_For_House() RX;

	//Non-virtual
	Point2D* GetCrdOnRadar(Point2D *pOutBuffer, CoordStruct *pCrd, bool bRestrictToBound)
	{
		JMP_THIS(0x6557F0);
	}

	Point2D GetCrdOnRadar(CoordStruct crd, bool bRestrictToBound = true)
	{
		auto pOutBuffer = new Point2D();
		return *GetCrdOnRadar(pOutBuffer, &crd, bRestrictToBound);
	}

	void RefreshCrd(const Point2D& pCrd)
	{
		JMP_THIS(0x6562D0);
	}

protected:
	//Constructor
	RadarClass() {}	//don't need this

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:
	Point2D unknown_point2d_11E4;
	int unknown_size_11EC;
	int unknown_size_11F0;
	int unknown_size_11F4;
	int unknown_size_11F8;
	DWORD unknown_11FC;
	Point2D unknown_point2d_1200;
	DWORD unknown_color_1208;
	RectangleStruct unknown_rect_120C;
	DSurface* unknown_surface_121C;
	BSurface *unknown_surface_1220;
	DynamicVectorClass<CellStruct> unknown_cells_1124;
	DWORD unknown_123C;
	Point2D unknown_point2d_1240;
	RectangleStruct unknown_rect_1248;
	HashTable<RadarTrackingStruct, TechnoClass*>* unknown_1258;
	DynamicVectorClass<Point2D> unknown_points_125C;
	DWORD unknown_1274;
	DynamicVectorClass<Point2D> FoundationTypePixels[22];
	float RadarSizeFactor;
	int unknown_int_148C;
	DWORD unknown_1490;
	DWORD unknown_1494;
	DWORD unknown_1498;
	RectangleStruct RadarRect;
	DWORD unknown_14AC;
	DWORD unknown_14B0;
	DWORD unknown_14B4;
	DWORD unknown_14B8;
	bool unknown_bool_14BC;
	bool unknown_bool_14BD;
	AudioController RadarAudioController;
	int unknown_int_14D4;
	bool IsAvailableNow;
	bool unknown_bool_14D9;
	bool unknown_bool_14DA;
	RectangleStruct RadarScopeRect;
	RectangleStruct RadarScopeRect2;
	DWORD unknown_14FC;
	SysTimerClass unknown_timer_1500;
};
