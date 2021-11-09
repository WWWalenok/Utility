#pragma once

template<typename T, const unsigned int S, const unsigned int D[S], const unsigned int I[S]>
struct Tensus
{
private:

	unsigned long int L = 0;

public:
	T* M = 0;

	Tensus()
	{
		L = 0;
		for (int i = 0; i < S; i++)
			L += D[i];
		M = new T[L];
	}


	Tensus(T& I) : Tensus()
	{
		for (int i = 0; i < L; i++)
			M[i] = I;
	}

	Tensus(T I) : Tensus()
	{
		for (int i = 0; i < L; i++)
			M[i] = I;
	}

	inline unsigned long int id(unsigned int V[S])
	{
		unsigned long int r = V[0];
		for (int i = 1; i < S; i++)
			r = r * D[i - 1] + V[i] % D[i];
		return r;
	}

	T& operator[] (unsigned int V[S]) { return M[id(V)]; }


	template<typename T, const unsigned int S, const unsigned int D[S]>
	const Tensus<T, S, D> operator*(Tensus<T, S, D>& left, T right)
	{
		Tensus<T, S, D> L;
		for (int i = 0; i < L.L; i++) L.M[i] = right * left.M[i];
		return L;
	}

	template<typename T, const unsigned int S, const unsigned int D[S]>
	const Tensus<T, S, D> operator*(T right, Tensus<T, S, D>& left)
	{
		Tensus<T, S, D> L;
		for (int i = 0; i < L.L; i++) L.M[i] = right * left.M[i];
		return L;
	}

	template<typename T, const unsigned int S, const unsigned int D[S]>
	const T operator*(Tensus<T, S, D>& left, Tensus<T, S, D>& right)
	{
		T L = 0;
		for (int i = 0; i < L.L; i++) L.M[i] = right.M[i] * left.M[i];
		return L;
	}

	template<typename T, const unsigned int S, const unsigned int D[S]>
	const Tensus<T, S, D> operator/(Tensus<T, S, D>& left, T right)
	{
		Tensus<T, S, D> L;
		for (int i = 0; i < D; i++) L.M[i] = left[i] / right;
		return L;
	}

	template<typename T, const unsigned int S, const unsigned int D[S]>
	const Tensus<T, S, D> operator -(Tensus<T, S, D>& left, Tensus<T, S, D>& right)
	{
		Tensus<T, S, D> L;
		for (int i = 0; i < D; i++) L.M[i] = left[i] - right[i];
		return L;
	};

	template<typename T, const unsigned int S, const unsigned int D[S]>
	const Tensus<T, S, D> operator +(Tensus<T, S, D>& left, Tensus<T, S, D>& right)
	{
		Tensus<T, S, D> L;
		for (int i = 0; i < D; i++) L.M[i] = left[i] + right[i];
		return L;
	};


};