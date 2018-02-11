/**
*	@link	https://www.acmicpc.net/problem/13335
*	@date	2017. 09. 20
*	@author	Sikurity
*	@method Just Easy With Queue & List
*/

#include <stdio.h>
#include <list>
#include <queue>

using namespace std;

typedef struct Truck {
	int _id;
	int weight;
	int pos;

	bool operator==(const Truck &t) {

		return this->_id == t._id;
	}
} Truck;

int main()
{
	int n, w, L;

	queue<Truck> trucks;

	scanf("%d %d %d", &n, &w, &L);
	for (int i = 0; i < n; i++) {

		int truckWeight;
		scanf("%d", &truckWeight);

		Truck t = Truck();
		t._id = i;
		t.weight = truckWeight;
		t.pos = 0;
		trucks.push(t);
	}

	list<Truck> bridge;

	int t = 0, totalWeight = 0;


	Truck truck = trucks.front();
	trucks.pop();
	totalWeight += truck.weight;

	bridge.push_back(truck);
	bridge.begin()->pos++;

	t++;
	while (!(trucks.empty() && bridge.empty())) {

		list<Truck>::iterator iter = bridge.begin();
		while (iter != bridge.end())
		{
			iter->pos++;

			if (iter->pos > w) {
				totalWeight -= iter->weight;
				bridge.erase(iter++);
			}
			else
				iter++;
		}

		if (!trucks.empty()) {
			Truck waitingTruck = trucks.front();

			if (waitingTruck.weight + totalWeight <= L) {
				trucks.pop();
				
				waitingTruck.pos++;
				bridge.push_back(waitingTruck);

				totalWeight += waitingTruck.weight;
			}
		}

		t++;
	}

	printf("%d\n", t);

	return 0;
}