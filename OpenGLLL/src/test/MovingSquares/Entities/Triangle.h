#pragma once

namespace test {
	class Triangle {
	public:
		Triangle(float x, float y, float z) :
			m_x(x), m_y(y), m_z(z),
			m_a(0), m_b(0) {}

		void SetCoords(float x, float y, float z) {m_x = x; m_y = y; m_z = z;};
		void SetLayout(float a, float b) {m_a = a; m_b = b;}

		float x() const { return m_x; }
		float y() const { return m_y; }
		float z() const { return m_z; }
		float a() const { return m_a; }
		float b() const { return m_b; }
	private:
		float m_x;
		float m_y;
		float m_z;

		float m_a;
		float m_b;
	};
}