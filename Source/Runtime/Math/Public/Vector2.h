#pragma once

namespace CK
{

	// 좌표를 관리하기 위해 Vector2 선언
	// Vector2를 사용하는 과정에서 벡터와 스칼라와의 연산은 빈번히 발생하기 때문에, 
	// 스택(Stack) 공간에서 데이터를 처리하는 데 중점을 두는 키워드인 구조체(struct)를 사용해 선언했다.
	// 구조체의 연산을 선언할 때는 가급적 함수 호출 없이 빠르게 처리되도록 인라인 키워드 FORCEINLINE을 사용했으며,
	// 가능하다면 컴파일 과정에서도 미리 계산될 수 있도록 constexpr 키워드도 선언했다.
	// 또한 모든 함수를 선언할 때에는 한정자 const 키워드를 사용해 입력과 출력의 수정 권한을 명확하게 지정하였다.
	// 벡터의 좌표 정보를 저장하는 데 사용할 Vector2는 두 개의 실수 값을 관리하고 있다.
struct Vector2
{
public:
	// 생성자 
	FORCEINLINE constexpr Vector2() = default;
	FORCEINLINE explicit constexpr Vector2(int InX, int InY) : X((float)InX), Y((float)InY) { }
	FORCEINLINE explicit constexpr Vector2(float InX, float InY) : X(InX), Y(InY) { }

	// 연산자 
	FORCEINLINE constexpr float operator[](BYTE InIndex) const;
	FORCEINLINE constexpr float& operator[](BYTE InIndex);
	FORCEINLINE constexpr Vector2 operator-() const;
		// * 연산자로 벡터와 스칼라의 곱셈 연산을 수행할 수 있도록 선언했다.
	FORCEINLINE constexpr Vector2 operator*(float InScalar) const;
	FORCEINLINE constexpr Vector2 operator/(float InScalar) const;
	FORCEINLINE constexpr Vector2 operator*(const Vector2& InVector) const;
		// + 연산자로 벡터와 벡터의 합 연산을 수행할 수 있도록 선언한다.
	FORCEINLINE constexpr Vector2 operator+(const Vector2& InVector) const;
	FORCEINLINE constexpr Vector2 operator-(const Vector2& InVector) const;
	FORCEINLINE constexpr Vector2& operator*=(float InScale);
	FORCEINLINE constexpr Vector2& operator/=(float InScale);
	FORCEINLINE constexpr Vector2& operator+=(const Vector2& InVector);
	FORCEINLINE constexpr Vector2& operator-=(const Vector2& InVector);

	// 멤버함수 
	FORCEINLINE float Size() const;
	FORCEINLINE constexpr float SizeSquared() const;
	void Normalize();
	[[nodiscard]] Vector2 GetNormalize() const;
	FORCEINLINE constexpr bool EqualsInTolerance(const Vector2& InVector, float InTolerance = SMALL_NUMBER) const;
	FORCEINLINE constexpr float Max() const;
	FORCEINLINE constexpr float Dot(const Vector2& InVector) const;
	FORCEINLINE float Angle() const;
	FORCEINLINE float AngleInDegree() const;
	FORCEINLINE Vector2 ToPolarCoordinate() const;
	FORCEINLINE constexpr Vector2 ToCartesianCoordinate() const;

	std::string ToString() const;

	// 정적멤버변수 
	static const Vector2 UnitX;
	static const Vector2 UnitY;
	static const Vector2 One;
	static const Vector2 Zero;
		// Vector2가 가지고 있는 멤버 변수의 개수를 알 수 있도록 차원(Dimension)이라는 정적 변수를 선언하고 이 값을 2로 지정한다.
	static constexpr BYTE Dimension = 2;

	// 멤버변수
		// 일반적으로 Vector2를 구성하는 각 원소는 멤버 변수 X, Y를 사용해 접근하지만,
		// 배열로도 접근할 수 있도록 union 키워드를 사용해 std::array로 선언된 2차원 배열을 추가로 선언했다.
	union
	{
		struct
		{
			float X, Y;
		};

		std::array<float, Dimension> Scalars = { 0.f, 0.f };
	};
};

FORCEINLINE float Vector2::Size() const
{
	return sqrtf(SizeSquared());
}

FORCEINLINE constexpr float Vector2::SizeSquared() const
{
	return X * X + Y * Y;
}

FORCEINLINE void Vector2::Normalize()
{
	*this = GetNormalize();
}

FORCEINLINE constexpr float Vector2::operator[](BYTE InIndex) const
{
	assert(InIndex < Dimension);
	return Scalars[InIndex];
}

FORCEINLINE constexpr float &Vector2::operator[](BYTE InIndex)
{
	assert(InIndex < Dimension);
	return Scalars[InIndex];
}

FORCEINLINE constexpr Vector2 Vector2::operator-() const
{
	return Vector2(-X, -Y);
}

FORCEINLINE constexpr Vector2 Vector2::operator*(float InScalar) const
{
	return Vector2(X * InScalar, Y * InScalar);
}

FORCEINLINE constexpr Vector2 Vector2::operator/(float InScalar) const
{
	return Vector2(X / InScalar, Y / InScalar);
}

FORCEINLINE constexpr Vector2 Vector2::operator+(const Vector2& InVector) const
{
	return Vector2(X + InVector.X, Y + InVector.Y);
}

FORCEINLINE constexpr Vector2 Vector2::operator-(const Vector2& InVector) const
{
	return Vector2(X - InVector.X, Y - InVector.Y);
}

FORCEINLINE constexpr Vector2 Vector2::operator*(const Vector2& InVector) const
{
	return Vector2(X * InVector.X, Y * InVector.Y);
}

FORCEINLINE constexpr Vector2& Vector2::operator*=(float InScale)
{
	X *= InScale;
	Y *= InScale;
	return *this;
}

FORCEINLINE constexpr Vector2& Vector2::operator/=(float InScale)
{
	X /= InScale;
	Y /= InScale;
	return *this;
}

FORCEINLINE constexpr Vector2& Vector2::operator+=(const Vector2& InVector)
{
	X += InVector.X;
	Y += InVector.Y;
	return *this;
}

FORCEINLINE constexpr Vector2& Vector2::operator-=(const Vector2& InVector)
{
	X -= InVector.X;
	Y -= InVector.Y;
	return *this;
}

FORCEINLINE constexpr bool Vector2::EqualsInTolerance(const Vector2& InVector, float InTolerance) const
{
	return (Math::Abs(this->X - InVector.X) <= InTolerance) &&
		(Math::Abs(this->Y - InVector.Y) < InTolerance);
}

FORCEINLINE constexpr float Vector2::Max() const
{
	return Math::Max(X, Y);
}

FORCEINLINE constexpr float Vector2::Dot(const Vector2& InVector) const
{
	return X * InVector.X + Y * InVector.Y;
}

FORCEINLINE float Vector2::Angle() const
{
	return atan2f(Y,X);
}

FORCEINLINE float Vector2::AngleInDegree() const
{
	return Math::Rad2Deg(atan2f(Y, X));
}

FORCEINLINE Vector2 Vector2::ToPolarCoordinate() const
{
	return Vector2(Size(), Angle());
}

FORCEINLINE constexpr Vector2 Vector2::ToCartesianCoordinate() const
{
	// 극좌표계에서 X는 반지름, Y는 각(rad)으로 활용
	float sin = 0.f, cos = 0.f;
	Math::GetSinCosRad(sin, cos, Y);
	return Vector2(X * cos, X * sin);
}

}