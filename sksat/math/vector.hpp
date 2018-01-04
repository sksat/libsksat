#ifndef SKSAT_MATH_VECTOR_HPP_
#define SKSAT_MATH_VECTOR_HPP_

namespace sksat {
namespace math {

template<typename T=double>
class vector {
public:
	vector() { x = {}; y = {}; z = {};}
	vector(T x, T y, T z)	: x(x), y(y), z(z) {}
	vector(T x, T y)		: x(x), y(y) { z = {}; }

	inline void set_x(const T x) { this->x = x; }
	inline void set_y(const T y) { this->y = y; }
	inline void set_z(const T z) { this->z = z; }
	inline void set_xy(const T x, const T y)			{ this->x = x; this->y = y; }
	inline void set_xyz(const T x, const T y, const T z){ this->x = x; this->y = y; this->z = z; }
	inline void set(const T x, const T y)				{ set_xy(x, y); }
	inline void set(const T x, const T y, const T z)	{ set_xyz(x, y, z); }

	inline const T get_x(void)	const { return x; }
	inline const T get_y(void)	const { return y; }
	inline const T get_z(void)	const { return z; }

	inline const vector& operator=(const vector& v) {
		x = v.get_x();
		y = v.get_y();
		z = v.get_z();
		return *this;
	}
	inline const vector& operator+=(const vector& v) {
		x += v.get_x();
		y += v.get_y();
		z += v.get_z();
		return *this;
	}
	inline const vector& operator-=(const vector& v) {
		x -= v.get_x();
		y -= v.get_y();
		z -= v.get_z();
		return *this;
	}

	T x, y, z;
};

template<typename T>
inline vector<T> operator+(const vector<T>& a, const vector<T>& b){
	return vector<T>{
		a.get_x() + b.get_x(),
		a.get_y() + b.get_y(),
		a.get_z() + b.get_z(),
	};
}

template<typename T>
inline vector<T> operator-(const vector<T>& a, const vector<T>& b){
	return vector<T>{
		a.get_x() - b.get_x(),
		a.get_y() - b.get_y(),
		a.get_z() - b.get_z(),
	};
}

template<typename T>
inline vector<T> operator*(const vector<T>& a, const vector<T>& b){
	return vector<T>{
		a.get_x() * b.get_x(),
		a.get_y() * b.get_y(),
		a.get_z() * b.get_z(),
	};
}

template<typename T>
inline const vector<T> operator*(const T& a, const vector<T> v){
	return vector<T>{
		a * v.get_x(),
		a * v.get_y(),
		a * v.get_z(),
	};
}

template<typename T>
inline const vector<T> operator*(const vector<T> v, const T& a){
	return vector<T>{
		v.get_x() * a,
		v.get_y() * a,
		v.get_z() * a,
	};
}

}
}
#endif
