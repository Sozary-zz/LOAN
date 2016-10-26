

template <typename T>
RoundRect<T>::RoundRect() :
	left(0),
	top(0),
	width(0),
	height(0),
	radius(0)
{

}

////////////////////////////////////////////////////////////
template <typename T>
RoundRect<T>::RoundRect(T leftX, T topY, T diamX, T diamY, T rad) :
	left(leftX),
	top(topY),
	width(diamX),
	height(diamY),
	radius(rad)
{

}

////////////////////////////////////////////////////////////
template <typename T>
RoundRect<T>::RoundRect(const Vector2<T>& position, const Vector2<T>& size, T rad) :
	left(position.x),
	top(position.y),
	width(size.x),
	height(size.y),
	radius(rad)
{

}

////////////////////////////////////////////////////////////
template <typename T>
bool RoundRect<T>::contains(T x, T y) const
{
	Ovale<T> leftTop(left, top, radius, radius);
	Ovale<T> leftBottom(left, top + height - radius * 2, radius, radius);
	Ovale<T> rightTop(left + width - radius * 2, top, radius, radius);
	Ovale<T> rightBottom(left + width - radius * 2, top + height - radius * 2, radius, radius);

	Rect<T> bloc1(left + radius, top, width - radius * 2, height);
	Rect<T> bloc2(left, top + radius, width, height - radius * 2);
	if (leftTop.contains(x, y) == true || leftBottom.contains(x, y) == true || rightTop.contains(x, y) == true || rightBottom.contains(x, y) == true || bloc1.contains(x, y) == true || bloc2.contains(x, y) == true)
	{
		return true;
	}
	else return false;
}

////////////////////////////////////////////////////////////
template <typename T>
bool RoundRect<T>::contains(const Vector2<T>& point) const
{
	return contains(point.x, point.y);
}
