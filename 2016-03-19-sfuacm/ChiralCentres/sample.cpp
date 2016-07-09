// Chiral Centres
// Jonathon Simister

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class v3
{
public:
	v3(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	v3 crossproduct(const v3& v) const
	{
		return v3(
			this->y * v.z - this->z * v.y,
			this->z * v.x - this->x * v.z,
			this->x * v.y - this->y * v.x);
	}

	v3 normalize() const
	{
		return v3(this->x / this->length(), this->y / this->length(), this->z / this->length());
	}

	double length() const
	{
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	double x, y, z;
};

class atom {
public:
	atom(int n, double x, double y, double z)
	{
		this->n = n;
		this->x = x;
		this->y = y;
		this->z = z;
		this->bonds = 0;
	}

	bool operator<(const atom& l) const
	{
		return this->n < l.n;
	}

	int n;
	double x, y, z;
	int bonds;
};

int main() {
	vector<atom> atoms;

	while(true)
	{
		atoms.clear();

		for(int i = 0;i < 5;i++)
		{
			int n;
			double x, y, z;
			if(scanf("%d %lf %lf %lf", &n, &x, &y, &z) != 4) {
				return 0;
			}

			atoms.push_back(atom(n, x, y, z));
		}

		for(int i = 1;i < 5;i++) {
			if(atoms[i].n == 6) {
				swap(atoms[i], atoms[0]);
			}
		}

		sort(atoms.begin() + 1, atoms.end());

		for(int i = 1;i < 4;i++)
		{
			if(atoms[i].n == atoms[i + 1].n)
			{
				puts("No chiral centre");
				goto wend;
			}
		}

		v3 viewvector = v3(atoms[1].x - atoms[0].x, atoms[1].y - atoms[0].y, atoms[1].z - atoms[0].z);
		v3 p1vector = v3(atoms[4].x - atoms[0].x, atoms[4].y - atoms[0].y, atoms[4].z - atoms[0].z);

		v3 rightvector = viewvector.crossproduct(p1vector).normalize();

		v3 rightpoint = v3(atoms[0].x + rightvector.x, atoms[0].y + rightvector.y, atoms[0].z + rightvector.z);
		v3 leftpoint = v3(atoms[0].x - rightvector.x, atoms[0].y - rightvector.y, atoms[0].z - rightvector.z);

		double rightlen = v3(rightpoint.x - atoms[2].x, rightpoint.y - atoms[2].y, rightpoint.z - atoms[2].z).length();
		double leftlen = v3(leftpoint.x - atoms[2].x, leftpoint.y - atoms[2].y, leftpoint.z - atoms[2].z).length();

		if(rightlen < leftlen)
		{
			puts("Rectus");
		} else
		{
			puts("Sinister");
		}
	wend:
		int o;
	}

	return 0;
}