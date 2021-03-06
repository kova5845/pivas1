#ifndef PCH_H
#define PCH_H

class Cage;

class Life {
protected:
	Cage *x;
public:
	int hp = 100, n, m;

	void set(int m, int n);
	void field(Cage *x);
	
};

class Animal : public Life {
private:
	int speed = 1, size = 1;
public:
	int sex;

	virtual void travel() = 0;
	virtual void eat() = 0;
};

class Plant : public Life {
public:
	void reprod();
	void hungry(int k);
};

class Herb : public Animal {
public:
	void travel();
	void reprod(int k);
	void eat();
	void hungry(int k);
};

class Pred : public Animal {
public:
	void travel();
	void reprod(int k);
	void eat();
	void hungry(int k);
};

class Cage{
public:
		int **arr;
		Plant **pl;
		Herb **hb;
		Pred **pr;

		void set(int **arr);
		void objekt(int k);
		void init();
		int** get();
		void WORLD();
};

#endif //PCH_H