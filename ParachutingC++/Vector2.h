class Vector2
{
public:
    float x, y;

    Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2& other);

	Vector2& operator=(const Vector2& other);

    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;

    Vector2 operator*(float scalar) const;
    Vector2 operator/(float scalar) const;

    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);

    Vector2& operator*=(float scalar);
    Vector2& operator/=(float scalar);

    float magnitude() const;
    Vector2 normalized() const;
};
