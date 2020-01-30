#include<iostream>
using namespace std;
namespace rtti_impl
{
	class GameObject
	{
	public:
		virtual ~GameObject()
		{
		}
	};
	class SpaceShip :public GameObject
	{
	public:

	};

	class SpaceStation :public GameObject
	{
	public:

	};

	class Asteroid :public GameObject
	{
	public:

	};

	void ProcessCollission(GameObject & g1, GameObject & g2)
	{
		//cout << typeid(g1).name() << " and g2=" << typeid(g2).name() << endl;
		if (typeid(g1) == typeid(SpaceShip) && typeid(g2) == typeid(SpaceStation))
		{
			cout << "Ship collides with station\n";
		}
		else if (typeid(g1) == typeid(SpaceShip) && typeid(g2) == typeid(Asteroid))
		{
			cout << "Ship collides with Asteroid\n";
		}
		else if (typeid(g1) == typeid(Asteroid) && typeid(g2) == typeid(SpaceStation))
		{
			cout << "Asteroid collides with station\n";
		}
	}

	//---------------------------
	int main()
	{
		SpaceShip sp;
		SpaceStation st;
		Asteroid ast;

		ProcessCollission(sp, st);
		ProcessCollission(sp, ast);
		ProcessCollission(ast, st);

		return 0;
	}
}