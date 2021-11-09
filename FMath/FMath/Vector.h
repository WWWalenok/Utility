#pragma once

template<typename T, const unsigned int D = 1>
struct Vector
{
	T M[D];

	Vector()
	{

	}

	Vector(T* I)
	{
		for (int i = 0; i < D; i++)
			M[D] = I[i];
	}

	Vector(T& I)
	{
		for (int i = 0; i < D; i++)
			M[D] = I;
	}

	Vector(T I)
	{
		for (int i = 0; i < D; i++)
			M[D] = I;
	}

	inline
		T& operator[](unsigned int i) { return M[i % D]; }

	Vector<T, D> operator +() { Vector<T, D> L; for (int i = 0; i < D; i++) L.M[i] = M[i]; return L; }

	Vector<T, D> operator -() { Vector<T, D> L; for (int i = 0; i < D; i++) L.M[i] = -M[i]; return L; }

	Vector<T, D>& operator=(Vector<T, D>& right)
	{
		if (this == &right) {
			return *this;
		}
		for (int i = 0; i < D; i++) M[i] = right.M[i];
		return *this;
	}
	Vector<T, D>& operator=(T& right)
	{
		if (this == &right) {
			return *this;
		}
		for (int i = 0; i < D; i++) M[i] = right;
		return *this;
	}
};

typedef Vector<float, 2> Vector2f;
typedef Vector<float, 3> Vector3f;
typedef Vector<double, 2> Vector2d;
typedef Vector<double, 3> Vector3d;


template<typename T, const unsigned int D>
const Vector<T, D> operator*(Vector<T, D>& left, T right)
{
	Vector<T, D> L;
	for (int i = 0; i < D; i++) L[i] = right * left[i];
	return L;
}

template<typename T, const unsigned int D>
const Vector<T, D> operator*(T right, Vector<T, D>& left)
{
	Vector<T, D> L;
	for (int i = 0; i < D; i++) L.M[i] = right * left[i];
	return L;
}

template<typename T, const unsigned int D>
const T operator*(Vector<T, D>& left, Vector<T, D>& right)
{
	T L = 0;
	for (int i = 0; i < D; i++) L = L + right[i] * left[i];
	return L;
}

template<typename T, const unsigned int D>
const Vector<T, D> operator/(Vector<T, D>& left, T right)
{
	Vector<T, D> L;
	for (int i = 0; i < D; i++) L.M[i] = left[i] / right;
	return L;
}

template<typename T, const unsigned int D>
const Vector<T, D> operator -(Vector<T, D>& left, Vector<T, D>& right)
{
	Vector<T, D> L;
	for (int i = 0; i < D; i++) L.M[i] = left[i] - right[i];
	return L;
};

template<typename T, const unsigned int D>
const Vector<T, D> operator +(Vector<T, D>& left, Vector<T, D>& right)
{
	Vector<T, D> L;
	for (int i = 0; i < D; i++) L.M[i] = left[i] + right[i];
	return L;
};



