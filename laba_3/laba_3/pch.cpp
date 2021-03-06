#include "pch.h"
#include <iostream>
using namespace std;

void Life::set(int m, int n){
	this->m = m;
	this->n = n;
}

void Life::field(Cage *x) {
	this->x = x;
}


void Plant::reprod() {
	if (hp == 10) {
		hp = 100;
	}
}

void Plant::hungry(int k){
	hp -= 10;
	if (hp < 0) {
		x->pl[k] = 0;
	}
}

void Herb::travel(){
	for (int i = 0; i < 10; i++) {
		if (x->hb[i] != 0 && this->hp >= 60 && this->sex == 0) {
			if (x->hb[i]->sex == 1) {
				if (this->m > x->hb[i]->m) {
					this->m--;
					break;
				}
				if (this->m < x->hb[i]->m) {
					this->m++;
					break;
				}
				if (this->m == x->hb[i]->m) {
					if (this->n > x->hb[i]->n) {
						this->n--;
						break;
					}
					if (this->n < x->hb[i]->n) {
						this->n++;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		if (x->pl[i] != 0 && this->hp < 60) {
			if (this->m > x->pl[i]->m) {
				this->m--;
				break;
			}
			if (this->m < x->pl[i]->m) {
				this->m++;
				break;
			}
			if (this->m == x->pl[i]->m) {
				if (this->n > x->pl[i]->n) {
					this->n--;
					break;
				}
				if (this->n < x->pl[i]->n) {
					this->n++;
					break;
				}
			}
		}
	}
}

void Herb::reprod(int k) {
	int i, j;
	for (i = 0; i < 10; i++)
		if (x->hb[i] != 0 && i != k && this->hp >= 60)
			if (x->hb[i]->m == this->m && x->hb[i]->n == this->n) {
				if (this->sex == 0 && x->hb[i]->sex == 1 && x->hb[i]->hp > 60) {
					for (j = 0; j < 10; j++) {
						if (x->hb[j] == 0) {
							x->hb[j] = new Herb;
							x->hb[j]->sex = j % 2;
							x->hb[j]->set(m, n);
							x->hb[j]->field(x);
							break;
						}
					}
					this->hp -= 30;
					x->hb[i]->hp -= 30;
					if (this->m < 9) this->m++;
					if (x->hb[i]->n < 9) x->hb[i]->n++;
					break;
				}
			}
}

void Herb::eat(){
	for (int i = 0; i < 10; i++)
		if (x->pl[i] != 0 && this->hp != 0)
			if (x->pl[i]->m == this->m && x->pl[i]->n == this->n) {
			x->pl[i] = 0;
			hp = 100;
		}
}

void Herb::hungry(int k){
	hp -= 5;
	if (hp < 0) {
		x->hb[k] = 0;
	}
}


void Pred::travel() {
	for (int i = 0; i < 10; i++)
		if (x->pr[i] != 0 && this->hp >= 60 && this->sex == 0) {
			if (x->pr[i]->sex == 1) {
				if (this->m > x->pr[i]->m) {
					this->m--;
					break;
				}
				if (this->m < x->pr[i]->m) {
					this->m++;
					break;
				}
				if (this->m == x->pr[i]->m) {
					if (this->n > x->pr[i]->n) {
						this->n--;
						break;
					}
					if (this->n < x->pr[i]->n) {
						this->n++;
						break;
					}
				}
			}
		}

	for (int i = 0; i < 10; i++)
		if (x->hb[i] != 0 && this->hp < 60) {
			if (this->m > x->hb[i]->m) {
				this->m--;
				break;
		}
			if (this->m < x->hb[i]->m) {
				this->m++;
				break;
			}
			if (this->m == x->hb[i]->m) {
				if (this->n > x->hb[i]->n) {
					this->n--;
					break;
				}
				if (this->n < x->hb[i]->n) {
					this->n++;
					break;
				}
		}
	}
}

void Pred::reprod(int k){
	int i, j;
	for (i = 0; i < 10; i++)
		if (x->pr[i] != 0 && i != k && this->hp >= 60)
			if (x->pr[i]->m == this->m && x->pr[i]->n == this->n) {
				if (this->sex == 0 && x->pr[i]->sex == 1 && x->pr[i]->hp > 60) {
					for (j = 0; j < 10; j++) {
						if (x->pr[j] == 0) {
							x->pr[j] = new Pred;
							x->pr[j]->sex = j % 2;
							x->pr[j]->set(m, n);
							x->pr[j]->field(x);
							break;
						}
					}
					this->hp -= 30;
					x->pr[i]->hp -= 30;
					if (this->m < 9) this->m++;
					if (x->pr[i]->n < 9) x->pr[i]->n++;
					break;
				}
			}
}

void Pred::eat(){
	for (int i = 0; i < 10; i++)
		if (x->hb[i] != 0 && this->hp != 0)
			if (x->hb[i]->m == this->m && x->hb[i]->n == this->n) {
				x->hb[i] = 0;
				hp = 100;
			}
}

void Pred::hungry(int k){
	hp -= 5;
	if (hp < 0) {
		x->pr[k] = 0;
	}
}

void Cage::set(int ** arr){
	this->arr = arr;
	pl = new Plant*[10];
	hb = new Herb*[10];
	pr = new Pred*[10];
	for (int i = 0; i < 10; i++) {
		pl[i] = 0;
		hb[i] = 0;
		pr[i] = 0;
	}
}

void Cage::objekt(int k){
	switch (k) {
	case 1:
		for (int i = 0; i < 10; i++)
			if (pl[i] == 0) {
				pl[i] = new Plant;
				pl[i]->set(rand()%10, rand()%10);
				pl[i]->field(this);
				break;
			}
		break;
	case 2:
		for (int i = 0; i < 10; i++)
			if (hb[i] == 0) {
				hb[i] = new Herb;
				hb[i]->sex = i % 2;
				hb[i]->set(rand() % 10, rand() % 10);
				hb[i]->field(this);
				break;
			}
		break;
	case 3:
		for (int i = 0; i < 10; i++)
			if (pr[i] == 0) {
				pr[i] = new Pred;
				pr[i]->sex = i % 2;
				pr[i]->set(rand() % 10, rand() % 10);
				pr[i]->field(this);
				break;
			}
		break;
	}
}

void Cage::init() {
	int i, j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			arr[i][j] = 0;
	for (i = 0; i < 10; i++)
		if (pl[i] != 0 && pl[i]->hp != 0)
			arr[pl[i]->m][pl[i]->n] = 1;
	for (i = 0; i < 10; i++)
		if (hb[i] != 0 && hb[i]->hp != 0)
			arr[hb[i]->m][hb[i]->n] = 2;
	for (i = 0; i < 10; i++)
		if (pr[i] != 0 && pr[i]->hp != 0)
			arr[pr[i]->m][pr[i]->n] = 3;
}

int ** Cage::get(){
	return arr;
}

void Cage::WORLD(){
	int i;
	for (i = 0; i < 10; i++)
		if (hb[i] != 0)
			hb[i]->travel();
	for (i = 0; i < 10; i++)
		if (pr[i] != 0)
			pr[i]->travel();

	for (i = 0; i < 10; i++)
		if (hb[i] != 0)
			hb[i]->eat();
	for (i = 0; i < 10; i++)
		if (pr[i] != 0)
			pr[i]->eat();

	for (i = 0; i < 10; i++)
		if (pl[i] != 0)
			pl[i]->reprod();
	for (i = 0; i < 10; i++)
		if (hb[i] != 0)
			hb[i]->reprod(i);
	for (i = 0; i < 10; i++)
		if (pr[i] != 0)
			pr[i]->reprod(i);

	for (i = 0; i < 10; i++)
		if (pl[i] != 0)
			pl[i]->hungry(i);
	for (i = 0; i < 10; i++)
		if (hb[i] != 0)
			hb[i]->hungry(i);
	for (i = 0; i < 10; i++)
		if (pr[i] != 0)
			pr[i]->hungry(i);
}