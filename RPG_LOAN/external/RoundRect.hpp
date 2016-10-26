#ifndef SFML_ROUNDRECT_HPP
#define SFML_ROUNDRECT_HPP

#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Rect.hpp>
#include "..\Ovale.hpp"

namespace sf
{
	template <typename T>
	class RoundRect : public Ovale, public Rect
	{
	public:
		RoundRect();
		RoundRect(T leftX, T topY, T diamX, T diamY, T rad = 0);
		RoundRect(const Vector2<T>& position, const Vector2<T>& size, T rad = 0);

		bool contains(T x, T y) const;
		bool contains(const Vector2<T>& point) const;

		T left;
		T top;
		T width;
		T height;
		T radius;
	};

#include "..\Ovale.inl"

	typedef RoundRect<int> IntRoundRect;
	typedef RoundRect<float> FloatRoundRect;

} // namespace sf


#endif // SFML_ROUNDRECT_HPP
