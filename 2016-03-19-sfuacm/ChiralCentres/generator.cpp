// Chiral Centres generator
// Jonathon Simister

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

const double pi = 3.141592653;

double randangle() {
	double r = (double)rand() / (double)RAND_MAX;

	return r * 2.0 * pi;
}

double randdouble(double min, double max)
{
	double r = (double)rand() / (double)RAND_MAX;

	return (r * (max - min)) + min;
}

class atom {
public:
	atom(int n, double x, double y, double z)
	{
		this->n = n;
		this->x = x;
		this->y = y;
		this->z = z;
	}

	atom rotateX(double theta) const
	{
		return atom(this->n,
			this->x,
			this->y * cos(theta) - this->z * sin(theta),
			this->y * sin(theta) + this->z * cos(theta));
	}

	atom rotateY(double theta) const
	{
		return atom(this->n,
			this->x * cos(theta) + this->z * sin(theta),
			this->y,
			this->z * cos(theta) - this->x * sin(theta));
	}

	atom rotateZ(double theta) const
	{
		return atom(this->n,
			this->x * cos(theta) - this->y * sin(theta),
			this->x * sin(theta) + this->y * cos(theta),
			this->z);
	}

	atom translate(double x, double y, double z) const {
		return atom(this->n, this->x + x, this->y + y, this->z + z);
	}

	int n;
	double x, y, z;
};

int main() {
	vector<int> subs;

	subs.push_back(1); // hydrogen
	subs.push_back(9); // flourine
	subs.push_back(17); // chlorine
	subs.push_back(35); // bromine
	subs.push_back(53); // iodine

	for(int i = 0;i < 998;i++)
	{
		random_shuffle(subs.begin(), subs.end());

		vector<atom> atoms;

		atoms.push_back(atom(6, 0, 0, 0));
		atoms.push_back(atom(subs[0], 1, 0, -0.70710678118));
		atoms.push_back(atom(subs[1], -1, 0, -0.70710678118));
		atoms.push_back(atom(subs[2], 0, 1, 0.70710678118));
		atoms.push_back(atom(subs[3], 0, -1, 0.70710678118));

		if((rand() % 100) == 0) // only put in a few symmetric carbons, since they're less interesting
		{
			atoms[1].n = atoms[2].n;
		}

		double rx = randangle();
		double ry = randangle();
		double rz = randangle();

		for(int x = 0;x < atoms.size();x++)
		{
			atoms[x] = atoms[x].rotateX(rx).rotateY(ry).rotateZ(rz);
		}

		double tx = randdouble(-20, 20);
		double ty = randdouble(-20, 20);
		double tz = randdouble(-20, 20);

		for(int x = 0;x < atoms.size();x++)
		{
			atoms[x] = atoms[x].translate(tx, ty, tz);
		}

		rx = randangle();
		ry = randangle();
		rz = randangle();

		for(int x = 0;x < atoms.size();x++)
		{
			atoms[x] = atoms[x].rotateX(rx).rotateY(ry).rotateZ(rz);
		}

		random_shuffle(atoms.begin(), atoms.end());

		for(int x = 0;x < atoms.size();x++)
		{
			printf("%d %.5lf %.5lf %.5lf\n", atoms[x].n, atoms[x].x, atoms[x].y, atoms[x].z);
		}
	}

	return 0;
}