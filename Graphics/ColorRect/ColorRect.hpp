#pragma once
#include "../../Functionality/Color/Color.hpp"
#include "../../Include/EZ++Func.hpp"

namespace EZ {
	enum class COLORRECT {
		FILL,
		OUTLINE
	};

	class ColorRect : public CanvasItem, public Rect {
	public:
	    ColorRect();
	    ColorRect(const Rect& body, const EZ::Color color);
	
	    COLORRECT Mode;
	    int Thickness;
		bool Visible;
	
	    bool Collides(const ColorRect& other) const;
	    bool Collides(const Rect& other) const;
	
	    EZ::Color Color;
	    void Render() const;
	};
}
