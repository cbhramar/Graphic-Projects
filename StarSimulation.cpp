/*
 * File: StarSimulation.cpp
 * This program uses the simplecpp graphic library
 * The purpose of the program is to simulate the interaction between many heavenly bodies and give us a rough estimate 
 * of how the bodies would interact with each other where the only force between them is gravitational.
 */

#include <simplecpp>

/*
 * Class  Vector3: 
 * Class to represent 3 dimensional vectors. The operations allowed on the vectors are addition, subtraction, and 
 * multiplication by a scalar. These operations are overloaded such that their intuitive symbols are used.
 */
class  Vector3  {

	private :
		double x, y, z; // the three components of a 3 dimensional vector

	public :
		Vector3() { // Constructor
		}; 
		
		 Vector3(double p, double q, double r) { // Constructor
			x = p; 
			y = q; 
			z = r;
		};

		Vector3 operator+( Vector3 const &w) const { // Vector Addition
			return  Vector3(x + w.x, y + w.y, z + w.z);
		};

		Vector3 operator-( Vector3 const &w) const { // Vector Subtraction
			return  Vector3(x - w.x, y - w.y, z - w.z);
		};

		Vector3 operator*(double t) const { // Multiplication by a scalar
			return  Vector3(x*t, y*t, z*t);
		};

		double length() const { // returns the magnitude of the vector
			return sqrt(x*x + y*y + z*z);
		};

		double getX() { // public function to access x coordinate
			return x;
		}

		double getY() { // public function to access y coordinate
			return y;
		}

		double getZ() { // public function to access z coordinate
			return z;
		}
};

/*
 * Class Star:
 * Class to represent a star (as a circle) on the canvas. Also stores the mass, position, and velocity of the star.
 * The functions include initialization of a star, updating velocity and position after some time interval, and
 * calculating the force exerted by other stars on the current star.
 */
class Star {

	private :
		Circle image; // the star on canvas
		double mass; // mass of the star
		Vector3 r; // position
		Vector3 v; // velocity

	public :
		Star() { // Empty constructor
		};

		void init(double m,  Vector3 position,  Vector3 velocity) { // function to initialize the star; acts as a Constructor
			mass = m;
			r = position;
			v = velocity;
			image.reset(r.getX(), r.getY(), 15); // 15 is the radius of the stars
			image.setColor(COLOR("red"));
			image.setFill(true);
			image.penDown();
		}

		void vStep(double dT,  Vector3 f) { // update velocity after dT time
			v = v + f*(dT/mass);
		}

		void rStep(double dT) { // update position after dT time
			Vector3 d = v*dT;
			image.move(d.getX(), d.getY());
			r = r + d;
		}

		Vector3 forceOf(Star &s) { // force exerted by any other star
			Vector3 R = s.r - r;
			return R*(mass*s.mass/pow(R.length(),3));
		}
};

/*
 * An input function. This function reads data provided by the user and creates star objects with the given parameters
 */
void read_star_data(Star stars[], int n) {
	double mass, vx, vy, vz, x, y, z;
	for(int i = 0; i < n; ++i) {
		cin >> mass >> x >> y >> z >> vx >> vy >> vz;
		stars[i].init(mass, Vector3(x, y, z), Vector3(vx, vy, vz));
	}
}

/*
 * Function to calculate the net force experienced by all stars due to each other
 */
void calculate_net_force(int n, Star stars[],  Vector3 forces[]) {
	for(int i = 0; i < n; ++i) {
		forces[i]= Vector3(0,0,0);
	}
	for(int i = 0; i < n - 1; ++i) {
		for(int j = i + 1; j < n; ++j) {
			Vector3 f = stars[i].forceOf(stars[j]);
			forces[i] = forces[i] + f;
			forces[j] = forces[j] - f;
		}
	}
}

/*
 * simplecpp allows us to use main_program instead of int main()
 */
main_program {

	initCanvas("N body problem", 800, 800); // initialize the canvas

	double T; // total time the user wants the simulation to run 
	double delta; // time interval after which the updates in velocity and position take place
	cin >> T >> delta;

	int n; // number of stars the user wants in the simulation
	cin >> n;
	Star stars[n];

	read_star_data(stars, n); // initialize the stars by providing data

	Vector3 forces[n]; // array to get the total force on each star
	calculate_net_force(n, stars, forces);

	for(int i = 0; i < n; ++i) {
		stars[i].vStep(delta/2, forces[i]);
	}

	for(float t = 0; t < T; t += delta) {
		for(int i = 0; i < n; ++i) {
			stars[i].rStep(delta);
		}
		calculate_net_force(n, stars, forces);
		for(int i = 0; i < n; ++i) {
			stars[i].vStep(delta, forces[i]);
		}
	}

	getClick();
}
